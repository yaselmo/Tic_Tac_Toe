#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
const char player = 'X';
const char computer = 'O';

void resetBoard() ;
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main(){
    char winner=' ';
    char playAgain = ' ';

    do{
        char winner=' ';
        char playAgain = ' ';
        resetBoard();

    while(winner == ' '){
        printBoard();
        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
    }
    printBoard();
    printWinner(winner);

    printf("\nDo you want to play again? (y/n): ");
    
    scanf(" %c", &playAgain);
    playAgain = toupper(playAgain);
    }while(playAgain == 'Y');

    printf("Goodbye\n");
    
    return 0;
    }


void resetBoard(){
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
    }

    }
}

void printBoard(){
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    
}

int checkFreeSpaces(){
    int freeSpaces = 9;
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
    }

    }
    return freeSpaces;
}

void playerMove(){
    int x;
    int y;
    do{
        printf("Enter the coordinates: ");
        scanf("%d %d", &x, &y);
    }while(x<1 || x>3 || y<1 || y>3 || board[x-1][y-1] != ' ');
    board[x-1][y-1] = player;
}

void computerMove(){
    //create random numbers
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpaces() > 0){
    do{
        x = rand() % 3;
        y = rand() % 3;
    }while(board[x][y] != ' ');
    board[x][y] = computer;
    }else{
        printWinner(' ');
    }
}

char checkWinner(){
    //check rows
    for(int i =0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int i =0; i<3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return board[0][i];
        }
    }
    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }
    return ' ';
}

void printWinner(char winner){
    if (winner == player){
        printf("You won\n");
    }else if (winner == computer){
        printf("You lost\n");
    }else{
        printf("Tie\n");
    }
}