//
//  tctctoe.cpp
//  
//
//  Created by Susan Steinman on 4/22/14.
//
//

#include <iostream>
#include <ncurses.h>
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
    void moveCheck(int move);
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
        cout<<"X goes first"<<endl;
    }
    else {
        player='O';
        cout<<"O goes first"<<endl;
    }
        getMoves();
    
}

void Game::printBoard(){
    wmove(stdscr, 2, 0);
        cout<<" "<<position[0]<<" | "<<position[1]<<" | "<<position[2]<<endl;
        cout<<"------------\n";
        cout<<" "<<position[3]<<" | "<<position[4]<<" | "<<position[5]<<endl;
        cout<<"------------\n";
        cout<<" "<<position[6]<<" | "<<position[7]<<" | "<<position[8]<<endl;

}

void Game::getMoves(){
    int move;
    while (moveCounter<9){
        cout<<"Player "<<player<<": where would you like to move?"<<endl;
        cin>>move;
        moveCheck(move);
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
    cout<<"Cat's game"<<endl;
    playAgain();
}
void Game::moveCheck(int move){
    if( position[move-1]==' '){
        position[move-1]=player;
    }
    else{
        cout<<"Invalid move. Please enter an empty space."<<endl;
        cin>>move;
        moveCheck(move);
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
        cout<<winner<<" won this round."<<endl;
        if (winner=='X'){
            xWins++;
        }
        if (winner=='O'){
            oWins++;
        }
    playAgain();
}

void Game::playAgain(){
    cout<<"Would you like to play again? (y/n)"<<endl;
    
    char playAgainCheck;
    cin>>playAgainCheck;
    if (playAgainCheck=='y'|| playAgainCheck=='Y'){
        gameCounter++;
        Game gameCounter;
    }
    else if (playAgainCheck=='n'|| playAgainCheck=='N'){
    
        cout<<"X won "<<xWins<<" games. "<<endl;
        cout<<"O won "<<oWins<<" games. "<<endl;
        if (xWins>oWins){
            cout<<"Congratulations X."<<endl;
        }
        if (oWins>xWins){
            cout<<"Congratulations O."<<endl;
        }
        exit(1);
    }
    else{
        cout<<"Please enter a valid character"<<endl;
        playAgain();
    }
}



int main(){
   initscr();
    cout<<"Welcome to tic tac toe. "<<endl;
    
    cout<<" 1  | 2 | 3"<<endl;
    cout<<"------------\n";
    cout<<" 4 | 5 | 6"<<endl;
    cout<<"------------\n";
    cout<<" 7 | 8 | 9"<<endl;

    cout<<"Type the number of the square you would like to make your move in."<<endl;
    Game aGame;
    return 0;
}
