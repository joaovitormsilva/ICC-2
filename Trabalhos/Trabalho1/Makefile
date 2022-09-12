UTIL=Trab1SelectionBolha.c 
MAIN=main.c
BINARY=main

all:
    gcc -Wall -Wextra -Werror -g $(MAIN) $(UTIL) -o $(BINARY) -lm
    
run:
    ./$(BINARY)

debug:
    gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)
    
valgrind:
    valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)
    
clean:
    @rm *.o

zip:
    @zip -r ex1.zip *