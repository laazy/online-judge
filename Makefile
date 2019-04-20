CC = g++
CFLAGS = -g -Wall
LFLAGS = -lpthread
PROJECT_PATH = intermediate
TARGET = list_question
TARGET_TEST = $(TARGET)_test

main: main.o $(TARGET).o $(TARGET_TEST).o util.o $(LFLAGS)

main.o: main.h main.cpp
	$(CC) $(CFLAGS) -c $^ 

util.o: util.h util.cpp
	$(CC) $(CFLAGS) -c $^ 

$(TARGET).o: $(PROJECT_PATH)/$(TARGET).h $(PROJECT_PATH)/$(TARGET).cpp
	$(CC) $(CFLAGS) -c $^

$(TARGET_TEST).o: $(PROJECT_PATH)/$(TARGET_TEST).cpp
	$(CC) $(CFLAGS) -c $^


.PHONY : create
create:
	./create.sh $(PROJECT_PATH) $(TARGET) $(TARGET_TEST)
	code $(PROJECT_PATH)/$(TARGET).h \
		 $(PROJECT_PATH)/$(TARGET).cpp\
		 $(PROJECT_PATH)/$(TARGET_TEST).cpp

.PHONY : clean	
clean:
	rm -rf main *.o */*.h.gch *.h.gch