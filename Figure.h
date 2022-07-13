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

    public:
        Figure(Tetris *t, int col)
        { 
            tetris = t;
            //x = (tetris->getWinWidth()-2-getFigureWidth())/2;
            x = (tetris->getWinWidth()-2-2)/2;
            y = 5;
            color = col;    
            state = rand() % 4;  
//            mvwprintw(win, 0, 0, "w:%d h:%d", figureHeight, figureWidth);
//            mvwprintw(tetris->getWindow(), 0, 0, "state: %d", state);
        }

        virtual ~Figure() = default;

        virtual int getFigureHeight() = 0;
        virtual int getFigureWidth() = 0;
        //virtual void draw(bool drawme = true) = 0;
        virtual void draw() = 0;
        virtual void clear() = 0;
        
        void moveRight()
        { 
            if (x + getFigureWidth() < tetris->getWinWidth()-1){
                clear();
                x++;
                draw();
            }
        }

        void moveLeft()
        {
            if (x > 1){
                clear();
                x--;
                draw();
            }
        }

        bool down()
        {
            if (y + getFigureHeight() < tetris->getWinHeight() - 1){
                clear();
                y++;
                draw();
                return true;
            }
            return false;
        }

        bool canRotate()
        {
            if( (x + getFigureHeight()*2 < tetris->getWinWidth()) 
                && (y + getFigureWidth()/2 < tetris->getWinHeight())){
                return true;
            }
            return false;
        }

        void rotate()
        {
            if(canRotate()){
                clear();
                state = (state + 1) % 4;
                draw();
            }
        }


};

#endif
