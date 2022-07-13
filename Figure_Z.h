#include "Figure.h"

using namespace std;


class Figure_Z: public Figure 
{

    public:

        Figure_Z(Tetris *tetris) : Figure(tetris, RED) {}

        virtual ~Figure_Z() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        virtual void draw();
        virtual void clear();

    private:
        unsigned int magic [4];

};