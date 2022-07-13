#include <curses.h>
#include <cassert>
#include "Figure_Z.h"


int Figure_Z::getFigureHeight() 
{
    switch (state)
    {
    case 0:
    case 2:
        return 2;
    
    case 1:
    case 3:
        return 3;
    
    default:
        assert(0);
    }
}

int Figure_Z::getFigureWidth() 
{ 
    switch (state)
    {    
    case 0:
    case 2:
        return 6;
    
    case 1:
    case 3:
        return 4;
    
    default:
        assert(0);
    }
}

/*
void Figure_Z::draw()
{
    wattron(tetris->getWindow(), COLOR_PAIR(color));   
    switch (state)
    {
    case 0:
    case 2:
        for (int i=0; i<6; i++) 
        {   
            if (i < 4) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }
            if (i > 1) {mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD);}
        }
        break;
   
    case 1:
    case 3:
        for (int i=0; i<4; i++)
        {
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
            if (i > 1) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }
            if (i < 2) {mvwaddch(tetris->getWindow(), y+2, x+i, ACS_CKBOARD); }
        }
        break;
    
    default:
        assert(0);
    }
    wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
}

void Figure_Z::clear()
{
    switch (state)
    {
    case 0:
    case 2:
        for (int i=0; i<6; i++) 
        {   
            if (i < 4) {mvwaddch(tetris->getWindow(), y, x+i, ' '); }
            if (i > 1) {mvwaddch(tetris->getWindow(), y+1, x+i, ' ');}
        }
        break;
   
    case 1:
    case 3:
        for (int i=0; i<4; i++)
        {
            mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
            if (i > 1) {mvwaddch(tetris->getWindow(), y, x+i, ' '); }
            if (i < 2) {mvwaddch(tetris->getWindow(), y+2, x+i, ' '); }
        }
        break;
    
    default:
        assert(0);
    }
}
*/

