#include <curses.h>
#include <cassert>
#include "Figure_O.h"


int Figure_O::getFigureHeight() 
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

int Figure_O::getFigureWidth() 
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

/*
void Figure_O::draw()
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

void Figure_O::clear()
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
*/

void Figure_O::drawB(bool _draw)
{
    mvwprintw(tetris->getWindow(), 0, 0, "state: %d number: %d", state, magic);
    if (_draw) { wattron(tetris->getWindow(), COLOR_PAIR(color)); }
    
    unsigned int magicState = magic[state];

    int tmp_x = x;
    int tmp_y = y;
    unsigned int mask = 0x00000001;

    for (int i=0;i<32;i++) {
    
        if (magicState & mask)
        {
            mvwaddch(tetris->getWindow(), tmp_y, tmp_x, _draw ? ACS_CKBOARD : ' ');
        }

        tmp_x++;
        mask <<= 1;

        if(i%8 == 7) 
        {
            tmp_y++;
            tmp_x = x;
        }
    }

    if (_draw) { wattroff(tetris->getWindow(), COLOR_PAIR(color)); }
}

void Figure_O::clearB()
{
    drawB(false);
}
