#include "Figure.h"

using namespace std;


class Stick: public Figure {
    private:
        int StickHeight = 4;
        int StickWidth = 2;

    public:

        Stick(Tetris *tetris) : Figure(tetris, GREEN) {}

        virtual ~Stick() = default;


        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

        virtual void down();
        virtual void rotate();
};