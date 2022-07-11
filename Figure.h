#ifndef FIGURE_H
#define FIGURE_H

using namespace std;

const int winWidth = 50;
const int winHeight = 50;
enum Colors {
    RED = 1,
    GREEN = 2,
    BLUE = 3,
    };

class Figure {

    public:
        Figure(WINDOW *window, int height, int width){
            x = (winWidth-2-width)/2;
            y = 5;
            h = height;
            w = width;
            color = RED;
            win = window;
//            mvwprintw(win, 0, 0, "w:%d h:%d", height, width);
        }

        virtual ~Figure() = default;

        virtual void draw() = 0;
        virtual void clear() = 0;
        
        virtual void down() = 0;
        virtual void rotate() = 0;
        
        void moveRight(){ 
            if (x < winWidth-3){
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

    protected:
        int x, y;       //top left
        int h, w;
        int color;
        WINDOW * win;

};

const int StickHeight = 4;
const int StickWidth = 2;

class Stick: public Figure {
    public:

        Stick(WINDOW *w) : Figure(w, StickHeight, StickWidth) {}

        virtual ~Stick() = default;

        virtual void draw();
        virtual void clear();

        virtual void down();
        virtual void rotate();

};

#endif
