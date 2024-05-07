#include<iostream>
#include<vector>
using namespace std;



int main(){


  int n;
  cout<<"Enter the no element"<<endl;
  cin>>n;

  vector<int>v;
  for(int i=0;i<n;i++){
    cout<<"Enter the "<<i<<" : element :-";
    int a;
    cin>>a;
    v.push_back(a);
  }

  for(int i=0;i<n;i++){
    int min=i;
    for(int j=i+1;j<n;j++){
      if(v[j]<v[min]){
        min=j;
      }
    }
    swap(v[i],v[min]);
  }

for(int i=0;i<n;i++){
  cout<<v[i]<<" ";
}


  return 0;
}