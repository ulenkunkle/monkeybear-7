#include <stdlib.h>
#include <iostream>
#include <curses.h>
#include <unistd.h>
//#include <asoundlib.h>
int main()
{
int x;

system("play chant21.wav -q");

std::cout<< "llllllllllllllllllll";
initscr();
start_color();

init_pair(1,COLOR_BLACK, COLOR_BLACK);
init_pair(2,COLOR_BLUE, COLOR_YELLOW);
init_pair(3,COLOR_BLUE, COLOR_WHITE);

for(x = 0;x<100;x++){
//printw("                   ");
usleep(60000);
move(9,7+x);
attron(COLOR_PAIR(1));
printw("    " );
move(11,7+x);printw("   ");
move(13,7+x);printw("   ");
attron (COLOR_PAIR(3));
move(7,112-x);
printw(" ***    ***     ***  ***  ****    ***");
move(8,112-x);
printw("*   *  *   *     *    *   *   *  *   *");
move(9,112-x);
printw("*      *   *     *    *   *   *  *   *");
move(10,112-x);
printw("*      *   *     *    *   ****   *****");
move(11,112-x);
printw("*  **  *   *     *    *   *   *  *   *");
move(12,112-x);
printw("*   *  *   *  *  *    *   *   *  *   *");
move(13,112-x);
printw(" ***    ***    **    ***  *   *  *   *");
usleep(38000);
//refresh();
attron(COLOR_PAIR(2));
move(9,9+x);
printw("****starfleet****");
move(11,9+x);printw("***Incoming Message");
move(13,9+x);printw("****Gojira sighted in your sector");
attron(COLOR_PAIR(1));
move(7,157 - x);
printw("**    ");

move(7,150-x);printw("   ");
move(8,150-x); printw("   ");
move(9,150-x); printw("   ");
move(10,150-x); printw("   ");
move(11,150-x); printw("   ");
move(12,150-x); printw("   ");
move(13,150-x); printw("   ");

refresh();usleep(19000);
}
getch();

endwin();

}
