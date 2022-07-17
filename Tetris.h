#ifndef TETRIS_H
#define TETRIS_H

#include <ncurses.h>
#include <cstdint>

using namespace std;


class Tetris 
{
	protected:
		WINDOW *w;
		static constexpr int winWidth = 42;
		static constexpr int winHeight = 42;
		
	public:
		uint64_t glass [winHeight+3];
		
		Tetris() 
		{	

			for(int i=0; i<winHeight; i++) glass[i] = ~((uint64_t(1) << winWidth)-1) + 1;		//set all outside to 1	
			for(int i=winHeight-1; i<winHeight+3; i++) glass[i] = uint64_t(-1);					//all below winHeight-1 set to 1 - bottom border

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