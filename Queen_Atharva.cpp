#include <bits/stdc++.h>
using namespace std;

bool clash(vector<vector<int>> &board, int n, int i, int c)
{

  for (int k = c - 1; k >= 0; k--)
  {
    if (board[i][k])
    {
      return true;
    }
  }

  int p = i - 1;
  int q = c - 1;
  while (p >= 0 && q >= 0)
  {
    if (board[p][q])
    {
      return true;
    }
    p--;
    q--;
  }

  p = i + 1;
  q = c - 1;

  while (p < n && q >= 0)
  {
    if (board[p][q])
    {
      return true;
    }
    p++;
    q--;
  }

  return false;
}

bool fn(vector<vector<int>> &board, int n, int c)
{
  // cout<<"D";
  int i = 0;
  if (c == n)
  {
    return true;
  }
  while (i < n)
  {
    if (!clash(board, n, i, c))
    {
      board[i][c] = 1;
      if (fn(board, n, c + 1))
      {
        return true;
      }
      board[i][c] = 0;
    }
    i++;
  }
  return false;
}

class Queen
{
public:
  vector<vector<int>> board;

  Queen(int n)
  {
    for (int i = 0; i < n; i++)
    {
      board.push_back(vector<int>(n, 0));
    }
  }

  void place(int n)
  {
    fn(board, n, 0);
  }

  void printq(int n)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j])
        {
          cout << "Q"
               << " ";
        }
        else
        {
          cout << "-"
               << " ";
        }
      }
      cout << endl;
    }
  }
};

int main()
{

  cout << "Enter the size of board : ";
  int n;
  cin >> n;

  Queen q(n);

  q.place(n);
  q.printq(n);

  return 0;
}