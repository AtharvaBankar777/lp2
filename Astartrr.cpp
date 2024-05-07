#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// Node structure for the puzzle state
struct Node
{
  vector<vector<int>> board; // 2D vector representing the puzzle state
  int g;                     // Cost from start to current state
  int h;                     // Heuristic value (estimated cost from current state to goal)
  int f;                     // Total cost f = g + h

  Node(vector<vector<int>> b, int g, int h) : board(b), g(g), h(h), f(g + h) {}

  // Define custom operator< for priority_queue
  bool operator<(const Node &other) const
  {
    return f > other.f; // Priority based on f value (lowest f value has higher priority)
  }
};

// Function to calculate the Manhattan distance heuristic
int manhattanDistance(const vector<vector<int>> &board)
{
  int n = board.size();
  int distance = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] != 0)
      {
        int targetX = (board[i][j] - 1) / n;
        int targetY = (board[i][j] - 1) % n;
        distance += abs(i - targetX) + abs(j - targetY);
      }
    }
  }
  return distance;
}

// Function to check if a board state is the goal state
bool isGoal(const vector<vector<int>> &board)
{
  int n = board.size();
  int num = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == n - 1 && j == n - 1)
      {
        if (board[i][j] != 0)
        {
          return false;
        }
      }
      else
      {
        if (board[i][j] != num++)
        {
          return false;
        }
      }
    }
  }
  return true;
}

// Function to print the board
void printBoard(const vector<vector<int>> &board)
{
  int n = board.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to generate a hash key for a board state
string myHash(const vector<vector<int>> &board)
{
  string key = "";
  for (const vector<int> &row : board)
  {
    for (int num : row)
    {
      key += to_string(num);
    }
  }
  return key;
}

void solvePuzzle(const vector<vector<int>> &initial)
{
    int n = initial.size();
    vector<vector<int>> goal(n, vector<int>(n));

    // Create the goal state
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            goal[i][j] = num++;
        }
    }
    goal[n - 1][n - 1] = 0; // Empty tile represented by 0

    // Define the initial node
    Node start(initial, 0, manhattanDistance(initial));

    // Priority queue for open set
    priority_queue<Node> openSet;
    openSet.push(start);

    // Hash table to store visited states
    unordered_map<string, bool> visited;
    visited[myHash(start.board)] = true; // Mark initial state as visited

    // A* algorithm
    while (!openSet.empty())
    {
        Node current = openSet.top();
        openSet.pop();

        cout << "Current state:" << endl;
        printBoard(current.board);
        cout << endl;

        if (isGoal(current.board))
        {
            cout << "Goal state reached!" << endl;
            printBoard(current.board);
            return;
        }

        // Generate possible moves
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int newX = -1, newY = -1;
            // Find the empty tile
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (current.board[x][y] == 0)
                    {
                        newX = x + dx[i];
                        newY = y + dy[i];
                        break;
                    }
                }
                if (newX != -1)
                {
                    break;
                }
            }
            // Check if the move is valid
            if (newX >= 0 && newX < n && newY >= 0 && newY < n)
            {
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[newX][newY], newBoard[newX - dx[i]][newY - dy[i]]);
                if (!visited[myHash(newBoard)])
                {
                    visited[myHash(newBoard)] = true;
                    openSet.push(Node(newBoard, current.g + 1, manhattanDistance(newBoard)));
                }
            }
        }
    }

    cout << "No solution found!" << endl;
}


int main()
{
  int n;
  cout << "Enter the size of the puzzle (e.g., for 8 puzzle, enter 3): ";
  cin >> n;

  vector<vector<int>> initial(n, vector<int>(n));

  cout << "Enter the initial state of the puzzle:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> initial[i][j];
    }
  }

  solvePuzzle(initial);

  return 0;
}
