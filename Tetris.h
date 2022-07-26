#ifndef TETRIS_H
#define TETRIS_H

#include <ncurses.h>
#include <cstdint>

#include "Figure.h"

using namespace std;

class Tetris
{
private:
	WINDOW *w;
	WINDOW *status;
	static constexpr int winWidth = 22;
	static constexpr int winHeight = 22;
	uint64_t glass[winHeight + 3];
	int score = 0;

public:
	Tetris()
	{

		reset();

		w = newwin(winHeight, winWidth, 0, 0);
		wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
		// wborder(w, '|', '|', '-', '-', '1', '2', '3', '4');
		//  wborder(window, left vertical, right vertical, top horizontal, bottom horizontal,
		//  top left corner, top right corner, bottom left corner, bottom right corner);

		status = newwin(winHeight/2, 20, 0, winWidth+3);
		wborder(status, 0, 0, 0, 0, 0, 0, 0, 0);
	}

	~Tetris()
	{
		delwin(w);
		delwin(status);
	};

	void reset()
	{
		for (int i = 0; i < winHeight; i++)
			glass[i] = ~((uint64_t(1) << (winWidth-1)) - 1) + 1; 		// set all outside to 1
		for (int i = winHeight - 1; i < winHeight + 3; i++)
			glass[i] = uint64_t(-1); 									// all below winHeight-1 set to 1 - bottom border

		score = 0;
	}


	void endGame()
	{
		mvwprintw(status,3,3,"GAME OVER");
		refresh();
		while(true)
		{
			int ch = wgetch(getWindow());         // return pushed btn
			if (ch == KEY_ENTER) break; 
		}
		reset();
		refreshGlass();
		mvwprintw(status,3,3,"         ");
		printScore();
		refresh();
	}

	void printScore() {
		mvwprintw(status,1,1,"score: %d   ", score);
	}


	void refresh() { 
		wrefresh(w); wrefresh(status); 
	}

	WINDOW *getWindow() { return w; }

	int getWinWidth() const { return winWidth; }

	int getWinHeight() const { return winHeight; }

	// for comparing row by row on coordinates of window with masks
	// if at least one of them return true - there is a collision
	bool canMove(const Figure *figure, int new_x, int new_y, int moveState)
	{
		// //create masks from figure magic number by state and row
		// //using shift for deleting extra 0 from the begining
		// //for comparing row by row on coordinates of window
		// uint64_t row_mask0 = magicNumber[moveState] & 0x000000FF;                   // 00000000 00000000 00000000 11111111
		// uint64_t row_mask1 = (magicNumber[moveState] & 0x0000FF00) >> 8;            // 00000000 00000000 11111111 00000000
		// uint64_t row_mask2 = (magicNumber[moveState] & 0x00FF0000) >> 16;           // 00000000 11111111 00000000 00000000
		// uint64_t row_mask3 = (magicNumber[moveState] & 0xFF000000) >> 24;           // 11111111 00000000 00000000 00000000

		// compare rows from window with masks (accordingly row by row)
		// if at least one of them return true - there is a collision
		//  if ((tetris->glass[new_y] & (getMaskForRow(0, moveState) << new_x )) |
		//       (tetris->glass[new_y+1] & (getMaskForRow(1, moveState) << new_x)) |
		//        (tetris->glass[new_y+2] & (getMaskForRow(2, moveState) << new_x)) |
		//         (tetris->glass[new_y+3] & (getMaskForRow(3, moveState) << new_x)) )
		//  {
		//      return false;
		//  }
		//  return true;

		for (int i = 0; i < 4; i++)
		{
			if (glass[new_y + i] & (figure->getMaskForRow(i, moveState) << new_x))
			{
				return false;
			}
		}
		return true;
	}

	// change window with masks of figure
	void putFigure(Figure *figure)
	{	
		// uint64_t row_mask0 = magicNumber[state] & 0x000000FF;                   // 00000000 00000000 00000000 11111111
		// uint64_t row_mask1 = (magicNumber[state] & 0x0000FF00) >> 8;            // 00000000 00000000 11111111 00000000
		// uint64_t row_mask2 = (magicNumber[state] & 0x00FF0000) >> 16;           // 00000000 11111111 00000000 00000000
		// uint64_t row_mask3 = (magicNumber[state] & 0xFF000000) >> 24;           // 11111111 00000000 00000000 00000000

		// glass[y] = (glass[y] | (getMaskForRow(0, state) << x ));
		// glass[y+1] = (glass[y+1] | (getMaskForRow(1, state) << x));
		// glass[y+2] = (glass[y+2] | (getMaskForRow(2, state) << x));
		// glass[y+3] = (glass[y+3] | (getMaskForRow(3, state) << x));

		for (int i = 0; i < 4; i++)
		{
			glass[figure->getY() + i] = (glass[figure->getY() + i] | (figure->getMaskForRow(i, figure->getState()) << figure->getX()));
		}
		figure->setColor(WHITE);
		figure->drawB();
		score++;

		printScore();

		collapse();
	}

	void collapse()
	{
		bool redo;

	  while(1) {
		redo= false;
 		for (int i=winHeight-2; i>0; i--)
		{
			if(glass[i] == uint64_t(-1))
			{
				for(int j=i; j>0; j--)
				{
					glass[j] = glass[j-1];
				}
				score += 10;
				printScore();
				refreshGlass();

				redo = true;
			}
		}

		if(redo == false) break;
	  }
	}

	void refreshGlass()
	{
		for(int i=winHeight-2; i>0; i--)
		{
			uint64_t mask = 0x0000000000000001ULL << 1;
			for(int j=1; j<winWidth-1; j++)
			{

				if (glass[i] & mask)
				{
					mvwaddch(getWindow(), i, j, ACS_CKBOARD);
				}
				else {
					mvwaddch(getWindow(), i, j, ' ');
				}
				
				mask <<= 1;
			}
		}
	}
};
#endif