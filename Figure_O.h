#include "Figure.h"

using namespace std;


class Figure_O: public Figure 
{

    public:

        Figure_O(Tetris *tetris) : Figure(tetris, YELLOW) {}

        virtual ~Figure_O() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

};