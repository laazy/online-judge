CC = gcc
CFLAGS = -g -Wall

main: main.o test.o

main.o: main.h main.c
	$(CC) $(CFLAGS) -c $^ 

test.o: test/test.h test/test.c
	$(CC) $(CFLAGS) -c $^ 
clean:
	rm -rf main *.o */*.h.gch *.h.gch