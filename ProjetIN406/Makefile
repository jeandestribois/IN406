# Test

test: clean build run

# Execution avec 5 exemple

run:
	./eval 54+  2+  \(  2*45  \) + 5

# Edition de lien

build: eval.o fonctionsListe.o
	gcc -Wall eval.o fonctionsListe.o -o eval -g

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
