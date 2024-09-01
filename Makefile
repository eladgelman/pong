CC = clang
CFLAGS = -g -Wall
LDFLAGS = -lraylib -lGL -lm -ldl -lrt -lX11

OBJECTS = main.o 
TARGET = main

.PHONY : all clean

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm $(TARGET) $(OBJECTS) 


