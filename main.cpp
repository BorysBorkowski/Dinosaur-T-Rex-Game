#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int height = 4;
const int width = 25;
int pos_x = 1;
int pos_y = 2;
int offset = 0;
int to_duck = 0;
bool to_jump = 0;
int turns = 0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void board_display_and_movement(int board[height][width])
{
        system("cls");
        if(to_duck == 0)
        {
            if(to_duck == 0)
         {
            board[pos_y][pos_x + offset] = 2;
            board[pos_y - 1][pos_x + offset] = 2;
        }
        else
        {
            board[pos_y][pos_x + offset] = 2;
        }
            board[pos_y - 1][pos_x + offset] = 2;
        }
        else
        {
            board[pos_y][pos_x + offset] = 2;
        }
        for(int i = 0; i < height; ++i)
        {
            for(int j = 0 + offset; j < 6 + offset; ++j)
            {
                if(board[i][j] == 0)
                {
                    SetConsoleTextAttribute(hConsole, 17);
                    cout << ' ';
                }
                if(board[i][j] == 1)
                {
                    SetConsoleTextAttribute(hConsole, 238);
                    cout << '1';
                }
                if(board[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole, 170);
                    cout << '2';
                }
                if(board[i][j] == 3)
                {
                    SetConsoleTextAttribute(hConsole, 34);
                    cout << '3';
                }
                cout << ' ';
            }
            cout << endl;
            SetConsoleTextAttribute(hConsole, 15);
            board[pos_y][pos_x + offset - 1] = 0;
            board[pos_y - 1][pos_x + offset - 1] = 0;
    }
    srand(time(NULL));
    int delay = rand()%400 + 500;
    Sleep(delay);
}

int main()
{
    HANDLE std_out = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coord;

    //system("cls");
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(std_out, coord);

    int board[height][width]=
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 0, 0},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

     while(true)
     {
        board_display_and_movement(board);
        if(kbhit())
        {
            switch(_getwch())
            {
            case 'w':
            {
                board[pos_y][pos_x + offset] = 0;
                pos_y -= 1;
                to_jump = 1;
                board_display_and_movement(board);
                board[pos_y + 1][pos_x + offset] = 2;
                board[pos_y - 1][pos_x + offset] = 0;
                break;
            }
            case 's':
            {
                board[pos_y - 1][pos_x + offset] = 0;
                to_duck = 1;
                board_display_and_movement(board);
                board[pos_y - 1][pos_x + offset] = 2;
                to_duck = 0;
                break;
            }
            }
        }
        offset += 1;
        if(to_jump == true)
        {
            turns += 1;;
        }
        if(turns == 2)
        {
            pos_y += 1;
            to_jump = false;
            turns = 0;
        }
     }
}
/*
No coz, nie udalo mi sie dokonczyc tego projektu na czas.
Zdecydowanie sie staralem, i tak ten kod pozostawia wiele do rzyczenia.
Gra niedziala tak jak zamierzalem, to znaczy: wyglada tragicznie, ma wiele bledow, brakuje miedzy innymi pterodaktymi
(co oznacza, ze kucanie jest bezu¿yteczne, rozgrywka trwa od 10-22s (a miala trwac nawet w niskonczonosc),
 a co najgorsze, niemozna mojej wersji porównac do orginalu. Czy jestem na siebie zły?
 Nie. Czy jestem zdeprymowany? Puki co nie. Pod czas tego projektu nauczylem sie nowych rzeczy.
 To nie jest moje ostatnie slowo :).
*/
