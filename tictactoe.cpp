#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void displayBoard(char board[][3]);
bool check(char board[][3], char move);
void playMove(char board[][3], char move);
void gotoxy(int x, int y);

int main()
{
    int index = 0;
    bool loop = false;
    char board[3][3] = {' '};
    while (true)
    {
        system("cls");
        displayBoard(board);
        cout << "Player One's turn" << endl;
        playMove(board, 'X');
        system("cls");
        displayBoard(board);
        if(check(board, 'X') == true)
        {
            cout << "Player 1 wins" << endl;
            getch();
            break;
        }
        if(index == 5)
        {
            cout << "Draw";
            break;
        }
        cout << "Player Two's turn" << endl;
        playMove(board, 'O');
        if(check(board, 'O') == true)
        {
            cout << "Player 2 wins" << endl;
            getch();
            break;
        }
        index++;
    }
}

void displayBoard(char board[][3])
{
    cout << endl << endl << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "                                                   ";
        for (int j = 0; j < 3; j++)
        {
            cout << "  ";
            cout << board[i][j];
            if (j != 2)
            {
                cout << " |";
            }
        }
        if (i == 2)
        {
            cout << endl;
            continue;
        }
        cout << endl
             << "                                                    _ _ _ _ _ _ _" << endl << endl;
    }
}

void playMove(char board[][3], char move)
{
    cout << "Enter the x-coordinates : ";
    int i, j;
    cin >> i;
    cout << "Enter the y-coordinates : ";
    cin >> j;
    if (board[i-1][j-1] == 'X' || board[i-1][j-1] == 'O')
    {
        cout << "You cannot play this move" << endl;
        getch();
        playMove(board, move);
    }
    else
    {
        board[i - 1][j - 1] = move;
    }
}

bool check(char board[][3], char move)
{
    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        if((board[i][0] == move && board[i][1] == move && board[i][2] == move) || (board[0][i] == move && board[1][i] == move && board[2][i] == move))
        {
            return true;
        }
    }   
    if((board[0][0] == move && board[1][1] == move && board[2][2] == move) || (board[0][2] == move && board[1][1] == move && board[2][0] == move))
    {
        return true;
    }
    return false;
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}