CC = g++
CFLAGS = -g -Wall
TARGET = string_question
TARGET_TEST = $(TARGET)_test

main: main.o $(TARGET).o $(TARGET_TEST).o util.o

main.o: main.h main.cpp
	$(CC) $(CFLAGS) -c $^ 

test.o: test/test.h test/test.cpp
	$(CC) $(CFLAGS) -c $^ 

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c $^ 

array_question.o: primary/array_question.h \
 primary/array_question.cpp 
	$(CC) $(CFLAGS) -c $^ 
	
array_question_test.o: primary/array_question_test.cpp 
	$(CC) $(CFLAGS) -c $^ 

string_question.o: primary/string_question.h \
 primary/string_question.cpp 
	$(CC) $(CFLAGS) -c $^ 
	
string_question_test.o: primary/string_question_test.cpp 
	$(CC) $(CFLAGS) -c $^ 


.PHONY : clean	
clean:
	rm -rf main *.o */*.h.gch *.h.gch