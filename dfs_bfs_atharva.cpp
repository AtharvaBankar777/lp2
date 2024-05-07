#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
public:
  vector<vector<int>>adj;
  
  graph(int v){
    adj.resize(v);
  }

  void addedges(int s,int d){
    adj[s].push_back(d);
    adj[d].push_back(s);

  }

  void dfs(int start){
    vector<int>visited(adj.size(),0);
    // visited[start]=1;
    cout<<"DFS traversal starts from "<<start<<" : "<<endl;
    recursivedfs(start,visited);

  }

  void recursivedfs(int start,vector<int>&visited){
    visited[start]=1;
    cout<<start<<"  ";
    for(auto it:adj[start]){
      if(!visited[it]){
        recursivedfs(it,visited);
      }
    }
  }

  void bfs(int start){
    vector<int>vis(adj.size(),0);
    queue<int>q;

    q.push(start);
    vis[start]=1;
    cout<<"BFS traversal starts from "<<start<<" : "<<endl;
    recursivebfs(q,vis);

    


  }

  void recursivebfs(queue<int>&q,vector<int>&visited){

    if(q.empty()){
      return ;
    }
    int u=q.front();
    q.pop();
    // visited[u]=1;
    cout<<u<<"  ";

    
      for(auto it:adj[u]){
        if(!visited[it]){
          q.push(it);
          visited[it]=1;
        }
      }
      recursivebfs(q,visited);
    

  }
};

int main(){

  cout<<"Enter thr vertex and edges";
  int V,E;
  cin>>V>>E;

  graph g(V);

  cout<<"Enter the source destination"<<endl;
  for(int i=0;i<E;i++){
    int s,d;
    cin>>s>>d;
    g.addedges(s,d);
  }

  cout<<"Enter the starting node"<<endl;
  int start;
  cin>>start;
  g.dfs(start);
  cout<<endl;
  g.bfs(start);




  return 0;
}
