#include "Figure.h"

using namespace std;


class Figure_L: public Figure 
{

    public:

        Figure_L(Tetris *tetris) : Figure(tetris, WHITE) {}

        virtual ~Figure_L() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();
        virtual void drawB(bool draw = true);
        virtual void clearB();


    private:
        static constexpr unsigned int magic [4] =
        {
            0x000F0303,                     // 00000011
                                            // 00000011
                                            // 00001111
                                            // 00000000

            0x0000033F,                     // 00111111
                                            // 00000011
                                            // 00000000
                                            // 00000000

            0x000C0C0F,                     // 00001111
                                            // 00001100
                                            // 00001100
                                            // 00000000

            0x00003F30,                     // 00110000 
                                            // 00111111
                                            // 00000000
                                            // 00000000

        };

};