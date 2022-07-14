#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include "Tetris.h"

using namespace std;


enum Colors {
    CYAN = 0,
    YELLOW = 1,
    MAGENTA = 2,      //grey
    BLUE = 3,
    WHITE = 4,
    GREEN = 5,
    RED = 6,
};


class Figure 
{
    protected:
        Tetris * tetris;
        int x, y;       //top left
        int color;
        int state;
        unsigned int magicNumber [4];

    public:
        Figure(Tetris *t, int col, const unsigned figureMagicNumber [4])
        { 
            tetris = t;
            x = (tetris->getWinWidth()-2-2)/2;
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
            int tmp_y = y+3;

            for (int i=0; i<32; i++)
            {
                if(magicState & mask)
                {
                    height = tmp_y - y + 1;
                    //mvwprintw(tetris->getWindow(), 0, 0, "height: %d state: %d", height, state);
                    return height;
                }
                mask >>= 1;
                tmp_x --;

                if (i%8 == 7)
                {
                    tmp_y --;
                    tmp_x = x+7;
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
                    //mvwprintw(tetris->getWindow(), 0, 0, "width: %d tmpW: %d state: %d", width, tmpW, state);

                    if (tmpW == 8) {return tmpW;}                       //max width
                    if (width < tmpW) { width = tmpW;}                 
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

                if(i%8 == 7) 
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

        void moveRight()
        { 
            if (x + getFigureWidth() < tetris->getWinWidth()-1){
                clearB();
                x++;
                drawB();
            }
        }

        void moveLeft()
        {
            if (x > 1){
                clearB();
                x--;
                drawB();
            }
        }

        bool down()
        {
            if (y + getFigureHeight() < tetris->getWinHeight() - 1){
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
