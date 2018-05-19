#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>
#include "hrstemc.h"

extern int hrstemc_n_transformations;
extern char* hrstemc_transformations[][2];

extern int hrstemc_n_rules;
extern pcre *hrstemc_rules[];
extern pcre_extra *hrstemc_rules_extra[];

static char *stopwords[] = {
    "biti","jesam","budem","sam","jesi","budeš","si","jesmo","budemo","smo","jeste","budete","ste","jesu","budu","su","bih","bijah","bjeh","bijaše","bi","bje","bješe","bijasmo",
    "bismo","bjesmo","bijaste","biste","bjeste","bijahu","biste","bjeste","bijahu","bi","biše","bjehu","bješe","bio","bili","budimo","budite","bila","bilo","bile","ću","ćeš","će",
    "ćemo","ćete","želim","želiš","želi","želimo","želite","žele","moram","moraš","mora","moramo","morate","moraju","trebam","trebaš","treba","trebamo","trebate","trebaju","mogu",
    "možeš","može","možemo","možete",
    NULL
};

static pcre *re_slogotvorno_r;
static pcre_extra *ree_slogotvorno_r;

void hrstemc_init() {
    const char *error;
    int error_offset;

    hrstemc_init_rules();

    re_slogotvorno_r = pcre_compile("(^|[^aeiou])r($|[^aeiou])", 0, &error, &error_offset, NULL);
    if (error != NULL) errx(1, "%s", error);
    ree_slogotvorno_r = pcre_study(re_slogotvorno_r, 0, &error);
    if (error != NULL) errx(1, "%s", error);
}

int hrstemc_is_stopword(char *w) {
    for (char **sw = stopwords; *sw != NULL; sw++) {
        if (strcmp(w, *sw) == 0) {
            return 1;
        }
    }
    return 0;
}

void hrstemc_istakni_slogotvorno_r(char *s) {
    int i;
    int len = strlen(s);

    for (i = 0; i < len; i++) {
        if (s[i] == 'r') {
            if (i == 0 ||
                (s[i-1] != 'a' && s[i-1] != 'e' && s[i-1] != 'i' && s[i-1] != 'o' && s[i-1] != 'u') ||
                i == len-1 ||
                (s[i+1] != 'a' && s[i+1] != 'e' && s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u')
                ) {
                    s[i] = 'R';
                }
        }
    }
}

int hrstemc_ima_samoglasnik(char *s) {
    char *sdup = strdup(s);
    int len = strlen(sdup);
    int i;

    hrstemc_istakni_slogotvorno_r(sdup);
    for (i = 0; i < len; i++) {
        if (sdup[i] == 'a' || sdup[i] == 'e' || sdup[i] == 'i' || sdup[i] == 'o' || sdup[i] == 'u' || sdup[i] == 'R') {
            free(sdup);
            return 1;
        }
    }

    free(sdup);
    return 0;
}

int hrstemc_endswith(char *s, char *what) {
    if (strlen(what) > strlen(s)) {
        return 0;
    }
    if (strcmp(s+strlen(s)-strlen(what), what) == 0) {
        return 1;
    }
    return 0;
}

void hrstemc_transformiraj(char **s) {
    int i;

    for (i = 0; i < hrstemc_n_transformations; i++) {
        if (hrstemc_endswith(*s, hrstemc_transformations[i][0])) {
            *s = realloc(*s, strlen(*s) + strlen(hrstemc_transformations[i][1]));
            if (*s == NULL) errx(1, "Out of memory");
            strcpy( (*s) + (strlen(*s) - strlen(hrstemc_transformations[i][0])), hrstemc_transformations[i][1]);
            return;
        }
    }
}