#include <iostream>
using namespace std;
const int N = 8;
bool issafe(int board[N][N], int i, int j)
{

  for (int k = 0; k <= i; k++)
  {

    if (board[k][j] == 1)
    {
      return false;
    }
  }
  int x = i;
  int y = j;
  while (x >= 0 && y >= 0)
  {
    if (board[x][y] == 1)
      return false;
    x--;
    y--;
  }
  x = i;
  y = j;
  while (x >= 0 && y < N)
  {
    if (board[x][y] == 1)
      return false;
    x--;
    y++;
  }
  return true;
}
bool solve(int board[N][N], int CurrRow)
{
  // Base case
  if (CurrRow == N)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n\n";
    return true;
  }

  // Recursive case
  for (int col = 0; col < N; col++)
  {
    if (issafe(board, CurrRow, col))
    {
      board[CurrRow][col] = 1;
      bool isSuccess = solve(board, CurrRow + 1);
      // if (isSuccess)
      //   return true;
      board[CurrRow][col] = 0; // Backtrack
    }
  }
  // Tried all possibles columns of current row
  return false;
}
int main()
{

  int board[N][N];
  memset(board, 0, sizeof(board));
  solve(board, 0);
}
