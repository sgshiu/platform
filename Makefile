OBJ = main.o 
FLAG = -Wall -g 
LIB = -lpthread
INCLUDE = -I./

.phony: all clean rebuild

all: $(OBJ)
	$(CXX) $(OBJ) $(FLAG) $(LIB)

%.o: %.c
	$(CC) -c $< $(INCLUDE) $(FLAG)

clean: 
	rm -f *.o
	rm -f *.out

rebuild:
	$(MAKE) clean
	$(MAKE) all
