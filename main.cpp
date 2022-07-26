/*
    @LAPTOP-.... /cygdrive/c/dev/Tetris

    $ g++ main.cpp -lncurses -I . -o main && main
    $ make clean && make && main
    or:
    make
    main.exe
*/

#include <curses.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <cassert>

#include "Tetris.h"
#include "Figure.h"
#include "Figure_I.h"
#include "Figure_O.h"
#include "Figure_T.h"
#include "Figure_S.h"
#include "Figure_Z.h"
#include "Figure_J.h"
#include "Figure_L.h"

using namespace std;

Figure * createRandomFigure(Tetris *tetris){
    Figure *next;
    int figureType = rand() % 7;

    switch(figureType)
    {
        case 0:
            next = new Figure_I(tetris);
            break;
        case 1:
            next = new Figure_O(tetris);
            break;
        case 2:
            next = new Figure_T(tetris);
            break;
        case 3:
            next = new Figure_S(tetris);
            break;
        case 4:
            next = new Figure_Z(tetris);
            break;
        case 5:
            next = new Figure_J(tetris);
            break;
        case 6:
            next = new Figure_L(tetris);
            break;
    }

    if(! tetris->canMove(next, next->getX(), next->getY(), next->getState())) 
    {
        tetris->endGame();
        return next;
    }

    return next;
}

int main(void)
{
    srand(time(NULL));
    initscr();
    noecho();       //do not print pressed btn
    cbreak();	    /* Line buffering disabled. pass on everything */
    curs_set(0);    //delete cursor

	start_color();
	init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);	
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);


    Tetris *tetris = new Tetris();

    keypad(tetris->getWindow(), TRUE); // ><
    nodelay(tetris->getWindow(), TRUE); //делает чтобы wgetch не ждал кнопки

  
    tetris->refresh();

    bool quit = false;

    Figure *figure = createRandomFigure(tetris);
    
    unsigned tick = 0;

    while(! quit) 
    {
        figure->drawB();
        tetris->refresh();
        
        int ch = wgetch(tetris->getWindow());         // return pushed btn
        
        switch(ch) 
        {
            case KEY_RIGHT:
            case 'a':
                figure->moveRight();
                break;

            case KEY_LEFT:
            case 'd':
                figure->moveLeft();
                break;

            case KEY_DOWN:
            case 'x':
                while(figure->down()) 
                {
                    tetris->refresh();
                    Sleep(15);
                }

                delete figure;
                figure = createRandomFigure(tetris);

                break;

            case ' ':
                figure->rotate();
                break;

            case 'q':
                quit = true;
                break;

            case 'p':
                while(wgetch(tetris->getWindow()) != 'p');
                break;
                
            default:
                break;
        }
        
        tick++;
       
        Sleep(20);

        if (tick % 16 == 0) 
        {
            if(!figure->down())
            {
                delete figure;
                figure = createRandomFigure(tetris);
            }
        }

    }

    delete figure;

	tetris->refresh();
	    
    endwin();
    return 0;
}



