#include <curses.h>
#include <cassert>
#include "Figure.h"
#include "Tetris.h"

Figure::Figure(Tetris *t, int col, const unsigned figureMagicNumber[4])
{
    tetris = t;
    x = (tetris->getWinWidth() - 2 - 2) / 2; // find the middle сonsidering figure size/2 and 2 for borders
    y = 5;
    color = col;
    state = rand() % 4;
    for (int i = 0; i < 4; i++)
    {
        magicNumber[i] = figureMagicNumber[i];
    }
    //            mvwprintw(win, 0, 0, "w:%d h:%d", figureHeight, figureWidth);
    //            mvwprintw(tetris->getWindow(), 0, 0, "state: %d", state);
}

// create masks from figure magic number by state and row
// using shift for deleting extra 0 from the begining
u_int64_t Figure::getMaskForRow(int row, int moveState) const
{
    switch (row)
    {
    case 0:
        return (uint64_t)magicNumber[moveState] & 0x000000FF; // 00000000 00000000 00000000 11111111

    case 1:
        return (uint64_t)(magicNumber[moveState] & 0x0000FF00) >> 8; // 00000000 00000000 11111111 00000000

    case 2:
        return (uint64_t)(magicNumber[moveState] & 0x00FF0000) >> 16; // 00000000 11111111 00000000 00000000

    case 3:
        return (uint64_t)(magicNumber[moveState] & 0xFF000000) >> 24; // 11111111 00000000 00000000 00000000

    default:
        assert(0);
    }
}

void Figure::drawB(bool _draw)
{
    if (_draw)
    {
        wattron(tetris->getWindow(), COLOR_PAIR(color));
    }

    unsigned int magicState = magicNumber[state];

    int tmp_x = x;
    int tmp_y = y;
    unsigned int mask = 0x00000001;

    for (int i = 0; i < 32; i++)
    {
        if (magicState & mask)
        {
            mvwaddch(tetris->getWindow(), tmp_y, tmp_x, _draw ? ACS_CKBOARD : ' ');
        }

        tmp_x++;
        mask <<= 1;

        if (i % 8 == 7) // change row, move x to start
        {
            tmp_y++;
            tmp_x = x;
        }
    }
    if (_draw)
    {
        wattroff(tetris->getWindow(), COLOR_PAIR(color));
    }
}

void Figure::clearB()
{
    drawB(false);
}


void Figure::moveRight()
{
    // if ( (x + getFigureWidth() < tetris->getWinWidth()-1) && canMove(x+2, y, state) )
    if (tetris->canMove(this, x + 2, y, state))
    {
        clearB();
        x += 2;
        drawB();
    }
}

void Figure::moveLeft()
{
    // if ( (x > 1) && canMove(x-2, y, state) )
    if (tetris->canMove(this, x - 2, y, state))
    {
        clearB();
        x -= 2;
        drawB();
    }
}

bool Figure::down()
{
    if (tetris->canMove(this, x, y + 1, state))
    {
        clearB();
        y++;
        drawB();

        return true;
    }
    tetris->putFigure(this) ;
    return false;
}

bool Figure::canRotate()
{
    // if( (x + getFigureHeight()*2 < tetris->getWinWidth()) &&
    if (tetris->canMove(this, x, y, (state + 1) % 4))
    {
        return true;
    }
    return false;
}

void Figure::rotate()
{
    if (canRotate())
    {
        clearB();
        state = (state + 1) % 4;
        drawB();
    }
}
