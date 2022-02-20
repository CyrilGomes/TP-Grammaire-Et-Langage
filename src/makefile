OBJS	= main.o lexer.o symbole.o etat.o automate.o
SOURCE	= main.cpp lexer.cpp symbole.cpp etat.cpp automate.cpp
HEADER	= 
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

lexer.o: lexer.cpp
	$(CC) $(FLAGS) lexer.cpp 

symbole.o: symbole.cpp
	$(CC) $(FLAGS) symbole.cpp 

etat.o: etat.cpp
	$(CC) $(FLAGS) etat.cpp 

automate.o: automate.cpp
	$(CC) $(FLAGS) automate.cpp 


clean:
	rm -f $(OBJS) $(OUT)
