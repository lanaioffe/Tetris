/*
    $ g++ main.cpp -lncurses -I . -o main && main
    $ make clean && make && main
    or:
    make
    main.exe
*/

#include <curses.h>
#include "Tetris.h"
#include "Figure.h"

using namespace std;


int main(void)
{
    initscr();
    noecho();       //do not print pressed btn
    cbreak();	    /* Line buffering disabled. pass on everything */
    curs_set(0);    //delete cursor

	WINDOW *w = newwin(winWidth, winHeight,0,0);
    wborder(w, 0, 0, 0, 0, 0, 0, 0, 0);
    //wborder(w, '|', '|', '-', '-', '1', '2', '3', '4');
    // wborder(window, left vertical, right vertical, top horizontal, bottom horizontal, 
    // top left corner, top right corner, bottom left corner, bottom right corner);

    keypad(w, TRUE); // ><


	start_color();
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);

	mvwprintw(w,1, 7, "NCURSES EXTENDED CHARACTERS");

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
	    
    endwin();
    return 0;
}



#if 0
int main(void)
{
    initscr();

    // resizeterm(int lines, int columns);

	if(has_colors() == FALSE)
	{	
        endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}

	start_color();
	init_pair(RED_BLOCK, COLOR_RED, COLOR_BLACK);
	init_pair(GRASS, COLOR_GREEN, COLOR_BLACK);
	init_pair(WATER, COLOR_BLUE, COLOR_BLACK);

    noecho();
    cbreak();	/* Line buffering disabled. pass on everything */
    //timeout(500);     // wait 500ms for key press
    //int nodelay(WINDOW *win, bool bf)
    curs_set(0);

    int maxx,maxy;
    getmaxyx(stdscr, maxy, maxx);

    move(0,0);

    refresh();

//  Window main_win(maxy/*height*/, maxx-40/*width*/, 0/*starty*/, 0/*startx*/);
    Game_Scene main_win(maxy, maxx-40);
    keypad(main_win.get(), TRUE);
    main_win.draw_scene();
    main_win.refresh();

    Window status_win(maxy/*height*/, 40/*width*/, 0/*starty*/, maxx-40/*startx*/);
    mvwprintw(status_win.get(), 1, 1, "dimy: %d, dimx: %d", maxy, maxx);
    mvwprintw(status_win.get(), 2, 1, "mainy: %d, mainx: %d", main_win.get_maxy(), main_win.get_maxx());
    mvwprintw(status_win.get(), 3, 1, "sy: %d, sx: %d", main_win.size_x(), main_win.size_y());
    status_win.refresh();

    Tank tank(&main_win, 1, 5, DIR_DOWN);
    tank.draw();

    while(1) {
        int ch = wgetch(main_win.get());
        switch(ch) {
        case KEY_LEFT:
        case 'a':
            tank.turn(DIR_LEFT);
            tank.move();
            mvwprintw(status_win.get(), 4, 1, "LEFT ");
            break;
        case KEY_RIGHT:
        case 'd':
            tank.turn(DIR_RIGHT);
            tank.move();
            mvwprintw(status_win.get(), 4, 1, "RIGHT");
            break;
        case KEY_UP:
        case 'w':
            tank.turn(DIR_UP);
            tank.move();
            mvwprintw(status_win.get(), 4, 1, "UP   ");
            break;
        case KEY_DOWN:
        case 'x':
            tank.turn(DIR_DOWN);
            tank.move();
            mvwprintw(status_win.get(), 4, 1, "DOWN ");
            break;
        case ' ':
            mvwprintw(status_win.get(), 4, 1, "FIRE ");
            break;
        default:
            break;
        }
        main_win.refresh();
        status_win.refresh();
    }

    refresh();

    getch();
    endwin();
    return 0;
}

#endif


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
