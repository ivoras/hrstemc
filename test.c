#include <stdio.h>

#include "hrstemc.h"

int main(int argc, char **argv) {
    hrstemc_init_rules();

    printf("koza: %d\n", is_stopword("koza"));
    printf("mora: %d\n", is_stopword("mora"));
    printf("krenuti: %d\n", is_stopword("krenuti"));
}