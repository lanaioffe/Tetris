#include "Figure.h"

using namespace std;


class Figure_T: public Figure 
{

    public:

        Figure_T(Tetris *tetris) : Figure(tetris, MAGENTA, magic) {}

        virtual ~Figure_T() = default;

        // virtual int getFigureHeight();
        // virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();



    private:
        static constexpr unsigned int magic [4] = 
        {
            0x00003F0C,                     // 00001100
                                            // 00111111
                                            // 00000000
                                            // 00000000
            
            0x00030F03,                     // 00000011
                                            // 00001111
                                            // 00000011
                                            // 00000000

            0x00000C3F,                     // 00111111
                                            // 00001100
                                            // 00000000
                                            // 00000000

            0x000C0F0C,                     // 00001100
                                            // 00001111
                                            // 00001100
                                            // 00000000
        };
};