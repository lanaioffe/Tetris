#include <curses.h>
#include "Stick.h"


int Stick::getFigureHeight() {return StickHeight;}

int Stick::getFigureWidth() {return StickWidth;}

void Stick::draw()
{
    for (int i=0; i<4; i++) {     
        wattron(tetris->getWindow(), COLOR_PAIR(color));     
		mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
		mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
        wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
	}
}

void Stick::clear()
{
    for (int i=0; i<4; i++) {             
        mvwaddch(tetris->getWindow(), y+i, x, ' '); 
        mvwaddch(tetris->getWindow(), y+i, x+1, ' ');
	}
}

void Stick::down(){
    if (y + getFigureHeight() < 49){
        clear();
        y++;
        draw();
    }
}

void Stick::rotate(){}
