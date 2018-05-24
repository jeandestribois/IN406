# Test

test: build
	./eval "54   +  2  +  (  2  *   45  )"

# Edition de lien

build: eval.o fonctionsListe.o
	gcc -Wall eval.o fonctionsListe.o -o eval

# Compilation

eval.o: eval.c
	gcc -c -Wall eval.c

fonctionsListe.o: fonctionsListe.c
	gcc -c -Wall fonctionsListe.c

# Clean

clean:
	rm -f *.o eval

edit:
	subl Makefile *.c *.h