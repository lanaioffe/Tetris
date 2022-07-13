#include "Figure.h"

using namespace std;


class Figure_T: public Figure 
{

    public:

        Figure_T(Tetris *tetris) : Figure(tetris, MAGENTA) {}

        virtual ~Figure_T() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

};