test: test.c hrstemc.c rules.c
	gcc -o test test.c hrstemc.c rules.c -lpcre

rules.c: rules.txt comprules.py
	python3 comprules.py > rules.c

