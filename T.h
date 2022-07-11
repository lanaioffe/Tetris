#include "Figure.h"

using namespace std;


class T: public Figure 
{

    public:

        T(Tetris *tetris) : Figure(tetris, MAGENTA) {}

        virtual ~T() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

};