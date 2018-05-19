#!/usr/bin/python

transformations = [ l.strip().split("\t") for l in open('transformations.txt') if l.strip() != "" ]

f = open('transformations.c', 'wt')
f.write("""
#include <err.h>

int hrstemc_n_transformations = %d;
char *hrstemc_transformations[%d][2] = {
""" % (len(transformations), len(transformations)))

for i, t in enumerate(transformations):
    f.write("""    { "%s", "%s" }""" % tuple(t))
    if i < len(transformations)-1:
        f.write(",")
    f.write("\n")

f.write("};\n")

f.close()


