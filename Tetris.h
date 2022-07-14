#ifndef TETRIS_H
#define TETRIS_H

#include <ncurses.h>
#include <cstdint>

using namespace std;


class Tetris 
{
	protected:
		WINDOW *w;
		const int winWidth = 42;
		const int winHeight = 42;
		
	public:
		uint64_t glass [45];
		
		Tetris() 
		{	
			for(int i=0; i<winWidth+3; i++) glass[i] = 0;
			for(int i=winHeight-1; i<winHeight+3; i++) glass[i] = uint64_t(-1);
			w = newwin(winWidth, winHeight, 0, 0);
        	wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
			//wborder(w, '|', '|', '-', '-', '1', '2', '3', '4');
			// wborder(window, left vertical, right vertical, top horizontal, bottom horizontal, 
			// top left corner, top right corner, bottom left corner, bottom right corner);
		}

		~Tetris() 
		{
			delwin(w); 
		};


		void refresh() { wrefresh(w); }

		WINDOW *getWindow() { return w; }

		int getWinWidth () const { return winWidth;}

		int getWinHeight () const { return winHeight;}

};
#endif