#include "Figure.h"

using namespace std;


class Figure_Z: public Figure 
{

    public:

        Figure_Z(Tetris *tetris) : Figure(tetris, RED) {}

        virtual ~Figure_Z() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();
        virtual void drawB(bool draw = true);
        virtual void clearB();


    private:
        static constexpr unsigned int magic [4] = 
        {
            0x00003C0F,                         // 00001111
                                                // 00111100
                                                // 00000000
                                                // 00000000
            
            0x00030F0C,                         // 00001100
                                                // 00001111
                                                // 00000011
                                                // 00000000
            
            0x00003C0F,                         // 00001111
                                                // 00111100
                                                // 00000000
                                                // 00000000
            
            0x00030F0C,                         // 00001100
                                                // 00001111
                                                // 00000011
                                                // 00000000                                  
        };

};