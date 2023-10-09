#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBoard(vector<vector<int>> board)
{
    cout << "-------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << "  | ";
        }
        cout << endl;
        cout << "-------------------" << endl;
    }
}

void userMove(vector<vector<int>> &board, int turn)
{
    bool valid = true;
    int move;
    while (valid)
    {
        cout << "Enter your move: (Valid Move : (1 - 9)): ";
        cin >> move;
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (move >= 1 && move <= 9 && (board[row][col] == 2))
        {
            cout << endl
                 << "USER MOVES: " << endl;
            if (turn % 2 != 0)
            {
                board[row][col] = 3;
            }
            else
            {
                board[row][col] = 5;
            }
            valid = false;
        }
        else
        {
            cout << "NOT a Valid Move!!!" << endl;
        }
    }
}

bool checkWin(vector<vector<int>> &board, int player)
{
    int product = player * player * player;
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] * board[i][1] * board[i][2]) == product)
        {
            return 1;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] * board[1][i] * board[2][i]) == product)
        {
            return 1;
        }
    }
    // Diagonals
    if ((board[0][0] * board[1][1] * board[2][2]) == product)
    {
        return 1;
    }
    if ((board[0][2] * board[1][1] * board[2][0]) == product)
    {
        return 1;
    }
    return 0;
}

int possWin(vector<vector<int>> &board, int player)
{
    int product = player * player * 2;
    // Rows
    if ((board[0][0] * board[0][1] * board[0][2]) == product)
    {
        if (board[0][0] == 2)
            return 1;
        else if (board[0][1] == 2)
            return 2;
        else
            return 3;
    }
    if ((board[1][0] * board[1][1] * board[1][2]) == product)
    {
        if (board[1][0] == 2)
            return 4;
        else if (board[1][1] == 2)
            return 5;
        else
            return 6;
    }
    if ((board[2][0] * board[2][1] * board[2][2]) == product)
    {
        if (board[2][0] == 2)
            return 7;
        else if (board[2][1] == 2)
            return 8;
        else
            return 9;
    }
    // Columns

    if ((board[0][0] * board[1][0] * board[2][0]) == product)
    {
        if (board[0][0] == 2)
            return 1;
        else if (board[1][0] == 2)
            return 4;
        else
            return 7;
    }
    if ((board[0][1] * board[1][1] * board[2][1]) == product)
    {
        if (board[0][1] == 2)
            return 2;
        else if (board[1][1] == 2)
            return 5;
        else
            return 8;
    }
    if ((board[0][2] * board[1][2] * board[2][2]) == product)
    {
        if (board[0][2] == 2)
            return 3;
        else if (board[1][2] == 2)
            return 6;
        else
            return 9;
    }

    // Diagonal
    if ((board[0][0] * board[1][1] * board[2][2]) == product)
    {
        if (board[0][0] == 2)
            return 1;
        else if (board[1][1] == 2)
            return 5;
        else
            return 9;
    }

    if ((board[0][2] * board[1][1] * board[2][0]) == product)
    {
        if (board[0][2] == 2)
            return 3;
        else if (board[1][1] == 2)
            return 5;
        else
            return 7;
    }

    return 0;
}

int make2(vector<vector<int>> &board)
{
    if (board[1][1] == 2)
    {
        return 5;
    }
    else if (board[0][1] == 2)
    {
        return 2;
    }
    else if (board[1][0] == 2)
    {
        return 4;
    }
    else if (board[1][2] == 2)
    {
        return 6;
    }
    else if (board[2][1] == 2)
    {
        return 8;
    }

    return 0;
}
int make3(vector<vector<int>> &board)
{
    if (board[1][1] == 2)
    {
        return 5;
    }
    else if (board[0][0] == 2)
    {
        return 1;
    }
    else if (board[0][2] == 2)
    {
        return 3;
    }
    else if (board[2][0] == 2)
    {
        return 7;
    }
    else if (board[2][2] == 2)
    {
        return 9;
    }

    return 0;
}

void go(vector<vector<int>> &board, int turn, int move)
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == 2)
    {
        if (turn % 2 != 0)
        {
            board[row][col] = 3;
        }
        else
        {
            board[row][col] = 5;
        }
    }
}

int findBlankSquare(vector<vector<int>> &board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 2)
            {
                int move = (i)*3 + j + 1;
                return move;
            }
        }
    }
    return 0;
}

