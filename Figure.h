#ifndef FIGURE_H
#define FIGURE_H

#include <cstdlib>
#include<cstdint>


using namespace std;


enum Colors {
    CYAN = 0,
    YELLOW = 1,
    MAGENTA = 2,      
    BLUE = 3,
    WHITE = 4,
    GREEN = 5,
    RED = 6,
};

class Tetris;

class Figure 
{
    protected:
        Tetris * tetris;
        int x, y;       //top left of figure
        int color;
        int state;
        unsigned int magicNumber [4];

    public:
        Figure(Tetris *t, int col, const unsigned figureMagicNumber [4]);
        

        virtual ~Figure() = default;

        // virtual int getFigureHeight() = 0;
        // virtual int getFigureWidth() = 0;
        //virtual void draw() = 0;
        //virtual void clear() = 0;


        int getFigureHeight() 
        {
            int height = 0;
            unsigned int mask = 0x80000000;             // 00000000
                                                        // 00000000
                                                        // 00000000
                                                        // 10000000

            unsigned int magicState = magicNumber[state];
            int tmp_x = x+7;
            int tmp_y = y+3;                    //max heigth 

            //comparing every x in every row starting from max height 
            for (int i=0; i<32; i++)
            {
                if(magicState & mask)
                {
                    height = tmp_y - y + 1;
                    return height;
                }
                mask >>= 1;
                tmp_x --;

                if (i%8 == 7)           //change row 
                {
                    tmp_y --;
                    tmp_x = x+7;        //x from the start
                }
            }
            return height;
        }


        int getFigureWidth() 
        {
            int width = 0;
            int tmpW = 0;
            unsigned int mask = 0x80000000;             // 00000000
                                                        // 00000000
                                                        // 00000000
                                                        // 10000000

            unsigned int magicState = magicNumber[state];
            int tmp_x = x+7;
            int tmp_y = y+3;

            for (int i=0; i<32; i++)
            {
                if(magicState & mask)
                {
                    tmpW = tmp_x - x + 1;

                    if (tmpW == 8) {return tmpW;}                  //max width
                    if (width < tmpW) { width = tmpW;}             //because of moving from the max height, width could be less on the heighest row
                }
                mask >>= 1;
                tmp_x --;
                
                if (i%8 == 7)
                {
                    tmp_y --;
                    tmp_x = x+7;
                }
            }
            return width;
        }


        void drawB(bool _draw = true);
        void clearB();


        //create masks from figure magic number by state and row 
        //using shift for deleting extra 0 from the begining
        u_int64_t getMaskForRow(int row, int moveState) const;

   
        void moveRight();
 
        void moveLeft();
 
        bool down();
  
        bool canRotate();

        void rotate();

        int getState()const {return state;}

        int getX() const {return x;}
        int getY() const {return y;}

};

#endif
