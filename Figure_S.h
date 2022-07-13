#include "Figure.h"

using namespace std;


class Figure_S: public Figure 
{

    public:

        Figure_S(Tetris *tetris) : Figure(tetris, GREEN) {}

        virtual ~Figure_S() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

    private:
        unsigned int magic [4];

};