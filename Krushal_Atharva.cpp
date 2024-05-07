#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
  public :
  vector<vector<pair<int,int>>>adj;
  vector<pair<int,pair<int,int>>>edges;
  vector<int>parent;


  graph(int v){
    adj.resize(v);
    parent.resize(v,-1);
  }

   void addEdge(int source, int destination, int weight) {
        adj[source].push_back({destination, weight});
        edges.push_back({weight, {source, destination}});
    }

  int find(int i){
    if(parent[i]==-1){
      return i;
    }
    return find(parent[i]);
  }

  void Union(int x,int y){
    int xset=find(x);
    int yset=find(y);

    parent[xset]=yset;

  }

  int krushal(){
    sort(edges.begin(),edges.end());
    int sum=0;
    for (auto it : edges){
      int wt=it.first;
      int source=it.second.first;
      int destination =it.second.second;

      int x=find(source);
      int y=find(destination);

      if(x!=y){
        sum+=wt;
        Union(x,y);
        cout<<"Edges added : "<<source<<"-->"<<destination<<"=="<<wt<<endl;
      }
    }
    return sum;
  }



};

int main(){

  cout<<"Enter the vertex and edges";
  int V,E;
  cin>>V>>E;

  graph g(V);

  cout << "Enter source, destination, and weight for each edge:" << endl;
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        g.addEdge(source, destination, weight);
    }

    int sum=g.krushal();
    cout<<sum;


  return 0;
}