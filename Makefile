CC = g++
CFLAGS = -g -Wall
PROJECT_PATH = primary
TARGET = math_question
TARGET_TEST = $(TARGET)_test

main: main.o $(TARGET).o $(TARGET_TEST).o util.o

main.o: main.h main.cpp
	$(CC) $(CFLAGS) -c $^ 

$(TARGET).o: $(PROJECT_PATH)/$(TARGET).h $(PROJECT_PATH)/$(TARGET).cpp
	$(CC) $(CFLAGS) -c $^

$(TARGET_TEST).o: $(PROJECT_PATH)/$(TARGET_TEST).cpp
	$(CC) $(CFLAGS) -c $^

.PHONY : clean	
clean:
	rm -rf main *.o */*.h.gch *.h.gch