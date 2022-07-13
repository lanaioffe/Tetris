# list of all objects which came from all cpp files
OBJS = main.o Figure.o Figure_I.o Figure_O.o Figure_T.o

# main.exe will be created as result
all: main.exe



#instructions howto compile cpp files
.cpp.o:
	g++ -std=c++17 -c $< -o $@

#instructions how to compile main.exe from all objects
main.exe: $(OBJS)
	g++ $(OBJS) -lcurses -o $@

main.o: Tetris.h Figure.h Figure_I.h Figure_O.h Figure_T.h
Tetris.o: Tetris.h
Figure.o: Figure.h
Figure_I.o: Figure_I.h
Figure_O.o: Figure_O.h
Figure_T.o: Figure_T.h

clean:
	rm -f *.o main.exe
	