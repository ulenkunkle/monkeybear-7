#include <stdlib.h>
#include <iostream>
#include <curses.h>
#include <unistd.h>
//#include <asoundlib.h>

void box()
{
init_pair(6,COLOR_RED,COLOR_YELLOW);
int x,y;
attron (COLOR_PAIR(6));
for(x=0;x<5;x++){
for(y=0;y<167;y++){
move(x,y);printw(" ");move(x+45,y);printw(" ");
}
}
for(x=0;x<49;x++){
for(y=0;y<3;y++){
move(x,y);printw(" ");move(x,y+167);printw(" ");
}}


}


void game_over()
{
box();
init_pair(4,COLOR_YELLOW, COLOR_BLACK);
system("play klaxon1.wav -q");
attron (COLOR_PAIR(4));
move(18,30);
printw("      ***    ***   *   *  *****    ***   *   *  *****  ****     *   *   ***   *   *   ");move(19,30);
printw("     *      *   *  ** **  *       *   *  *   *  *      *   *    ** **  *   *  *   *   ");move(20,30);
printw("     *      *   *  * * *  *       *   *  *   *  *      *   *    * * *  *   *  **  *   ");move(21,30);
printw("     *      *   *  *   *  ****    *   *  *   *  ****   *   *    *   *  *   *  * * *   ");move(22,30);
printw("     * ***  *****  *   *  *       *   *  *   *  *      ****     *   *  *****  *  **   ");move(23,30);
printw("     *   *  *   *  *   *  *       *   *   * *   *      *   *    *   *  *   *  *   *   ");move(24,30);
printw("      ***   *   *  *   *  *****    ***     *    *****  *   *    *   *  *   *  *   *   ");
getch();
}




void intro()
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
system("play klaxon1.wav -q");

getch();

//endwin();
}
void  begin()
{
init_pair(3,COLOR_BLUE, COLOR_WHITE);
init_pair(2,COLOR_BLUE, COLOR_YELLOW);
init_pair(4,COLOR_YELLOW, COLOR_BLACK);
init_pair(5,COLOR_RED,COLOR_BLACK);
attron(COLOR_PAIR(3));
char ans;

move(16,4);
printw("JOURNEY BEGINS:  GOJIRA HAS ESCAPED EARTH  AND  ENTERS TRANSWARP SPACE");
move(18,4);
printw("your mission(((should you decide to accept)))is to find him capture Gojira alive");
move(20,4);
printw("and return hin to starbase...");
attron(COLOR_PAIR(2));
move(16,110);
printw("Gojira activating long range sensors");
move(18,110);printw("You have been seen....");
move(20,110);printw("..activate cloak sir...???   y/n   ");
ans = getch();
if (ans == 'y'){move(22,110);printw("....OK....");
attron(COLOR_PAIR(3));
move(22,4);printw("mode:::SILENT RUNNING::scan:::GOJIRA 22000 kalicams & CLOSING");
getch();}
else game_over();
attron(COLOR_PAIR(2));
move(24,110);printw("ACTiVATE DEEP SPACE SENSORS ???::>    ");
ans = getch();
if (ans == 'y'){move(24,146);printw(":::SENSORS ACTiVE::");
attron(COLOR_PAIR(3));
move(24,4);printw("GOJIRA ATTACKS Battleship Nostromo");getch();}
else game_over();
move(26,4);printw("MESSAGE FROM SHUTTLE_DRONE #3-->>ok?   ");ans=getch();
if (ans =='y'){attron(COLOR_PAIR(2));move(26,110);printw("Nostromo attacks GOJIRA");}
else game_over();
getch();
attron(COLOR_PAIR(5));move(28,4);printw("Gojira absorbed into Borg/Alien collective");getch();
attron(COLOR_PAIR(4));move(28,110);printw("GOJIRA FORCED TO CHANGE NAME TO GODZILLA BY BORG");getch();
move(30,4);printw("Godzilla changes his name to Space_Godzilla and along with his clone Mecha_Space_Godzilla ,, escapes the Borg as they chew and burn");
move(31,4);printw("huge chunks out of the side of the BORG CUBE allowing them to getaway without being chased");
move(32,4);printw("Space_Godzilla can only achieve warp speeds by merging with Mecha_warp_Godzilla and Mecha_Space_Godzilla");
move(33,4);printw("forming  one unit capable of speeds of warp 13  or higher....Space monsters are believed to have originated from somewhere in the Mustafar system");
move(34,4);printw("After they evolved space travel they spread through the galaxy eating everything in sight___>IF YOU DONT BELIEVE US JUST ASK THEM");
move(35,4);printw("SPACE_GODZILLA::: I'm not answering anybody");move(36,4);printw("MONKEYBEAR:::Well guess what stupid space monster we dont care");
move(37,4);printw("SPACE_GODZILLA:::Why should I care what a stupid little space monkey thinks anyway");move(38,4);
printw("MONKEYBEAR::: Well guess what  ,,, no one cares about space monsters anyway");move(39,4);
printw("SPACE_GODZILLA::::YOULL CARE PLENTY WHEN I START EATING ALL YOUR FRIENDS...HOW BOUT THAT SPACE MONKEY BOY"); move(40,4);
printw("MONKEYBEAR:::: YOU BETTER NOT KELLYBEAR KNOWS ALL ABOUT YOU AND YOULL BE IN TROUBLE <<< BIG TROUBLE !!!!");move(41,4);
printw("Space_Godzilla:::::: Forget you Monkeybear   ...  i got stuff to do   ... more important stuff than you  ...");move(42,4);
attron(COLOR_PAIR(5));printw("FOLLOW SPACE___GODZILLAS    NEXT ADVENTURE ?????   ");
ans = getch();printw(" ***STAY TUNED FOR MONKEYBEARS NEXT ADVENTURE   ");getch();game_over();
endwin();
}

