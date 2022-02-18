OBJS	= lexer.o main.o symbole.o
SOURCE	= lexer.cpp main.cpp symbole.cpp
HEADER	= lexer.h symbole.h
OUT	= exec
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

lexer.o: lexer.cpp
	$(CC) $(FLAGS) lexer.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

symbole.o: symbole.cpp
	$(CC) $(FLAGS) symbole.cpp 


clean:
	rm -f $(OBJS) $(OUT)