#include "postgres.h"
#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

#include "commands/defrem.h"
#include "tsearch/dicts/spell.h"
#include "tsearch/ts_locale.h"
#include "tsearch/ts_public.h"
#include "tsearch/ts_utils.h"
#include "utils/builtins.h"
#include "utils/memutils.h"
#include "utils/formatting.h"

#if PG_VERSION_NUM >= 90100
#include "catalog/pg_collation.h"
#endif

#define MAIN
#include "hrstemc.h"

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

PG_FUNCTION_INFO_V1(dhrstemc_init);
Datum		dhrstemc_init(PG_FUNCTION_ARGS);
PG_FUNCTION_INFO_V1(dhrstemc_lexize);
Datum		dhrstemc_lexize(PG_FUNCTION_ARGS);

struct hrstemc_sc {
	unsigned int	sufx_counter;
	unsigned int	sw_counter;
};

Datum
dhrstemc_init(PG_FUNCTION_ARGS)
{
	struct hrstemc_sc *sc = calloc(1, sizeof(*sc));
	List           *dictoptions = (List *) PG_GETARG_POINTER(0);
	ListCell       *l;

	foreach(l, dictoptions) {
		DefElem        *defel = (DefElem *) lfirst(l);
		/* No implemented options so far */
		elog(ERROR, "Unknown option: %s => %s", defel->defname, defGetString(defel));
	}

	MemoryContextDeleteChildren(CurrentMemoryContext);

	PG_RETURN_POINTER(sc);
}

static TSLexeme *
make_lexeme_from_word(char *word)
{
	TSLexeme       *res = palloc0(sizeof(TSLexeme) * 2);

	res[0].lexeme = word ? pstrdup(word) : NULL;
	return res;
}


static int
is_stopword(char *word)
{
	return hrstemc_is_stopword(word);
}


/*
 * Input: word to stem
 * Output: palloced null terminated string with stem
 */
static char *
process_sufx(char *word)
{
	int i, wl;
	char *res, *stemmed;

	wl = strlen(word);
#if PG_VERSION_NUM >= 90100
	word = str_tolower(word, wl, DEFAULT_COLLATION_OID);
#else
	word = str_tolower(word, wl);
#endif

	stemmed = hrstemc_korjenuj(word);
	res = pstrdup(word);
	free(stemmed);
	return res;
}


Datum
dhrstemc_lexize(PG_FUNCTION_ARGS)
{
	struct hrstemc_sc *sc = (struct hrstemc_sc *) PG_GETARG_POINTER(0);
	char           *in = (char *)PG_GETARG_POINTER(1);
	int32		len = PG_GETARG_INT32(2);
	char           *txt = lowerstr_with_len(in, len);
	DictSubState   *dstate = (DictSubState *) PG_GETARG_POINTER(3);
	char           *lex;
	TSLexeme       *res;

	if (is_stopword(txt)) {
		sc->sw_counter++;
		pfree(txt);
		/*elog(NOTICE, "Stopword: %s", txt);*/
		PG_RETURN_POINTER(make_lexeme_from_word(NULL));
	}

	if (!txt || !strlen(txt))
		elog(ERROR, "Empty word passed!");
	dstate->getnext = false;

	lex = process_sufx(txt);
	pfree(txt);
	if (!lex || !strlen(lex))
		PG_RETURN_POINTER(make_lexeme_from_word(NULL));
	res = make_lexeme_from_word(lex);
	pfree(lex);

	sc->sufx_counter++;
	PG_RETURN_POINTER(res);
}
