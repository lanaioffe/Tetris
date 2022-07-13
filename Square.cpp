#include <curses.h>
#include <cassert>
#include "Square.h"


int Square::getFigureHeight() 
{
    switch (state)
    {    
    case 0:
    case 1:
    case 2:
    case 3:
        return 2;
    
    default:
        assert(0);
    }
}

int Square::getFigureWidth() 
{ 
    switch (state)
    {    
    case 0:
    case 1:
    case 2:
    case 3:
        return 4;
    
    default:
        assert(0);
    }
}

void Square::draw()
{
    switch (state)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        for (int i=0; i<4; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD);
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    
    default:
        assert(0);
    }
}

void Square::clear()
{
    switch (state)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        for (int i=0; i<4; i++) 
        {        
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
            mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
        }
        break;
   
    default:
        assert(0);
    }
}


