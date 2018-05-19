test: test.c hrstemc.c hrstemc.h rules.c transformations.c
	gcc -o test -g test.c hrstemc.c rules.c transformations.c -lpcre

rules.c: rules.txt comprules.py
	python3 comprules.py 

transformations.c: transformations.txt comptransformations.py
	python3 comptransformations.py

