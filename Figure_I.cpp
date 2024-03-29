#include <curses.h>
#include <cassert>
#include "Figure_I.h"


// int Figure_I::getFigureHeight() 
// {
//     switch (state)
//     {
//     case 0:
//     case 2:
//         return 4;
    
//     case 1:
//     case 3:
//         return 1;
    
//     default:
//         assert(0);
//     }
// }

// int Figure_I::getFigureWidth() 
// { 
//     switch (state)
//     {    
//     case 0:
//     case 2:
//         return 2;
    
//     case 1:
//     case 3:
//         return 8;
    
//     default:
//         assert(0);
//     }
// }



/*
void Figure_I::draw()
{
    wattron(tetris->getWindow(), COLOR_PAIR(color));   
    switch (state)
    {
    case 0:
    case 2:
        for (int i=0; i<4; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ACS_CKBOARD); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ACS_CKBOARD);
        }
        break;
   
    case 1:
    case 3:
        for (int i=0; i<8; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ACS_CKBOARD); 
        }
        break;
    
    default:
        assert(0);
    }
    wattroff(tetris->getWindow(), COLOR_PAIR(color)); 
}


void Figure_I::clear()
{
    switch (state)
    {
    case 0:
    case 2:
        for (int i=0; i<4; i++) 
        {     
            mvwaddch(tetris->getWindow(), y+i, x, ' '); 
            mvwaddch(tetris->getWindow(), y+i, x+1, ' ');
        }
        break;
   
    case 1:
    case 3:
        for (int i=0; i<8; i++) 
        {     
            mvwaddch(tetris->getWindow(), y, x+i, ' '); 
        }
        break;
    
    default:
        assert(0);
    }
}
*/

// int Figure_I::getFigureHeight() 
// {
//     int height = 0;
//     unsigned int mask = 0x80000000;             // 00000000
//                                                 // 00000000
//                                                 // 00000000
//                                                 // 10000000

//     unsigned int magicState = magic[state];
//     int tmp_x = x+7;
//     int tmp_y = y+3;

//     for (int i=0; i<32; i++)
//     {
//         if(magicState & mask)
//         {
//             height = tmp_y - y + 1;
//             //mvwprintw(tetris->getWindow(), 0, 0, "height: %d state: %d", height, state);
//             return height;
//         }
//         mask >>= 1;
//         tmp_x --;

//         if (i%8 == 7)
//         {
//             tmp_y --;
//             tmp_x = x+7;
//         }
//     }
//     return height;
// }

// int Figure_I::getFigureWidth() 
// {
//     int width = 0;
//     unsigned int mask = 0x80000000;             // 00000000
//                                                 // 00000000
//                                                 // 00000000
//                                                 // 10000000

//     unsigned int magicState = magic[state];
//     int tmp_x = x+7;
//     int tmp_y = y+3;

//     for (int i=0; i<32; i++)
//     {
//         if(magicState & mask)
//         {
//             width = tmp_x - x + 1;
//             //mvwprintw(tetris->getWindow(), 0, 0, "width: %d state: %d", width, state);
//             return width;
//         }
//         mask >>= 1;
//         tmp_x --;
        
//         if (i%8 == 7)
//         {
//             tmp_y --;
//             tmp_x = x+7;
//         }
//     }
//     return width;
// }