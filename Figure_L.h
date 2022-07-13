#include "Figure.h"

using namespace std;


class Figure_L: public Figure 
{

    public:

        Figure_L(Tetris *tetris) : Figure(tetris, WHITE) {}

        virtual ~Figure_L() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

    private:
        unsigned int magic [4] ;

};