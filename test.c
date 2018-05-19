#include <stdio.h>
#include <string.h>

#include "hrstemc.h"

int main(int argc, char **argv) {
    hrstemc_init();

    printf("koza: %d\n", hrstemc_is_stopword("koza"));
    printf("mora: %d\n", hrstemc_is_stopword("mora"));
    printf("krenuti: %d\n", hrstemc_is_stopword("krenuti"));

    char *s = strdup("drvo");
    hrstemc_istakni_slogotvorno_r(s);
    printf("r: %s\n", s);

}