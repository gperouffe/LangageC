matproj: matproj.o mat.o op.o es.o err.o
	gcc matproj.o mat.o op.o es.o err.o -o matproj -lm

matproj.o: matproj.c mat.h es.h op.h
	gcc -c matproj.c

mat.o: mat.c mat.h
	gcc -c mat.c

op.o: op.c op.h err.h es.h mat.h
	gcc -c op.c

es.o: es.c es.h mat.h err.h
	gcc -c es.c

err.o: err.c err.h
	gcc -c err.c
