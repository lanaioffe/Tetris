#include <curses.h>
#include "Figure.h"

void Stick::draw()
{
    for (int i=0; i<4; i++) {     
        wattron(win, COLOR_PAIR(color));     
		mvwaddch(win, y+i, x, ACS_CKBOARD); 
		mvwaddch(win, y+i, x+1, ACS_CKBOARD);
        wattroff(win, COLOR_PAIR(color)); 
	}
}

void Stick::clear()
{
    for (int i=0; i<4; i++) {             
        mvwaddch(win, y+i, x, ' '); 
        mvwaddch(win, y+i, x+1, ' ');
	}
}

void Stick::down(){
    if (y + h < 49){
        clear();
        y++;
        draw();
    }
   

}

void Stick::rotate(){}