#if 0
int main(void)
{
    initscr();

    noecho();   //do not print pressed btn
    cbreak();	/* Line buffering disabled. pass on everything */
    curs_set(0); //delete cursor

	WINDOW *w = newwin(winWidth, winHeight,0,0);
    wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
    //wborder(w, '|', '|', '-', '-', '1', '2', '3', '4');
    // wborder(window, left vertical, right vertical, top horizontal, bottom horizontal, 
    // top left corner, top right corner, bottom left corner, bottom right corner);

    keypad(w, TRUE); // ><

    wrefresh(w);    

    bool quit = false;

    Figure *figure = new Stick(w);

    while(! quit) {
        int ch = wgetch(w);         // return pushed btn
        
        switch(ch) {
            case KEY_RIGHT:
            case 'a':
                figure->moveRight();
                break;

            case KEY_LEFT:
            case 'd':
                figure->moveLeft();
                break;

            case KEY_DOWN:
            case 'x':
                figure->down();
                break;

            case 'q':
                quit = true;
                break;

            default:
                break;
        }

        figure->draw();

        wrefresh(w);
    }

    delete figure;

	wrefresh(w);
	/*
    mvwprintw(w,1, 7, "NCURSES EXTENDED CHARACTERS");
    mvwprintw(w,5, 7, "|");   // (window, y.coordinate to start - vertical, x.coordinate to start - horizontal, symbol)
	mvwprintw(w,6, 7, "|");
	mvwprintw(w,7, 7, "|");
	mvwprintw(w,8, 7, "|");
	mvwprintw(w,8, 8, "-");
	mvwprintw(w,5, 8, "-");
	mvwprintw(w,5, 9, "|");
	mvwprintw(w,6, 9, "|");
	mvwprintw(w,7, 9, "|");
	mvwprintw(w,8, 9, "|");

    for (int i=0;i<4;i++) {                     // fill with square
		mvwaddch(w, 11+i, 7, ACS_CKBOARD); 
		
		mvwaddch(w, 11+i, 8, ACS_CKBOARD);
	}

    attron(A_UNDERLINE);
    mvprintw(0, 7, "NCURSES EXTENDED CHARACTERS\n");
    attroff(A_UNDERLINE);
    printw("\nUpper left corner         "); addch(ACS_ULCORNER); printw("  ACS_ULCORNER\t");
    printw("\nLower left corner         "); addch(ACS_LLCORNER); printw("  ACS_LLCORNER\t");
    printw("\nUpper right corner        "); addch(ACS_URCORNER); printw("  ACS_URCORNER\t");
    printw("\nLower right corner        "); addch(ACS_LRCORNER); printw("  ACS_LRCORNER\t");
    printw("\nTee pointing right        "); addch(ACS_LTEE); printw("  ACS_LTEE\t");
    printw("\nTee pointing left         "); addch(ACS_RTEE); printw("  ACS_RTEE\t");
    printw("\nTee pointing up           "); addch(ACS_BTEE); printw("  ACS_BTEE\t");
    printw("\nTee pointing down         "); addch(ACS_TTEE); printw("  ACS_TTEE\t");
    printw("\nHorizontal line           "); addch(ACS_HLINE); printw("  ACS_HLINE\t");
    printw("\nVertical line             "); addch(ACS_VLINE); printw("  ACS_VLINE\t");
    printw("\nLarge Plus or cross over  "); addch(ACS_PLUS); printw("  ACS_PLUS\t");
    printw("\nScan Line 1               "); addch(ACS_S1); printw("  ACS_S1\t");
    printw("\nScan Line 3               "); addch(ACS_S3); printw("  ACS_S3\t");
    printw("\nScan Line 7               "); addch(ACS_S7); printw("  ACS_S7\t");
    printw("\nScan Line 9               "); addch(ACS_S9); printw("  ACS_S9\t");
    printw("\nDiamond                   "); addch(ACS_DIAMOND); printw("  ACS_DIAMOND\t");
    printw("\nChecker board (stipple)   "); addch(ACS_CKBOARD); printw("  ACS_CKBOARD\t");
    printw("\nDegree Symbol             "); addch(ACS_DEGREE); printw("  ACS_DEGREE\t");
    printw("\nPlus/Minus Symbol         "); addch(ACS_PLMINUS); printw("  ACS_PLMINUS\t");
    printw("\nBullet                    "); addch(ACS_BULLET); printw("  ACS_BULLET\t");
    printw("\nArrow Pointing Left       "); addch(ACS_LARROW); printw("  ACS_LARROW\t");
    printw("\nArrow Pointing Right      "); addch(ACS_RARROW); printw("  ACS_RARROW\t");
    printw("\nArrow Pointing Down       "); addch(ACS_DARROW); printw("  ACS_DARROW\t");
    printw("\nArrow Pointing Up         "); addch(ACS_UARROW); printw("  ACS_UARROW\t");
    printw("\nBoard of squares          "); addch(ACS_BOARD); printw("  ACS_BOARD\t");
    printw("\nLantern Symbol            "); addch(ACS_LANTERN); printw("  ACS_LANTERN\t");
    printw("\nSolid Square Block        "); addch(ACS_BLOCK); printw("  ACS_BLOCK\t");
    printw("\nLess/Equal sign           "); addch(ACS_LEQUAL); printw("  ACS_LEQUAL\t");
    printw("\nGreater/Equal sign        "); addch(ACS_GEQUAL); printw("  ACS_GEQUAL\t");
    printw("\nPi                        "); addch(ACS_PI); printw("  ACS_PI\t");
    printw("\nNot equal                 "); addch(ACS_NEQUAL); printw("  ACS_NEQUAL\t");
    printw("\nUK pound sign             "); addch(ACS_STERLING); printw("  ACS_STERLING\t\n");
    refresh();
	wgetch(w);                  // return pushed btn
    */
    
    endwin();
    return 0;
}
#endif
