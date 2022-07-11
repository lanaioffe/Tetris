#include "Figure.h"

using namespace std;


class Stick: public Figure 
{

    public:

        Stick(Tetris *tetris) : Figure(tetris, CYAN) {}

        virtual ~Stick() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

};