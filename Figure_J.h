#include "Figure.h"

using namespace std;


class Figure_J: public Figure 
{

    public:

        Figure_J(Tetris *tetris) : Figure(tetris, BLUE) {}

        virtual ~Figure_J() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();
        virtual void drawB(bool draw = true);
        virtual void clearB();


    private:
        unsigned int magic [4] =
        {
            0x000F0C0C,                 // 00001100
                                        // 00001100
                                        // 00001111
                                        // 00000000

            0x00003F03,                 // 00000011
                                        // 00111111
                                        // 00000000
                                        // 00000000

            0x0003030F,                 // 00001111
                                        // 00000011
                                        // 00000011
                                        // 00000000

            0x0000303F,                 // 00111111
                                        // 00110000
                                        // 00000000
                                        // 00000000

        };

};