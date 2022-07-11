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
        int x, y;       //top left
        int h, w;
        int color;
        Tetris * tetris;

    public:
        Figure(Tetris *t, int figureHeight, int figureWidth){
            tetris = t;
            x = (tetris->getWinWidth()-2-figureWidth)/2;
            y = 5;
            h = figureHeight;
            w = figureWidth;
            color = RED;         
//            mvwprintw(win, 0, 0, "w:%d h:%d", figureHeight, figureWidth);
        }

        virtual ~Figure() = default;

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



const int StickHeight = 4;
const int StickWidth = 2;

class Stick: public Figure {
    public:

        Stick(Tetris *tetris) : Figure(tetris, StickHeight, StickWidth) {}

        virtual ~Stick() = default;

        virtual void draw();
        virtual void clear();

        virtual void down();
        virtual void rotate();
};

#endif
