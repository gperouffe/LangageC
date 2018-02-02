matproj: matproj.o mat.o op.o es.o err.o
	gcc matproj.o mat.o op.o es.o err.o -o matproj

matproj.o: matproj.c mat.h es.h op.h
	gcc -c matproj.c

mat.o: mat.c mat.h
<<<<<<< HEAD
	cc -c mat.c
=======
	gcc -c mat.c
>>>>>>> f76a3ae14a0c61d8e9317c476e919b257bcf435c

op.o: op.c op.h err.h es.h mat.h
	gcc -c op.c

es.o: es.c es.h mat.h err.h
	gcc -c es.c

err.o: err.c err.h
	gcc -c err.c
