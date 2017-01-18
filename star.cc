#include <stdlib.h>
#include <iostream>
#include <curses.h>
#include <unistd.h>
//#include <asoundlib.h>
void intro();void begin();void game_over();

int main()
{
//int x=0;

system("play chant21.wav -q");

std::cout<< "llllllllllllllllllll";
initscr();
intro();begin();



}
