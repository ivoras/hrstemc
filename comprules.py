
rules = [r'^('+osnova+')('+nastavak+r')$' for osnova, nastavak in [e.strip().split(' ') for e in open('rules.txt', 'rt')]]

print("""
#include <err.h>
#include <pcre.h>

static pcre *rules[%d];

void hrstemc_init_rules() {
    const char *error;
    int error_offset;
    """ % len(rules) )

for i, r in enumerate(rules):
    print("    rules[%d] = pcre_compile(\"%s\", 0, &error, &error_offset, NULL);" % (i, r))
    print("    if (error != NULL) errx(1, \"%s\", error);")

print("""}""")
