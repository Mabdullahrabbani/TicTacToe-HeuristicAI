#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
const int rows = 3;
const int columns = 3;
class Board
{
public:
    char Array[3][3];
    Board()
    {
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < columns; j++)
            {
                Array[i][j] = '-';
            }
        }
    }
    void Display()
    {
        string padding = "          ";
        cout << padding << "========================" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << padding << "|";
            for (int j = 0; j < columns; j++)
            {
                cout << "   " << Array[i][j] << "   |";
            }
            cout << "\n"
                << padding << "========================" << endl;
        }
    }
};
class Player
{

public:
    string Name;
    int PlayerNo;
    Player()
    {
        this->Name = "Computer";
    }
    void Input(int i)
    {
        this->PlayerNo = i;
        cout << " Player " << this->PlayerNo << " Please Enter your Name : ";
        cin >> this->Name;
    }
};
class Game
{
public:
    Player first;
    Player second;
    Player AiPlayer;
    Board board;
    int col;
    int row;
    static int Moves;
    Game()
    {
        col = 0;
        row = 0;
    }
    void Input()
    {
        while (true)
        {
            cout << "Please Enter the Row (1-3) : ";
            cin >> row;
            while (row < 1 || row > 3)
            {
                cout << "Please Enter the Row Again (1-3) : ";
                cin >> row;
            }
            cout << "Please Enter the Column (1-3) : ";
            cin >> col;
            while (col < 1 || col > 3)
            {
                cout << "Please Enter the column Again (1-3) : ";
                cin >> col;
            }

            if (this->Verify(row - 1, col - 1) == true)
            {
                this->Moves++;
                break;
            }
            cout << "Please See the table this Place is Already occupied ! " << endl;
        }
    }
    bool Verify(int rows, int cols)
    {
        return (this->board.Array[rows][cols] != 'X' && this->board.Array[rows][cols] != 'O');
    }
    void Placer(int id)
    {
        if (id == 1)
        {
            this->board.Array[row - 1][col - 1] = 'X';
        }
        else
        {
            this->board.Array[row - 1][col - 1] = 'O';
        }
    }
    bool WinChecker_Row()
    {
        bool checker = true;
        char CurrentElement;
        for (int i = 0; i < rows; i++)
        {
            checker = true;
            CurrentElement = this->board.Array[i][0];
            if (CurrentElement == '-')
                continue;
            for (int j = 1; j < columns; j++)
            {
                if (CurrentElement != this->board.Array[i][j])
                {
                    checker = false;
                    break;
                }
                CurrentElement = this->board.Array[i][j];
            }
            if (checker == true)
            {
                return true;
            }
        }
        return false;
    }
    bool WinChecker_Col()
    {
        bool checker = true;
        for (int i = 0; i < columns; i++)
        {
            checker = true;
            char CurrentElement = this->board.Array[0][i];
            if (CurrentElement == '-')
                continue;

            for (int j = 1; j < rows; j++)
            {
                if (CurrentElement != this->board.Array[j][i])
                {
                    checker = false;
                    break;
                }
            }
            if (checker == true)
            {
                return true;
            }
        }
        return false;
    }
    bool WinChecker_Diagonal()
    {
        int r = 1, c = 1;
        if (this->board.Array[0][0] == '-')
            return false;
        while (r < rows && c < columns)
        {
            if (this->board.Array[0][0] != this->board.Array[r][c])
                return false;
            r++;
            c++;
        }
        return true;
    }
    bool WinChecker_SecDiagonal()
    {
        int r = 0;
        int c = columns - 1;
        if (this->board.Array[r][c] == '-')
            return false;
        while (r < rows && c >= 0)
        {
            if (this->board.Array[0][columns - 1] != this->board.Array[r][c])
                return false;
            r++;
            c--;
        }
        return true;
    }
    bool CheckWin()
    {
        return (WinChecker_Row() || WinChecker_Col() || WinChecker_Diagonal() || WinChecker_SecDiagonal());
    }
    int Row_Searcher(char ch)
    {
        int Charcount = 0;
        int EmptyCount = 0;
        for (int i = 0; i < rows; i++)
        {
            EmptyCount = 0;
            Charcount = 0;
            for (int j = 0; j < columns; j++)
            {
                if (this->board.Array[i][j] == ch)
                    Charcount++;
                if (this->board.Array[i][j] == '-')
                    EmptyCount++;
            }
            if (Charcount == 2 && EmptyCount == 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
    int Col_Searcher(char ch)
    {
        int Charcount = 0;
        int EmptyCount = 0;
        for (int i = 0; i < rows; i++)
        {
            EmptyCount = 0;
            Charcount = 0;
            for (int j = 0; j < columns; j++)
            {
                if (this->board.Array[j][i] == ch)
                    Charcount++;
                if (this->board.Array[j][i] == '-')
                    EmptyCount++;
            }
            if (Charcount == 2 && EmptyCount == 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
    void Placer_Ai(int num, char ch)
    {
        if (ch == 'R')
        {
            for (int i = 0; i < rows; i++)
            {

                if (this->board.Array[num - 1][i] == '-')
                    this->board.Array[num - 1][i] = 'O';
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {

                if (this->board.Array[i][num - 1] == '-')
                    this->board.Array[i][num - 1] = 'O';
            }
        }
    }
    bool Diagonal_Searcher(char ch)
    {

        int Charcount = 0;
        int EmptyCount = 0;
        int r = 0, c = 0;
        while (r < rows && c < columns)
        {
            if (this->board.Array[r][c] == ch)
                Charcount++;
            if (this->board.Array[r][c] == '-')
                EmptyCount++;
            r++;
            c++;
        }
        r = 0, c = 0;
        if (Charcount == 2 && EmptyCount == 1)
        {
            while (r < rows && c < columns)
            {
                if (this->board.Array[r][c] == '-')
                {
                    this->board.Array[r][c] = 'O';
                    return true;
                }
                r++;
                c++;
            }
        }
        return false;
    }
    bool Sec_Diagonal_Searcher(char ch)
    {

        int Charcount = 0;
        int EmptyCount = 0;
        int r = 0, c = columns - 1;
        while (r < rows && c >= 0)
        {
            if (this->board.Array[r][c] == ch)
                Charcount++;
            if (this->board.Array[r][c] == '-')
                EmptyCount++;
            r++;
            c--;
        }
        r = 0;
        c = columns - 1;
        if (Charcount == 2 && EmptyCount == 1)
        {
            while (r < rows && c >= 0)
            {
                if (this->board.Array[r][c] == '-')
                {
                    this->board.Array[r][c] = 'O';
                    return true;
                }
                r++;
                c--;
            }
        }
        return false;
    }
    bool All_Functions(char ch)
    {
        int num;
        num = this->Row_Searcher(ch);
        if (num != -1)
        {
            this->Placer_Ai(num, 'R');
            return true;
        }
        num = this->Col_Searcher(ch);
        if (num != -1)
        {
            this->Placer_Ai(num, 'C');
            return true;
        }
        num = this->Diagonal_Searcher(ch);
        if (num == 1)
        {
            return true;
        }
        num = this->Sec_Diagonal_Searcher(ch);
        if (num == 1)
        {
            return true;
        }
        return false;
    }
    void Random()
    {
        int r = rand() % 3;
        int c = rand() % 3;
        bool flag = false;
        while (flag == false)
        {
            if (this->board.Array[r][c] == '-')
            {
                this->board.Array[r][c] = 'O';
                flag = true;
            }
            else
            {
                r = rand() % 3;
                c = rand() % 3;
            }
        }
    }
};
int Game::Moves = 0;
int main()
{
    srand(time(0));
    int Choice = 0;
    cout << "MultiPlayer(1)\n"
        << "SinglePlayer(2)\n"
        << "Please Enter Your Choice ! \n";
    cin >> Choice;
    Game game;
    Game* ptr = &game;
    if (Choice == 1)
    {
        ptr->first.Input(1);
        ptr->second.Input(2);
    }
    else
    {
        ptr->first.Input(1);
    }
    while (1)
    {
        system("cls");
        ptr->board.Display();
        cout << ptr->first.Name << " Now its Your Turn ! " << endl;
        ptr->Input();
        ptr->Placer(ptr->first.PlayerNo);
        if (ptr->CheckWin())
        {
            system("cls");
            ptr->board.Display();
            cout << "Congratulations " << ptr->first.Name << " Has Won the Game ! " << endl;
            break;
        }
        if (ptr->Moves == 9)
        {
            system("cls");
            ptr->board.Display();
            cout << "Match Tied ! " << endl;
            break;
        }
        if (Choice == 1)
        {
            system("cls");
            ptr->board.Display();
            cout << ptr->second.Name << " Now its Your Turn ! " << endl;
            ptr->Input();
            ptr->Placer(ptr->second.PlayerNo);
            ptr->board.Display();
            if (ptr->CheckWin())
            {
                system("cls");
                ptr->board.Display();
                cout << "Congratulations " << ptr->second.Name << " Has Won the Game ! " << endl;
                break;
            }
            if (ptr->Moves == 9)
            {
                system("cls");
                ptr->board.Display();
                cout << "Match Tied ! " << endl;
                break;
            }
        }
        else if (Choice == 2)
        {
            system("cls");
            ptr->board.Display();
            bool Checker = (ptr->All_Functions('O'));
            if (Checker == false)
            {
                Checker = ptr->All_Functions('X');
                if (Checker == true)
                {
                    ptr->Moves++;
                }
                else
                {
                    ptr->Random();
                    ptr->Moves++;
                }
            }
            else
            {
                ptr->Moves++;
            }
            if (ptr->CheckWin())
            {
                system("cls");
                ptr->board.Display();
                cout << "Congratulations Computer  Has Won the Game ! " << endl;
                break;
            }
            if (ptr->Moves == 9)
            {
                system("cls");
                ptr->board.Display();
                cout << "Match Tied ! " << endl;
                break;
            }
        }
    }

    return 0;
}