#ifndef FIGURE_H
#define FIGURE_H

#include "Tetris.h"

using namespace std;


enum Colors {
    RED = 1,
    GREEN = 2,
    BLUE = 3,
    };

class Figure {

    protected:
        Tetris * tetris;
        int x, y;       //top left
        int color;

    public:
        Figure(Tetris *t, int col){
            tetris = t;
            //x = (tetris->getWinWidth()-2-getFigureWidth())/2;
            x = (tetris->getWinWidth()-2-2)/2;
            y = 5;
            color = col;         
//            mvwprintw(win, 0, 0, "w:%d h:%d", figureHeight, figureWidth);
        }

        virtual ~Figure() = default;

        virtual int getFigureHeight() = 0;
        virtual int getFigureWidth() = 0;
        virtual void draw() = 0;
        virtual void clear() = 0;
        
        virtual void down() = 0;
        virtual void rotate() = 0;
        
        void moveRight(){ 
            if (x < tetris->getWinWidth()-3){
                clear();
                x++;
                draw();
            }
        }

        void moveLeft(){
            if (x > 1){
                clear();
                x--;
                draw();
            }
        }

};

#endif
