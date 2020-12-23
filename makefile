all: processor.c controller.c
	gcc -o processor.o processor.c
	gcc -o controller.o controller.c

run:
	./processor.o & ./controller.o

clean:
	rm *.o