void computerMove(vector<vector<int>> &board, int turn)
{
    if (turn == 1)
    {
        go(board, 1, 1);
    }
    else if (turn == 2)
    {
        if (board[1][1] == 2)
        {
            go(board, 2, 5);
        }
        else
        {
            go(board, 2, 1);
        }
    }
    else if (turn == 3)
    {
        if (board[2][2] == 2)
        {
            go(board, 3, 9);
        }
        else
        {
            go(board, 3, 3);
        }
    }
    else if (turn == 4)
    {
        if (possWin(board, 3) != 0)
        {
            go(board, 4, possWin(board, 3));
        }
        else
        {
            go(board, 4, make3(board));
        }
    }
    else if (turn == 5)
    {
        if (possWin(board, 5) != 0)
        {
            go(board, 5, possWin(board, 5));
        }
        else if (possWin(board, 3) != 0)
        {
            go(board, 5, possWin(board, 5));
        }
        else if (board[2][0] == 2)
        {
            go(board, 5, 7);
        }
        else
        {
            go(board, 5, 3);
        }
    }
    else if (turn == 6)
    {
        if (possWin(board, 5) != 0)
        {
            go(board, 6, possWin(board, 5));
        }
        else if (possWin(board, 3) != 0)
        {
            go(board, 6, possWin(board, 3));
        }
        else
        {
            go(board, 6, make2(board));
        }
    }
    else if (turn == 7 || turn == 9)
    {

        if (possWin(board, 3) != 0)
        {
            go(board, 5, possWin(board, 3));
        }
        else if (possWin(board, 5) != 0)
        {
            go(board, 5, possWin(board, 5));
        }
        else
        {
            int move = findBlankSquare(board);
            if (turn == 7)
                go(board, 7, move);
            else
                go(board, 9, move);
        }
    }
    else if (turn == 8)
    {
        if (possWin(board, 3) != 0)
        {
            go(board, 6, possWin(board, 3));
        }
        else if (possWin(board, 5) != 0)
        {
            go(board, 6, possWin(board, 5));
        }
        else
        {
            int move = findBlankSquare(board);
            go(board, 8, move);
        }
    }
}

int main()
{

    // Intialising the Board Vector
    vector<vector<int>> board = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
    int turn = 1;
    // Display the board
    cout << endl;
    displayBoard(board);
    cout << endl
         << endl;

    bool playFirst = true;
    char ch;
    while (playFirst)
    {
        cout << "Do you want to play First ?? (y/n): ";
        cin >> ch;
        if (ch == 'N' || ch == 'n')
        {
            while (turn < 8)
            {
                cout << endl
                     << endl
                     << "COMPUTER MOVES: " << endl;
                computerMove(board, turn);
                displayBoard(board);
                if (checkWin(board, 3))
                {
                    cout << endl
                         << "COMPUTER WINS!!!" << endl;
                    return 0;
                }
                turn++;
                cout << endl
                     << endl;
                userMove(board, turn);
                displayBoard(board);
                if (checkWin(board, 5))
                {
                    cout << endl
                         << "USER WINS!!!" << endl;
                    return 0;
                }
                turn++;
            }
            cout << endl
                 << endl
                 << "COMPUTER MOVES: " << endl;
            computerMove(board, turn);
            displayBoard(board);
            if (checkWin(board, 3))
            {
                cout << endl
                     << "COMPUTER WINS!!!" << endl;
                return 0;
            }
            playFirst = false;
        }
        else if (ch == 'Y' || ch == 'y')
        {
            while (turn < 8)
            {
                cout << endl
                     << endl;
                userMove(board, turn);
                displayBoard(board);
                if (checkWin(board, 3))
                {
                    cout << endl
                         << "USER WINS!!!" << endl;
                    return 0;
                }
                turn++;
                cout << endl
                     << endl
                     << "COMPUTER MOVES: " << endl;
                computerMove(board, turn);
                displayBoard(board);
                if (checkWin(board, 5))
                {
                    cout << "COMPUTER WINS!!!" << endl;
                    return 0;
                }
                turn++;
            }
            userMove(board, turn);
            displayBoard(board);
            if (checkWin(board, 3))
            {
                cout << "USER WINS!!!" << endl;
                return 0;
            }
            playFirst = false;
        }
        else
        {
            cout << "Enter a Valid Character!!" << endl;
        }
    }
    cout << "Its a DRAW!!" << endl;

    return 0;
}
