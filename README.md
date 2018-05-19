# Croatian language stemmer in C, and a PostgreSQL dictionary extension

This project is based on the work published at http://nlp.ffzg.hr/resources/tools/stemmer-for-croatian/ .

## Requirements

* pcre, available in Debian/Ubuntu as `libpcre3-dev`

## PostgreSQL stemmer module requirements

* PostgreSQL development libraries, e.g. `postgresql-server-dev-9.5`

See build instructions in the `pgdict_hrstemc` folder.

## Usage example in C

All strings are assumed to be UTF-8.

```C
#include <stdio.h>
#include <string.h>

#include "hrstemc.h"

int main(int argc, char **argv) {
    hrstemc_init();

    printf("koza: %d\n", hrstemc_is_stopword("koza"));
    printf("mora: %d\n", hrstemc_is_stopword("mora"));
    printf("krenuti: %d\n", hrstemc_is_stopword("krenuti"));

    char *s2 = hrstemc_korjenuj("tihim");
    printf("korjenuj: %s\n", s2);
    free(s2);
}
```

The main function is `hrstemc_korjenuj()` defined as:

```C
char* hrstemc_korjenuj(char* lowercase_word);
```

The function always returns a `malloc()`-ed string which needs to be `free()`-d by the caller.

## Usage example for PostgreSQL

See the `README.build` file in the `pgdict_hrstemc` directory for build and usage instructions.

## Endnotes

There are several places in the code which could be optimized for better performance, e.g. searching for stopwords could be done as a binary search on a sorted list, transformation processing could be done with a fancy algorithm, etc. Patches welcome!

Sponsored by IRB.
