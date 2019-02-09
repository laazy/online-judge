CC = g++
CFLAGS = -g -Wall
TARGET = array_question
TARGET_TEST = $(TARGET)_test

main: main.o $(TARGET).o $(TARGET_TEST).o

main.o: main.h main.cpp
	$(CC) $(CFLAGS) -c $^ 

test.o: test/test.h test/test.cpp
	$(CC) $(CFLAGS) -c $^ 

array_question.o: primary/array_question.h \
 primary/array_question.cpp 
	$(CC) $(CFLAGS) -c $^ 
	
array_question_test.o: primary/array_question_test.cpp
	$(CC) $(CFLAGS) -c $^ 

.PHONY : clean	
clean:
	rm -rf main *.o */*.h.gch *.h.gch