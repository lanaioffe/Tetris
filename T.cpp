#include <curses.h>
#include "T.h"


int T::getFigureHeight() 
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
        return 2;
    }
}

int T::getFigureWidth() 
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
        return 6;
    }
}

void T::draw()
{
    switch (state){
    
    case 0:
        for (int i=0; i<3; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color)); 
            if (i == 1) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }
            else {mvwaddch(tetris->getWindow(), y, x+i, ' '); }
            //wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
            //mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            //wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    case 1:
        for (int i=0; i<3; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color)); 
            mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
            //wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
            //mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            //wattron(tetris->getWindow(), COLOR_PAIR(color));     
            if (i == 1) {mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD); }
            else {mvwaddch(tetris->getWindow(), y+i, x+1, ' '); }
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    case 2:
        for (int i=0; i<3; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color)); 
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
            //wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
            //mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            //wattron(tetris->getWindow(), COLOR_PAIR(color));     
            if (i == 1) {mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); }
            else {mvwaddch(tetris->getWindow(), y+1, x+i, ' '); }
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    case 3:
        for (int i=0; i<3; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color)); 
            if (i == 1) {mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); }
            else {mvwaddch(tetris->getWindow(), y+i, x, ' '); }
            //wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
            //mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            //wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD); 
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    default:
        for (int i=0; i<3; i++) 
        {     
            wattron(tetris->getWindow(), COLOR_PAIR(color)); 
            if (i == 1) {mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); }
            else {mvwaddch(tetris->getWindow(), y, x+i, ' '); }
            //wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
            //mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
            //wattron(tetris->getWindow(), COLOR_PAIR(color));     
            mvwaddch(tetris->getWindow(), y+1, x+i, ACS_CKBOARD); 
            wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
        }
        break;
    }
}

void T::clear()
{
        switch (state){
    
    case 0:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
            mvwaddch(tetris->getWindow(), y+1, x+i, ' '); 
        }
        break;
    case 1:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ' '); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');              
        }
        break;
    case 2:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
            mvwaddch(tetris->getWindow(), y+1, x+i, ' ');              
        }
        break;
    case 3:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ' '); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');     
        }
        break;
    default:
        for (int i=0; i<3; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
            mvwaddch(tetris->getWindow(), y+1, x+i, ' ');  
        }
        break;
    }
}


