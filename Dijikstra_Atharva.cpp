#include<bits/stdc++.h>
using namespace std;

int inf = INT_MAX;

class graph{
  public:
    vector<vector<pair<int,int>>>adj;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int>distance;

    graph(int v){
      adj.resize(v);
      distance.resize(v,inf);
    }

    void edges(int source,int destination , int weight){
      adj[source].push_back({destination,weight});
      adj[destination].push_back({source,weight});
    }

    vector<int> dijikstra(int start){
      q.push({0,start});
      distance[start]=0;

      while(!q.empty()){
        auto u=q.top().second;
        q.pop();

        for(auto it : adj[u]){
          int v=it.first;
          int wt=it.second;

          if(distance[u] != inf  && distance[u]+wt<distance[v]){
            distance[v]=distance[u]+wt;
            q.push({distance[v],v});
          }

        }

      }
      return distance;


    }
};

int main(){

  cout<<"Enter the no of Vertex and Edges :";
  int V,E;
  cin>>V>>E;

  graph g(V);

  cout<<"Enter the Source Destination Weight"<<endl;
  for(int i=0;i<E;i++){
    int s,d,wt;
    cin>>s>>d>>wt;
    g.edges(s,d,wt);
  }

  cout<<"Enter the source";
  int start;
  cin>>start;
  vector<int>dist=g.dijikstra(start);

  for(int i=0;i<V;i++){
    if(dist[i]==inf){
      cout<<"vertex "<<i<<" does not exist path";
    }else{
      cout<<"vertex "<<i<<" : "<<dist[i];
    }cout<<endl;
  }


  return 0;
}