#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>
#include "hrstemc.h"

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

int hrstemc_istakni_slogotvorno_r(char *s) {
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