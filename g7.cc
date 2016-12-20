#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "conio.h" /* needed for _getchar() */
#include <math.h>
#include <Windows.h>
#include <iostream>
#include <sstream>
//#include "g4.h"
#define WIDTHz 10
#define HEIGHTz 10
#define VK_Q	0x051;

HANDLE wHnd; /* write (output) handle */
HANDLE rHnd; /* read (input handle */


char story_two( const char *prompt,int xx,int yy,int zz,int aa);
char call_stor(const char *file_n);

int N_Zone = 9000;
char line_3[] = "Screens Down--97% Phasers Down  88% // Torpedoes none // 10forward - empty        ";
char line_4[] = "Klingons off starboard bow Romulans off port bow //Borg 10 parsec /warp 11.5";
char line_5[] = "Klingons fire Photon Torodoes ///Warp breach// **ABANDON SHIP**ABANDON SHIP**";
char line_6[] = "Engineering Deck sustained slight damage --- bridge Undamaged --- transporter down";
CHAR_INFO consoleBufferC[WIDTHz * HEIGHTz];
CHAR_INFO consoleBufferD[WIDTHz * HEIGHTz];
CHAR_INFO consoleBufferE[WIDTHz * HEIGHTz];
CHAR_INFO consoleBufferF[WIDTHz * HEIGHTz];

char stk_error( const char *prompt,int zx,int zy,int ab,int xc)
  {
      
  DWORD        mode;
  HANDLE       hstdin;//HANDLE wHnd;
  INPUT_RECORD inrec;
  DWORD        count;
  char         default_prompt[] = "Press the 'any' key...";
  char         result           = '\0';
  int xd;
    CHAR_INFO consoleBuffer[20];SMALL_RECT consoleWriteAreaI = {ab, zx, xc, zy};COORD characterBufferSize = {20,1};
    COORD characterPosition = {0,0};CHAR_INFO consoleBufferI[20];
  if (!prompt) prompt = default_prompt;
  for(xd=0;xd<19;xd++)
  {
      consoleBufferI[xd].Char.AsciiChar = prompt[xd];consoleBufferI[xd].Attributes =  263;
      
  }
   WriteConsoleOutput(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    consoleBufferI,
    characterBufferSize,
    characterPosition ,
    &consoleWriteAreaI
    );
  }  
 
