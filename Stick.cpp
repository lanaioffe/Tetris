#include <curses.h>
#include "Stick.h"


int Stick::getFigureHeight() 
{
    switch (state){
        
    case 0:
    case 2:
        return 4;
    
    case 1:
    case 3:
        return 1;
    
    default:
        return 4;
    }
}

int Stick::getFigureWidth() 
{ 
    switch (state){
        
    case 0:
    case 2:
        return 2;
    
    case 1:
    case 3:
        return 8;
    
    default:
        return 2;
    }
}

void Stick::draw()
{
    switch (state){
    
    case 0:
    case 2:
        for (int i=0; i<4; i++) {     
            wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
   
    case 1:
    case 3:
        for (int i=0; i<8; i++) {     
            wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    
    default:
        for (int i=0; i<4; i++) {     
            wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    }
}

void Stick::clear()
{
    switch (state){
    
    case 0:
    case 2:
        for (int i=0; i<4; i++) {          
            mvwaddch(tetris->getWindow(), y+i, x, ' '); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');
        }
        break;
    
    case 1:
    case 3:
        for (int i=0; i<8; i++) {          
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
        }
        break;
   
    default:
        for (int i=0; i<4; i++) {          
            mvwaddch(tetris->getWindow(), y+i, x, ' '); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');
        }
        break;
    }
}


