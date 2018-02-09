matproj: vec.o es.o mat.o solveur.o op.o err.o matproj.o
	gcc  matproj.o solveur.o mat.o vec.o op.o es.o err.o -o matproj -lm

matproj.o: matproj.c vec.h mat.h es.h op.h
	gcc -c matproj.c

vec.o: vec.c vec.h
	gcc -c vec.c

mat.o: mat.c mat.h es.h
	gcc -c mat.c

solveur.o: solveur.c solveur.h
	gcc -c solveur.c -lm

op.o: op.c op.h err.h es.h mat.h vec.h
	gcc -c op.c

es.o: es.c es.h vec.h mat.h err.h
	gcc -c es.c

err.o: err.c err.h
	gcc -c err.c
