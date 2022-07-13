#include "Figure.h"

using namespace std;


class Figure_O: public Figure 
{

    public:

        Figure_O(Tetris *tetris) : Figure(tetris, YELLOW, magic) {}

        virtual ~Figure_O() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();
        // virtual void drawB(bool draw = true);
        // virtual void clearB();


    private:
        static constexpr unsigned int magic [4] = 
        {
            0x00000F0F,                     // 00001111
                                            // 00001111
                                            // 00000000
                                            // 00000000
            0x00000F0F,
            0x00000F0F,
            0x00000F0F,
        };

};