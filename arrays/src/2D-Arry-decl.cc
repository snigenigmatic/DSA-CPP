#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  for(int i = 0;i<n;i++){
     for(int j = 0;j<m;j++){
        int num;
        cin>>num;
        arr[i][j] = num;
     }
  }

  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
}

