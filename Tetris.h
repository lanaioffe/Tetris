#ifndef TETRIS_H
#define TETRIS_H

#include <ncurses.h>

using namespace std;


class Tetris 
{
	protected:
		WINDOW *w;
		const int winWidth = 50;
		const int winHeight = 50;

	public:
		Tetris() 
		{
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