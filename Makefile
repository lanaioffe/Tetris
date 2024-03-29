# list of all objects which came from all cpp files
OBJS = main.o Figure.o Figure_I.o Figure_O.o Figure_T.o Figure_S.o Figure_Z.o Figure_J.o Figure_L.o

# main.exe will be created as result
all: main.exe



#instructions howto compile cpp files
.cpp.o:
	g++ -std=c++17 -c $< -o $@

#instructions how to compile main.exe from all objects
main.exe: $(OBJS)
	g++ $(OBJS) -lcurses -o $@

main.o: Tetris.h Figure.h Figure_I.h Figure_O.h Figure_T.h Figure_S.h Figure_Z.h Figure_J.h Figure_L.h
Tetris.o: Tetris.h Figure.h
Figure.o: Figure.h Tetris.h
Figure_I.o: Figure_I.h  Figure.h
Figure_O.o: Figure_O.h  Figure.h
Figure_T.o: Figure_T.h  Figure.h
Figure_S.o: Figure_S.h  Figure.h
Figure_Z.o: Figure_Z.h  Figure.h
Figure_J.o: Figure_J.h  Figure.h
Figure_L.o: Figure_L.h  Figure.h


clean:
	rm -f *.o main.exe
	