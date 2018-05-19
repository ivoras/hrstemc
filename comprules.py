#!/usr/bin/python

rules = [r'^('+osnova+')('+nastavak+r')$' for osnova, nastavak in [e.strip().split(' ') for e in open('rules.txt', 'rt')]]

f = open('rules.c', 'wt')
f.write("""
#include <err.h>
#include <pcre.h>

static pcre *rules[%d];

void hrstemc_init_rules() {
    const char *error;
    int error_offset;
    """ % len(rules) )

for i, r in enumerate(rules):
    f.write("    rules[%d] = pcre_compile(\"%s\", 0, &error, &error_offset, NULL);\n" % (i, r))
    f.write("    if (error != NULL) errx(1, \"%s\", error);\n")

f.write("}\n")
f.close()


