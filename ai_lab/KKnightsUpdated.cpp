#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
using namespace std::chrono;

int m, n, k;
int counter = 1;

void display_board(char** board)
{
	for (int i = 0; i < 4*m + 1; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < m; i++)
	{
		cout << "| ";
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " | ";
		}
		cout << endl;
		for (int i = 0; i < 4*m + 1; i++)
		cout << "-";
		cout << "\n";
	}
	cout << endl;
}

void attacking_squares(int i, int j, char A, char** board)
{
	if ((i + 2) < m && (j - 1) >= 0)
		board[i + 2][j - 1] = A;
	if ((i - 2) >= 0 && (j - 1) >= 0)
		board[i - 2][j - 1] = A;
	if ((i + 2) < m && (j + 1) < n)
		board[i + 2][j + 1] = A;
	if ((i - 2) >= 0 && (j + 1) < n)
		board[i - 2][j + 1] = A;
	if ((i + 1) < m && (j + 2) < n)
		board[i + 1][j + 2] = A;
	if ((i - 1) >= 0 && (j + 2) < n)
		board[i - 1][j + 2] = A;
	if ((i + 1) < m && (j - 2) >= 0)
		board[i + 1][j - 2] = A;
	if ((i - 1) >= 0 && (j - 2) >= 0)
		board[i - 1][j - 2] = A;
}

int canPlace(int i, int j, char** board)
{
	if (board[i][j] == '-')
		return 1;
	else
		return 0;
}

void placeKnight(int i, int j, char K, char A, char** board, char** new_board)
{
	for (int a = 0; a < m; a++)
		for (int b = 0; b < n; b++)
			new_board[a][b] = board[a][b];

	new_board[i][j] = K;
	attacking_squares(i, j, A, new_board);
}

int safespots(char** board)
{
    int safespots = 0;
    for (int i = 0; i < m; i++)
    {
		for (int j = 0; j < n; j++)
        {
			if(board[i][j]=='-')
				safespots++;
		}
	}
	return safespots;
}

void KKnights(int k, int sti, int stj, char** board)
{
	if (k == 0)
	{
		cout << "Solution "<<counter<<" is :\n";
		display_board(board);
		counter++;
	}

	else
	{
		for(int i = sti; i < m; i++)
		{
			for(int j = stj; j < n; j++)
			{
				if(canPlace(i, j, board))
				{
					char** new_board = new char*[m];

					for(int c = 0; c < m; c++)
						new_board[c] = new char[n];
					
					placeKnight(i, j, 'K', 'A', board, new_board);

					if(k <= safespots(board))
						KKnights(k - 1, i, j, new_board);

					for (int c = 0; c < m; c++)
						delete[] new_board[c];
					delete[] new_board;
				}
			}
			stj = 0;
		}
	}
}

int main()
{
	cout << "Enter the dimensions of the board : ";
    cin >> m >> n;
    cout << "Enter the number of knights to be placed : ";
    cin >> k;

	char** board = new char*[m];
	for(int i = 0; i < m; i++)
		board[i] = new char[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = '-';

	auto start = high_resolution_clock::now();
	if(k <= safespots(board)/2 + 1)
		KKnights(k, 0, 0, board);
	auto stop = high_resolution_clock::now();

	cout << endl << "Total number of solutions are : " << counter - 1 << "\n";
	auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken is "<< fixed << duration.count() << setprecision(5) << " milliseconds." <<endl;
	getch();
	return 0;
}