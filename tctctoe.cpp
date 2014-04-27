//
//  tctctoe.cpp
//  
//
//  Created by Susan Steinman on 4/22/14.
//
//
// versioned on github

#include <iostream>
#include <ncurses.h> //use -lncurses in command lines
using namespace std;

class Game{
private:
    
public:
    Game();
    char position[9];
    void printBoard();
    void getMoves();
    char checkWin();
    void printWin(char winner);
    void playAgain();
    void moveCheck(int aMove);
    static int xWins;
    static int oWins;
    static int gameCounter;
    int moveCounter;
    char player;
};

int Game::xWins=0;
int Game::oWins=0;
int Game::gameCounter=0;

Game::Game(){
    for (int i=0; i<9; i++){
        position[i]=' ';
    }
        moveCounter=0;
    if (gameCounter%2==0){
        player='X';
        //printw("X goes first\n");
    }
    else {
        player='O';
       // printw("O goes first\n");
    }
    refresh();
    //getch();
        getMoves();
    
}

void Game::printBoard(){
    int moveLine=(gameCounter*7)+1;
    wmove(stdscr, moveLine, 0);
    clrtobot();
    printw("\n %c",position[0]);
    printw(" | %c",position[1]);
    printw(" | %c",position[2]);
    printw("\n------------\n");
    printw(" %c",position[3]);
    printw(" | %c",position[4]);
    printw(" | %c",position[5]);
    printw("\n------------\n");
    printw(" %c",position[6]);
    printw(" | %c",position[7]);
    printw(" | %c",position[8]);
    printw("\n");
    refresh();

}

void Game::getMoves(){
    int aMove;
    while (moveCounter<9){
        printBoard();
        printw("Player %c", player);
        printw(": where would you like to move?\n");
        refresh();
        aMove=getch();
        aMove=aMove-'0';
        moveCheck(aMove);
        if (player=='X'){
            player='O';
        }
        else {player='X';}
        moveCounter++;
        printBoard();
        if (checkWin()=='Q'|| checkWin()==' '){
            getMoves();
        }
        else printWin(checkWin());
    }
    printw("Cat's game\n");
    playAgain();
}
void Game::moveCheck(int aMove){
    int y,x;
    if( position[aMove-1]==' '){
        position[aMove-1]=player;
    }
    else{
        printw("Invalid move. Please enter an empty space.\n");
        aMove=getch();
        getyx(stdscr, y, x);
        move(y-1, x);
        clrtobot();
        aMove=aMove-'0';
        moveCheck(aMove);
    }
    
}

char Game::checkWin(){
    if ((position[3]==position[4]&& position[4]==position[5])|| (position[1]==position[4]&& position[4]==position[7])|| (position[0]==position[4]&& position[4]==position[8])|| (position[2]==position[4]&& position[4]==position[6])){
        
        return position[4];
    }
    else if((position[0]==position[1]&&position[1]==position[2]) || (position[0]==position[3]&&position[3]==position[6]) ){
        return position[0];
    }
    
    else if((position[6]==position[7]&&position[7]==position[8])|| (position[2]==position[5]&&position[5]==position[8])){
        return position[8];
    }
    else return 'Q';
}

void Game::printWin(char winner){
    printw("%c",winner);
    printw(" won this round.\n");
        if (winner=='X'){
            xWins++;
        }
        if (winner=='O'){
            oWins++;
        }
    refresh();
    playAgain();
}

void Game::playAgain(){
    int y,x;
    printw("Would you like to play again? (y/n)\n");
    refresh();
    int playAgainCheck;
    playAgainCheck=getch();
    getyx(stdscr, y, x);
    move(y-2, x);
    clrtobot();
    if (playAgainCheck=='y'|| playAgainCheck=='Y'){
        gameCounter++;
        Game gameCounter;
    }
    else if (playAgainCheck=='n'|| playAgainCheck=='N'){
    
        printw("X won %i%",xWins);
        printw(" games. \n");
        printw("O won %i%",oWins);
        printw(" games. \n");
        if (xWins>oWins){
            printw("Congratulations X.\n");
        }
        if (oWins>xWins){
            printw("Congratulations O.\n");
        }
        refresh();
        printw("press any key to exit\n");
        getch();
        //timeout(3000);
        //printw("goodbye, anyway!");
        endwin();
        exit(1);
    }
    else{
        printw("Please enter a valid character\n");
        playAgain();
    }

}



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
