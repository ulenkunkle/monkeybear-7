#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "conio.h" /* needed for _getchar() */
#include <math.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
//#include "g4.h"
#define WIDTHz 10
#define HEIGHTz 10
#define VK_Q	0x051;
using namespace std;
//HANDLE wHnd; /* write (output) handle */
//HANDLE rHnd; /* read (input handle */
std::string line,text;
std::ifstream infile("C://python/info.txt");


char story_two( const char *prompt,int xx,int yy,int zz,int aa)
  {
  DWORD        mode;
  HANDLE       hstdin;//HANDLE wHnd;
  INPUT_RECORD inrec;
  DWORD        count;
  char         default_prompt[] = "Press the 'any' key...";
  char         result           = '\0';
  int xd;
    CHAR_INFO consoleBuffer[20];SMALL_RECT consoleWriteArea = {110, xx, 112, yy};COORD characterBufferSize = {aa,1};
	COORD characterPosition = {0,0};
    SMALL_RECT consoleWriteAreaG = {zz, xx, 150, yy};
    SMALL_RECT consoleWriteAreaH = {50, 11, 70, 13};
    CHAR_INFO consoleBufferG[aa];CHAR_INFO consoleBufferH[20];
  hstdin = GetStdHandle( STD_INPUT_HANDLE );
  if (hstdin == INVALID_HANDLE_VALUE
  || !GetConsoleMode( hstdin, &mode )
  || !SetConsoleMode( hstdin, 0 ))
    return result;	
  if (!prompt) prompt = default_prompt;
  for(xd=0;xd<aa;xd++)
  {
      consoleBufferG[xd].Char.AsciiChar = prompt[xd];consoleBufferG[xd].Attributes =  263;
      
  }
    /* Instruct the user */
  WriteConsoleOutput(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    consoleBufferG,
    characterBufferSize,
    characterPosition ,
    &consoleWriteAreaG
    );
  }
  
char call_stor(const char *file_n)
{
   string filename = file_n;
   char buff[2270];int xd;char buff_c[100];int xc;int xe=0;
   // Write to File
   ofstream fout(filename.c_str(),ios::out | ios::app );  // default mode is ios::out | ios::trunc
   if (!fout) {
      cerr << "error: open file for output failed!" << endl;
      abort();  // in <cstdlib> header
   }
   //fout << "apple" << endl;
  // fout << "orange" << endl;
  // fout << "banana" << endl;
   fout.close();
 
   // Read from file
   ifstream fin(filename.c_str());  // default mode ios::in
   if (!fin) {
      cerr << "error: open file for input failed!" << endl;
      abort();
   }
   char ch;int c = 0;
   while (fin.get(ch)) {  // till end-of-file
     // cout << ch;
     buff[c] = ch;c++;
	 
   }
   	 for(xd=1;xd<21;xd++){
	  //buff[c] = ch;c++;fin.get(ch);
	  for(xc=0;xc<99;xc++){//cout << xe <<  "  ";
	   buff_c[xc]= buff[(xe)];xe++;
        //if (buff[xe] == '\n') xc=129;
		}
	  story_two(buff_c,29+xd,31+xd,0,100);
	  
	 }
   
   fin.close();
  // return 0;
}