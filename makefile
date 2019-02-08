all:
	gcc -g -Wall -o prog1sorter.c sorter.c
	gcc -g -Wall -o prog1generator.c generator.c
	gcc -g -Wall -o test.c clt.c
sorter: sorter.c 
	gcc -Wall -g -o sorter sorter.c
generator: generator.c 
	gcc -Wall -g -o generator generator.c
clt: clt.c 
	gcc -Wall -g -o clt clt.c
clean:
	-rm generator.o sorter.o clt.o
