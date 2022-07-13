#include <curses.h>
#include <cassert>
#include "Figure_T.h"


int Figure_T::getFigureHeight() 
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

int Figure_T::getFigureWidth() 
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
void Figure_T::draw()
{
    wattron(tetris->getWindow(), COLOR_PAIR(color)); 
    switch (state){
    
    case 0:
        for (int i=0; i<6; i++) 
        {     
            if (i == 2 || i == 3) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
        }
        break;
    case 1:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD);
            mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);   
            if (i == 1) 
            {
                mvwaddch(tetris->getWindow(), y+i, x+2, ACS_CKBOARD); 
                mvwaddch(tetris->getWindow(), y+i, x+3, ACS_CKBOARD); 
            }
        }
        break;
    case 2:
        for (int i=0; i<6; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
            if (i == 2 || i == 3) {mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); }
        }
        break;
    case 3:
        for (int i=0; i<3; i++) 
        {     
            if (i == 1) 
            {
                mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
                mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD); 
            }
            mvwaddch(tetris->getWindow(), y+i, x+2, ACS_CKBOARD);
            mvwaddch(tetris->getWindow(), y+i, x+3, ACS_CKBOARD);   
        }
        break;
    default:
        assert(0);
    }     
    wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
}

void Figure_T::clear()
{
    switch (state){
    
    case 0:
        for (int i=0; i<6; i++) 
        {     
            if (i == 2 || i == 3) {mvwaddch(tetris->getWindow(), y, x+i, ' '); }
            mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
        }
        break;
    case 1:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ' ');
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');   
            if (i == 1) 
            {
                mvwaddch(tetris->getWindow(), y+i, x+2, ' '); 
                mvwaddch(tetris->getWindow(), y+i, x+3, ' '); 
            }
        }
        break;
    case 2:
        for (int i=0; i<6; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
            if (i == 2 || i == 3) {mvwaddch(tetris->getWindow(), y+1, x+i, ' '); }
        }
        break;
    case 3:
        for (int i=0; i<3; i++) 
        {     
            if (i == 1) 
            {
                mvwaddch(tetris->getWindow(), y+i, x, ' '); 
                mvwaddch(tetris->getWindow(), y+i, x+1, ' '); 
            }
            mvwaddch(tetris->getWindow(), y+i, x+2, ' ');
            mvwaddch(tetris->getWindow(), y+i, x+3, ' ');   
        }
        break;
    default:
        assert(0);
    } 
}
*/
