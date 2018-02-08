#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcre.h>

char *stopwords[] = {
    "biti","jesam","budem","sam","jesi","budeš","si","jesmo","budemo","smo","jeste","budete","ste","jesu","budu","su","bih","bijah","bjeh","bijaše","bi","bje","bješe","bijasmo",
    "bismo","bjesmo","bijaste","biste","bjeste","bijahu","biste","bjeste","bijahu","bi","biše","bjehu","bješe","bio","bili","budimo","budite","bila","bilo","bile","ću","ćeš","će",
    "ćemo","ćete","želim","želiš","želi","želimo","želite","žele","moram","moraš","mora","moramo","morate","moraju","trebam","trebaš","treba","trebamo","trebate","trebaju","mogu",
    "možeš","može","možemo","možete",
    NULL
};

int is_stopword(char *w) {
    for (char **sw = stopwords; *sw != NULL; sw++) {
        if (strcmp(w, *sw) == 0) {
            return 1;
        }
    }
    return 0;
}

