#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph
{
public:
  vector<vector<pair<int, int>>> adj;
  vector<int> visited;
  vector<pair<int, int>> mst;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

  graph(int v)
  {
    adj.resize(v);
    visited.resize(v);
    mst.resize(v);
  }

  void addEdges(int source, int destination, int weight)
  {
    adj[source].push_back({destination, weight});
    adj[destination].push_back({source, weight});
  }

  int prims()
  {
    q.push({0, {0, -1}}); // weight source destination

    int sum = 0;

    while (!q.empty())
    {
      auto element = q.top();
      int wt = element.first;
      int node = element.second.first;
      int parent = element.second.second;
      q.pop();

      if (visited[node])
        continue;

      if (parent != -1)
      {
        mst[node] = {parent, wt};
        sum += wt;
      }

      visited[node] = 1;

      for (auto it : adj[node])
      {
        int neighboure = it.first;
        int wt = it.second;

        if (!visited[neighboure])
        {
          q.push({wt, {neighboure, node}});
          // visited[neighboure] = 1;
        }
      }
    }
    return sum;
  }
};

int main()
{

  cout << "Enter the Vertex and Edges :";
  int V, E;
  cin >> V >> E;
  graph g(V);

  cout << "Enter the source destination weight" << endl;
  for (int i = 0; i < E; i++)
  {
    int s, d, wt;
    cin >> s >> d >> wt;

    g.addEdges(s, d, wt);
  }

  int sum = g.prims();

  for (int i = 0; i < V; i++)
  {
    cout << "connected edges to " << i << " vertex are :";
    for (auto it : g.adj[i])
    {
      cout << "     -> " << it.first << " & weight is " << it.second;
    }
    cout << endl;
  }

  cout << sum;

  return 0;
}