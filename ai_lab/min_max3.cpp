#include <iostream>
#include <vector>
#include <string>

using namespace std;
int turn = 1;
int MAX_DEPTH = 9;

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
    int count = 0;
    // Rows
    if ((board[0][0] * board[0][1] * board[0][2]) == product)
    {
        count++;
    }
    if ((board[1][0] * board[1][1] * board[1][2]) == product)
    {
        count++;
    }
    if ((board[2][0] * board[2][1] * board[2][2]) == product)
    {
        count++;
    }
    // Columns

    if ((board[0][0] * board[1][0] * board[2][0]) == product)
    {
        count++;
    }
    if ((board[0][1] * board[1][1] * board[2][1]) == product)
    {
        count++;
    }
    if ((board[0][2] * board[1][2] * board[2][2]) == product)
    {
        count++;
    }

    // Diagonal
    if ((board[0][0] * board[1][1] * board[2][2]) == product)
    {
        count++;
    }

    if ((board[0][2] * board[1][1] * board[2][0]) == product)
    {
        count++;
    }
    return count;
}

// Check the requiremnet of the below 4 functions

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

vector<int> move_generator(vector<vector<int>> board)
{
    vector<int> pos;

    if(checkWin(board,5) or checkWin(board,3)) 
        return pos;

    for (int i = 1; i <= 9; i++)
    {
        int row = (i - 1) / 3;
        int col = (i - 1) % 3;
        if (board[row][col] == 2)
        {
            pos.push_back(i);
        }
    }
    return pos;
}

int rating(vector<vector<int>> board, int move, int player)
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    int score = 0;
    // board[row][col] = player;
    int opponent = (player == 3) ? 5 : 3;

    if (checkWin(board, player))
    {
        score = 100;
    }
    else if (checkWin(board, opponent))
    {
        score = -100;
    }
    else if (possWin(board, player))
    {
        score = (possWin(board, player) * 10);
    }
    else if (possWin(board, opponent))
    {
        score = -(possWin(board, opponent) * 10);
    }
    else if (board[1][1] == player)
    {
        score += 3;
        if (board[0][1] == player)
            score += 2;
        if (board[1][0] == player)
            score += 2;
        if (board[1][2] == player)
            score += 2;
        if (board[2][1] == player)
            score += 2;
        if (board[0][0] == player)
            score += 1;
        if (board[0][2] == player)
            score += 1;
        if (board[2][0] == player)
            score += 1;
        if (board[2][2] == player)
            score += 1;
    }
    else
    {
        score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == player)
                {
                    score++;
                }
            }
        }
    }

    return score;
}

int min_max(vector<vector<int>> board, int player, int position, int depth, vector<int> &bestPath)
{
    if (depth >= MAX_DEPTH)
    {
        int score = rating(board, position, player);
        bestPath.clear();
        bestPath.push_back(position);
        return score;
    }
    else
    {
        vector<int> successors = move_generator(board);
        if (successors.empty())
        {
            int score = rating(board, position, player);
            bestPath.clear();
            bestPath.push_back(position);
            return score;
        }
        else
        {
            int bestScore = -100;
            vector<int> currentPath;
            int opponent = (player == 3) ? 5 : 3;

            for (int i = 0; i < successors.size(); i++)
            {
                vector<int> resultPath;

                auto new_board = board;
                int row = (successors.at(i) - 1) / 3;
                int col = (successors.at(i) - 1) % 3;
                new_board.at(row).at(col) = player;

                int result_succ = min_max(new_board, opponent, successors[i], depth + 1, resultPath);
                int new_val = -(result_succ);
                if (new_val > bestScore)
                {
                    bestScore = new_val;
                    currentPath = resultPath;
                }
                // displayBoard(new_board);
                // cout<<new_val<<endl;
            }

            currentPath.insert(currentPath.begin(), position);
            bestPath = currentPath;
            return bestScore;
        }
    }
}

void computerMove(vector<vector<int>> &board, int turn)
{
    int player = (turn % 2 == 0) ? 5 : 3;
    vector<int> successors = move_generator(board);
    int bestScore = -100;
    vector<int> path;
    vector<int> current_path;
    for (int i = 0; i < successors.size(); i++)
    {
        current_path.clear();
        auto new_board = board;
        int row = (successors.at(i) - 1) / 3;
        int col = (successors.at(i) - 1) % 3;
        new_board.at(row).at(col) = player;

        int result = min_max(new_board, 8 - player, successors[i], 1, current_path);
        displayBoard(new_board);
        cout<<-result<<endl;
        if (-(result) > bestScore)
        {
            bestScore = -(result);
            current_path.push_back(successors[i]);
            path = current_path;
        }

    }
    
    cout << "PATH" << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    go(board, turn, path[path.size() - 1]);
    return;
}

int main()
{

    // Intialising the Board Vector
    vector<vector<int>> board = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
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
            cout << "Enter a Valid Character!!";
        }
    }
    cout << "Its a DRAW!!" << endl;

    return 0;
}
