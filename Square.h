#include "Figure.h"

using namespace std;


class Square: public Figure 
{

    public:

        Square(Tetris *tetris) : Figure(tetris, YELLOW) {}

        virtual ~Square() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

};