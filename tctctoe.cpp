
//
//  tctctoe.cpp
//  tctctoe1
//
//  Created by Susan Steinman on 4/28/14.
//  
//

#include <iostream>
#include <tctctoe.h>
#include <ncurses.h> //use -lncurses in command lines
using namespace std;



int main(){
    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, true);
    
    printw("Welcome to tic tac toe. \n");
    
    printw("\n 1  | 2 | 3\n");
    printw("------------\n");
    printw(" 4 | 5 | 6\n");
    printw("------------\n");
    printw(" 7 | 8 | 9\n");
    
    printw("Type the number of the square you would like to make your move in.\n Press any key to start playing!\n");
    refresh();
    getch();
    Game aGame;
    endwin();
    return 0;
}