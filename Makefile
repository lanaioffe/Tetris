# list of all objects which came from all cpp files
OBJS = main.o Figure.o Stick.o

# main.exe will be created as result
all: main.exe



#instructions howto compile cpp files
.cpp.o:
	g++ -std=c++17 -c $< -o $@

#instructions how to compile main.exe from all objects
main.exe: $(OBJS)
	g++ $(OBJS) -lcurses -o $@

main.cpp: Tetris.h Figure.h
Tetris.o: Tetris.h
Figure.o: Figure.h
Stick.o: Stick.h

clean:
	rm -f *.o main.exe
	