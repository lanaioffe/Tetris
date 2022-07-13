#include "Figure.h"

using namespace std;


class Figure_I: public Figure 
{

    public:

        Figure_I(Tetris *tetris) : Figure(tetris, CYAN, magic) {}

        virtual ~Figure_I() = default;

        virtual int getFigureHeight();
        virtual int getFigureWidth();
        //virtual void draw();
        //virtual void clear();
        // virtual void drawB(bool draw = true);
        // virtual void clearB();

    private:
        static constexpr unsigned int magic [4] = 
        {
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