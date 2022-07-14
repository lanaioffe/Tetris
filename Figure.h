#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include<cstdint>

#include "Tetris.h"

using namespace std;


enum Colors {
    CYAN = 0,
    YELLOW = 1,
    MAGENTA = 2,      
    BLUE = 3,
    WHITE = 4,
    GREEN = 5,
    RED = 6,
};


class Figure 
{
    protected:
        Tetris * tetris;
        int x, y;       //top left of figure
        int color;
        int state;
        unsigned int magicNumber [4];

    public:
        Figure(Tetris *t, int col, const unsigned figureMagicNumber [4])
        { 
            tetris = t;
            x = (tetris->getWinWidth()-2-2)/2;          //find the middle сonsidering figure size/2 and 2 for borders
            y = 5;
            color = col;    
            state = rand() % 4;  
            for (int i=0; i<4; i++)
            {            
                magicNumber[i] = figureMagicNumber[i];
            }
//            mvwprintw(win, 0, 0, "w:%d h:%d", figureHeight, figureWidth);
//            mvwprintw(tetris->getWindow(), 0, 0, "state: %d", state);
        }

        virtual ~Figure() = default;

        // virtual int getFigureHeight() = 0;
        // virtual int getFigureWidth() = 0;
        //virtual void draw() = 0;
        //virtual void clear() = 0;


        int getFigureHeight() 
        {
            int height = 0;
            unsigned int mask = 0x80000000;             // 00000000
                                                        // 00000000
                                                        // 00000000
                                                        // 10000000

            unsigned int magicState = magicNumber[state];
            int tmp_x = x+7;
            int tmp_y = y+3;                    //max heigth 

            //comparing every x in every row starting from max height 
            for (int i=0; i<32; i++)
            {
                if(magicState & mask)
                {
                    height = tmp_y - y + 1;
                    return height;
                }
                mask >>= 1;
                tmp_x --;

                if (i%8 == 7)           //change row 
                {
                    tmp_y --;
                    tmp_x = x+7;        //x from the start
                }
            }
            return height;
        }


        int getFigureWidth() 
        {
            int width = 0;
            int tmpW = 0;
            unsigned int mask = 0x80000000;             // 00000000
                                                        // 00000000
                                                        // 00000000
                                                        // 10000000

            unsigned int magicState = magicNumber[state];
            int tmp_x = x+7;
            int tmp_y = y+3;

            for (int i=0; i<32; i++)
            {
                if(magicState & mask)
                {
                    tmpW = tmp_x - x + 1;

                    if (tmpW == 8) {return tmpW;}                  //max width
                    if (width < tmpW) { width = tmpW;}             //because of moving from the max height, width could be less on the heighest row
                }
                mask >>= 1;
                tmp_x --;
                
                if (i%8 == 7)
                {
                    tmp_y --;
                    tmp_x = x+7;
                }
            }
            return width;
        }


        void drawB(bool _draw = true)
        {
            if (_draw) { wattron(tetris->getWindow(), COLOR_PAIR(color)); }
            
            unsigned int magicState = magicNumber[state];

            int tmp_x = x;
            int tmp_y = y;
            unsigned int mask = 0x00000001;

            for (int i=0;i<32;i++) 
            {
                if (magicState & mask) {mvwaddch(tetris->getWindow(), tmp_y, tmp_x, _draw ? ACS_CKBOARD : ' ');}

                tmp_x++;
                mask <<= 1;

                if(i%8 == 7)                //change row, move x to start
                {
                    tmp_y++;
                    tmp_x = x;
                }
            }
            if (_draw) { wattroff(tetris->getWindow(), COLOR_PAIR(color)); }
        }


        void clearB()
        {
            drawB(false);
        }


        bool canMove(int win_x, int win_y)
        {
            //create masks from figure magic number by state and row 
            //using shift for deleting extra 0 from the begining
            //for comparing row by row on coordinates of window
            uint64_t row_mask0 = magicNumber[state] & 0x000000FF;                   // 00000000 00000000 00000000 11111111
            uint64_t row_mask1 = (magicNumber[state] & 0x0000FF00) >> 8;            // 00000000 00000000 11111111 00000000
            uint64_t row_mask2 = (magicNumber[state] & 0x00FF0000) >> 16;           // 00000000 11111111 00000000 00000000
            uint64_t row_mask3 = (magicNumber[state] & 0xFF000000) >> 24;           // 11111111 00000000 00000000 00000000

            //compare rows from window with masks (accordingly row by row)
            //if at least one of them return true - there is a collision
            if ((tetris->glass[win_y] & (row_mask0 << x )) |
                 (tetris->glass[win_y+1] & (row_mask1 << x)) | 
                  (tetris->glass[win_y+2] & (row_mask2 << x)) |
                   (tetris->glass[win_y+3] & (row_mask3 << x)) ) 
            {
                return false;
            }
            return true;
        }


        void putFigure()
        {
            uint64_t row_mask0 = magicNumber[state] & 0x000000FF;                   // 00000000 00000000 00000000 11111111
            uint64_t row_mask1 = (magicNumber[state] & 0x0000FF00) >> 8;            // 00000000 00000000 11111111 00000000
            uint64_t row_mask2 = (magicNumber[state] & 0x00FF0000) >> 16;           // 00000000 11111111 00000000 00000000
            uint64_t row_mask3 = (magicNumber[state] & 0xFF000000) >> 24;           // 11111111 00000000 00000000 00000000

            //change window with masks of figure 
            tetris->glass[y] = (tetris->glass[y] | (row_mask0 << x ));
            tetris->glass[y+1] = (tetris->glass[y+1] | (row_mask1 << x));
            tetris->glass[y+2] = (tetris->glass[y+2] | (row_mask2 << x));
            tetris->glass[y+3] = (tetris->glass[y+3] | (row_mask3 << x));
        }


        void moveRight()
        { 
            if (canMove(x+1, y) & (x + getFigureWidth() < tetris->getWinWidth()-1))
            {
                clearB();
                x++;
                drawB();
            }
        }


        void moveLeft()
        {
            if (canMove(x-1, y) & (x > 1))
            {
                clearB();
                x--;
                drawB();
            }
        }


        bool down()
        {
            if (canMove(x, y+1) & (y + getFigureHeight() < tetris->getWinHeight() - 1))
            {
                clearB();
                y++;
                drawB();
                
                return true;
            }
            return false;
        }


        bool canRotate()
        {
            if( (x + getFigureHeight()*2 < tetris->getWinWidth()) 
                && (y + getFigureWidth()/2 < tetris->getWinHeight()))
            {
                return true;
            }
            return false;
        }


        void rotate()
        {
            if(canRotate())
            {
                clearB();
                state = (state + 1) % 4;
                drawB();
            }
        }


};

#endif