char story_one( const char *prompt,int xx,int yy,int zz)
  {
  DWORD        mode;
  HANDLE       hstdin;//HANDLE wHnd;
  INPUT_RECORD inrec;
  DWORD        count;
  char         default_prompt[] = "Press the 'any' key...";
  char         result           = '\0';
  int xd;
    CHAR_INFO consoleBuffer[20];SMALL_RECT consoleWriteArea = {100, xx, 112, yy};COORD characterBufferSize = {68,1};
	COORD characterPosition = {0,0};
    SMALL_RECT consoleWriteAreaG = {zz, xx, 110, yy};
    SMALL_RECT consoleWriteAreaH = {50, 11, 70, 13};
    CHAR_INFO consoleBufferG[69];CHAR_INFO consoleBufferH[20];
  hstdin = GetStdHandle( STD_INPUT_HANDLE );
  if (hstdin == INVALID_HANDLE_VALUE
  || !GetConsoleMode( hstdin, &mode )
  || !SetConsoleMode( hstdin, 0 ))
    return result;	
  if (!prompt) prompt = default_prompt;
  for(xd=0;xd<58;xd++)
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
 
char pressanykey( const char *prompt,int xx,int yy)
  {
  DWORD        mode;
  HANDLE       hstdin;//HANDLE wHnd;
  INPUT_RECORD inrec;
  DWORD        count;
  char         default_prompt[] = "Press the 'any' key...";
  char         result           = '\0';
  int xd;
    CHAR_INFO consoleBuffer[20];SMALL_RECT consoleWriteArea = {100, xx, 112, yy};COORD characterBufferSize = {68,1};
    COORD characterPosition = {0,0};
    SMALL_RECT consoleWriteAreaG = {50, xx, 110, yy};
    SMALL_RECT consoleWriteAreaH = {50, 11, 70, 13};
    CHAR_INFO consoleBufferG[69];CHAR_INFO consoleBufferH[20];
  /* Set the console mode to no-echo, raw input, */
  /* and no window or mouse events.              */
  hstdin = GetStdHandle( STD_INPUT_HANDLE );
  if (hstdin == INVALID_HANDLE_VALUE
  || !GetConsoleMode( hstdin, &mode )
  || !SetConsoleMode( hstdin, 0 ))
    return result;

  if (!prompt) prompt = default_prompt;
  for(xd=0;xd<58;xd++)
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

  FlushConsoleInputBuffer( hstdin );
  for(xd=0;xd<15;xd++)
  {
      
  /* Wait for and get a single key PRESS */
  do ReadConsoleInput( hstdin, &inrec, 1, &count );
  while ((inrec.EventType != KEY_EVENT) || !inrec.Event.KeyEvent.bKeyDown);

  /* Remember which key the user pressed */
  result = inrec.Event.KeyEvent.uChar.AsciiChar;
  
  consoleBuffer[xd].Char.AsciiChar = result;consoleBuffer[xd].Attributes =  264;
  /* Wait for and get a single key RELEASE */
  do ReadConsoleInput( hstdin, &inrec, 1, &count );
  
  while ((inrec.EventType != KEY_EVENT) || inrec.Event.KeyEvent.bKeyDown);
  //WriteConsoleOutput(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
  /* Restore the original console mode */
  WriteConsoleOutput(GetStdHandle( STD_OUTPUT_HANDLE ), consoleBuffer,characterBufferSize,characterPosition , &consoleWriteArea);
  }
  
  SetConsoleMode( hstdin, mode );

  return result;
  }

void look()
{
  int long x,i;bool  done = FALSE; int long * address;char mastermind[13];
  char *d = &(line_4[0]);char *e;char *y;
  std::string s,s2;
  std::stringstream out;
  out << d;
  s = out.str();
  COORD characterBufferSize = {12, 1};
  COORD characterPosition = {0, 0};
  SMALL_RECT consoleWriteArea = {100, 5, 112, 7};
  SMALL_RECT consoleWriteAreaB = {100, 3, 112, 5};
  SMALL_RECT consoleWriteAreaC = {100, 7, 112, 9};
  CHAR_INFO consoleBuffer[WIDTHz * HEIGHTz];
  CHAR_INFO consoleBufferB[WIDTHz * HEIGHTz];
  CHAR_INFO consoleBufferC[WIDTHz * HEIGHTz];
  address = &i;
  for (x = 0; x < 7; ++x){
      
  consoleBuffer[x].Char.AsciiChar = *d;consoleBuffer[x].Attributes =  225;d++;} 
  while(!done){
  WriteConsoleOutput(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea); 
  
  if(GetAsyncKeyState(VK_DOWN))
  pressanykey("begin debugging ::::: enter machine code here===>",11,13);stk_error("xxxx xxxxxxxxxx",15,17,50,73);
  if(GetAsyncKeyState(VK_UP))
  pressanykey("debugging FAILED :::: enter machine code here===>",13,15);stk_error("STACK OVERFLOW",15,17,50,72);
  if(GetAsyncKeyState(VK_RIGHT))
    {d++;Sleep(60);e=d;
     for (x = 0; x < 13; ++x){
         
        std::stringstream out;out << address;s = out.str();mastermind[x] =s[x];printf( " mastermind  Guess  %s",mastermind);std::cout<<mastermind;
       consoleBufferB[x].Char.AsciiChar = s[x];consoleBufferB[x].Attributes =  225;address++;
       consoleBuffer[x].Char.AsciiChar = *e;consoleBuffer[x].Attributes =  225;e++;stk_error("xxxx XXXX xx",15,17,20,50);
       //if(x>3 && x<10){
       std::stringstream out2;out2 << *d;s2 = out2.str(); 
       consoleBufferC[x].Char.AsciiChar = s2[x];consoleBufferC[x].Attributes =  225;stk_error("***WARNING***",13,15,20,50);
       }
        WriteConsoleOutput(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
        WriteConsoleOutput(wHnd, consoleBufferB, characterBufferSize, characterPosition, &consoleWriteAreaB);
        WriteConsoleOutput(wHnd, consoleBufferC, characterBufferSize, characterPosition, &consoleWriteAreaC);
        }
   if(GetAsyncKeyState(VK_LEFT))
    {d--;Sleep(60);e=d;
     for (x = 0; x < 12; ++x){
         std::stringstream out;out << address;s = out.str();
         consoleBufferB[x].Char.AsciiChar = s[x];consoleBufferB[x].Attributes =  225;address--;
       consoleBuffer[x].Char.AsciiChar = *e;consoleBuffer[x].Attributes =  225;e++;}
        WriteConsoleOutput(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
        WriteConsoleOutput(wHnd, consoleBufferB, characterBufferSize, characterPosition, &consoleWriteAreaB);
        }     
  if(GetKeyState('Z'))
           done = TRUE;
  if(GetKeyState('K'))
	       story_one("Galactic Messaging Down.....call back later",19,21,0);
  if(GetKeyState('J'))
	       story_one("Galactic Message.... someone named Palpatine calling,,,",29,30,0);   
  if(GetKeyState('I'))
	       story_two("Galactic Message.... Borg scouts sighted in your sector,,,",31,32,0,70);  
  if(GetKeyState('U'))
	       call_stor("info.txt"); 
  if(GetKeyState('Y'))
	       call_stor("info_2.txt");
  if(GetKeyState('T'))
	       call_stor("info_3.txt");   
  if(GetKeyState('7'))
	       call_stor("info_4.txt");     
	   
}}

void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;

// Get the number of character cells in the current buffer. 

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

void scroll(char a[])
{
    int x,y;
    char one_line[] = " MESSAGE FROM STARFLEET--- DO NOT ENTER THE NEUTRAL ZONE AT THIS TIME..";
    
    char parsec[20];
    
    //std::stringstream input;
    //std::itoa (i,parsec,10);
    std::string s;
    std::stringstream out;
    out << N_Zone;
    s = out.str();
    char two_line[] = " ***WARNING*** ENTERING NEUTRAL ZONE IN         PARSECS";//+parsec[];  //+ std::to_string(N_Zone);
    COORD characterBufferSize = {80, 1};
    COORD characterPosition = {0, 0};
    SMALL_RECT consoleWriteArea = {0, 0, 70, 2};
    SMALL_RECT consoleWriteAreaB = {0, 10, 70, 12};
    SMALL_RECT consoleWriteAreaC = {0, 20, 80, 22};
    SMALL_RECT consoleWriteAreaD = {0, 22, 82, 24};
    SMALL_RECT consoleWriteAreaE = {0, 24, 82, 26};
    SMALL_RECT consoleWriteAreaF = {0, 25, 82, 26};
    CHAR_INFO consoleBuffer[WIDTHz * HEIGHTz];
    CHAR_INFO consoleBufferB[WIDTHz * HEIGHTz];
    
    
    for (x = 0; x < 80; ++x){
         consoleBuffer[x].Char.AsciiChar = one_line[x];consoleBuffer[x].Attributes =  225;
         consoleBufferB[x].Char.AsciiChar = two_line[x];consoleBufferB[x].Attributes =  225;
         consoleBufferC[x].Char.AsciiChar = line_3[x];consoleBufferC[x].Attributes =  244;
         consoleBufferD[x].Char.AsciiChar = line_4[x];consoleBufferD[x].Attributes =  229;
         consoleBufferE[x].Char.AsciiChar = line_5[x];consoleBufferE[x].Attributes =  244;
         consoleBufferF[x].Char.AsciiChar = a[x];consoleBufferF[x].Attributes =  244;
         if ((x>40) && (x<45)){consoleBufferB[x].Char.AsciiChar = s[x-41];consoleBufferB[x].Attributes =  225;
         }
         }
    for (y=0;y<172;y++)  { if(GetAsyncKeyState(VK_RIGHT))exit;
      SMALL_RECT consoleWriteArea = {y, 0, 70+y, 2+y};
      WriteConsoleOutput(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
      Sleep(92);
      
      WriteConsoleOutput(wHnd, consoleBufferB, characterBufferSize, characterPosition, &consoleWriteAreaB);
      WriteConsoleOutput(wHnd, consoleBufferC, characterBufferSize, characterPosition, &consoleWriteAreaC);
      WriteConsoleOutput(wHnd, consoleBufferD, characterBufferSize, characterPosition, &consoleWriteAreaD);
      WriteConsoleOutput(wHnd, consoleBufferE, characterBufferSize, characterPosition, &consoleWriteAreaE);
      WriteConsoleOutput(wHnd, consoleBufferF, characterBufferSize, characterPosition, &consoleWriteAreaF);
      for (x=41;x<45;x++){std::stringstream out;out << N_Zone;s = out.str(); consoleBufferB[x].Char.AsciiChar = s[x-41];consoleBufferB[x].Attributes =  225; }N_Zone--;
      }
      //consoleBuffer[x + WIDTHz].Attributes =  156+fff;fff++;
    //}//
}


int main(int argc, char * argv[])
{
   bool  done = FALSE;
   int x=1;int y = 1;
   int fff=1;
   
   printf("\n\n\n\n\n\n\n\n\n\n ...screens down Captain ,,, continue???");getchar();
   printf("\n\n\n\n\n\n\n ...Torpedoes,Phasors,Navigation and life Support down Captain ,,, continue???");getchar();
   printf("\n\n\n\n\n ... fine ,,, incoming message sir shall I play it Captain ,,, ");getchar();
   HANDLE hStdout;
   SMALL_RECT windowSize = {0, 0, 169, 134};
   hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD bufferSize = {170, 135};
   
  /* Setting up different variables for passing to WriteConsoleOutput */
  COORD characterBufferSize = {10, 10};
  COORD characterPosition = {0, 0};
  SMALL_RECT consoleWriteArea = {0, 0, 10, 10};
  
  CHAR_INFO characterQ;
  characterQ.Char.AsciiChar = 'Q';
  characterQ.Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN |
                          FOREGROUND_INTENSITY;
  CHAR_INFO consoleBuffer[WIDTHz * HEIGHTz];
  
  wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
  rHnd = GetStdHandle(STD_INPUT_HANDLE); 
    SetConsoleTitle("Our shiny new title!");
  SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
  SetConsoleScreenBufferSize(wHnd, bufferSize);
  
  cls(hStdout);
   scroll(line_6);printf("\n...sorry sir,,,Ship destroyed by Klingons Borg and Romulans goodbye Captain Dunsill,,, ");getchar();
   printf("\n...wait,,,wait im getting a message,,,ships computer in error ,,, battle bridge remains... \n");
   printf(".. you must get computers back online to survive,,,start with hacking the output buffers\n");
   printf(".. use the arrow keys(up/down/rt/lf)to show contents of buffer here(careful of stackdumps)----->");
   getchar();scroll(line_6);look();
   getchar();
}
