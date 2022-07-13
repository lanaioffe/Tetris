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

    private:
        unsigned int magic [4] = {
            0x03030303,                     // 000000011        0b000000110000001100000001100000011
                                            // 000000011    
                                            // 000000011
                                            // 000000011

            0x000000FF,                     // 111111111
                                            // 000000000 ...
            0x03030303,
            0x000000FF,
        };

};