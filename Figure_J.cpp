#include <curses.h>
#include <cassert>
#include "Figure_J.h"


int Figure_J::getFigureHeight() 
{
    switch (state)
    {
    case 0:
    case 2:
        return 3;
    
    case 1:
    case 3:
        return 2;
    
    default:
        assert(0);
    }
}

int Figure_J::getFigureWidth() 
{ 
    switch (state)
    {    
    case 0:
    case 2:
        return 4;
    
    case 1:
    case 3:
        return 6;
    
    default:
        assert(0);
    }
}

/*
void Figure_J::draw()
{
    wattron(tetris->getWindow(), COLOR_PAIR(color));   
    switch (state)
    {
    case 0:
        for (int i=0; i<4; i++) 
        {   
            if (i > 1)            
            {
                mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
                mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
            }
            mvwaddch(tetris->getWindow(), y+2, x+i, ACS_CKBOARD);
        }
        break;

    case 1:
        for (int i=0; i<6; i++) 
        {   
            if (i < 2) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }   
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD);       
        }
        break;
   
    case 2:
        for (int i=0; i<4; i++) 
        {   
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD);
            if (i < 2)            
            {
                mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
                mvwaddch(tetris->getWindow(), y+2, x+i, ACS_CKBOARD); 
            }
        }
        break;

    case 3:
        for (int i=0; i<6; i++) 
        {    
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD);       
            if (i > 3) {mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); }  
        }
        break;
    
    default:
        assert(0);
    }
    wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
}

void Figure_J::clear()
{
    switch (state)
    {
    case 0:
        for (int i=0; i<4; i++) 
        {   
            if (i > 1)            
            {
                mvwaddch(tetris->getWindow(), y, x+i, ' '); 
                mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
            }
            mvwaddch(tetris->getWindow(), y+2, x+i, ' ');
        }
        break;

    case 1:
        for (int i=0; i<6; i++) 
        {   
            if (i < 2) {mvwaddch(tetris->getWindow(), y, x+i, ' '); }   
            mvwaddch(tetris->getWindow(), y+1, x+i, ' ');       
        }
        break;
   
    case 2:
        for (int i=0; i<4; i++) 
        {   
            mvwaddch(tetris->getWindow(), y, x+i, ' ');
            if (i < 2)            
            {
                mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
                mvwaddch(tetris->getWindow(), y+2, x+i, ' '); 
            }
        }
        break;

    case 3:
        for (int i=0; i<6; i++) 
        {   
            mvwaddch(tetris->getWindow(), y, x+i, ' ');       
            if (i > 3) {mvwaddch(tetris->getWindow(), y+1, x+i, ' '); }       
        }
        break;
    
    default:
        assert(0);
    }
}
*/

