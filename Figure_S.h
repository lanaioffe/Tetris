#include "Figure.h"

using namespace std;


class Figure_S: public Figure 
{

    public:

        Figure_S(Tetris *tetris) : Figure(tetris, GREEN, magic) {}

        virtual ~Figure_S() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();


    private:
        static constexpr unsigned int magic [4] = 
        {
            0x00000F3C,                     // 00111100
                                            // 00001111
                                            // 00000000
                                            // 00000000
                                            
            0x000C0F03,                     // 00000011
                                            // 00001111
                                            // 00001100
                                            // 00000000
                                            
            0x00000F3C,                     // 00111100
                                            // 00001111
                                            // 00000000
                                            // 00000000

            0x000C0F03,                     // 00000011
                                            // 00001111
                                            // 00001100
                                            // 00000000
        };

};