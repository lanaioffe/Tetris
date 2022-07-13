#include "Figure.h"

using namespace std;


class Figure_J: public Figure 
{

    public:

        Figure_J(Tetris *tetris) : Figure(tetris, BLUE) {}

        virtual ~Figure_J() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

    private:
        unsigned int magic [4] ;

};