#!/usr/bin/python

rules = [r'^('+osnova+')('+nastavak+r')$' for osnova, nastavak in [e.strip().split(' ') for e in open('rules.txt', 'rt') if e[0] != "#"]]

f = open('rules.c', 'wt')
f.write("""
#include <err.h>
#include <pcre.h>

int hrstemc_n_rules = %d;
pcre *hrstemc_rules[%d];
pcre_extra *hrstemc_rules_extra[%d];

void hrstemc_init_rules(void);

void hrstemc_init_rules() {
    const char *error;
    int error_offset;
""" % (len(rules), len(rules), len(rules)) )

for i, r in enumerate(rules):
    f.write("    hrstemc_rules[%d] = pcre_compile(\"%s\", 0, &error, &error_offset, NULL);\n" % (i, r))
    f.write("    if (error != NULL) errx(1, \"%s\", error);\n")
    f.write("    hrstemc_rules_extra[%d] = pcre_study(hrstemc_rules[%d], 0, &error);\n" % (i,i))
    f.write("    if (error != NULL) errx(1, \"%s\", error);\n")

f.write("}\n")
f.close()


