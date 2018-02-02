matproj: matproj.o mat.o op.o es.o err.o
	cc matproj.o mat.o op.o es.o err.o -o matproj

matproj.o: matproj.c mat.h es.h op.h
	cc -c matproj.c


mat.o: mat.c mat.h.h
	cc -c mat.c

op.o: op.c op.h err.h es.h mat.h
		cc -c op.c

es.o: es.c es.h mat.h err.h
		cc -c es.c

err.o: err.c err.h
		cc -c err.c
