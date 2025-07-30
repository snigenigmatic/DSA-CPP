#include<bits/stdc++.h>
using namespace std;

/* int nCr(int n, int r)
{
  long long res = 1;
  for(int i = 0;i<=r;i++)
  {
    res = res*(n-i);
    res = res/(i+1);
  }
  return (int)(res);
}

vector<vector<int>> pascalTriangle(int n)
{
  vector<vector<int>> ans;
  for(int row = 1;row<=n;row++)
  {
    vector<int> tempLst; //temporary list
    for(int col = 1;col<=row;col++)
    {
      tempLst.push_back(nCr(row-1, col-1));      
    }
    ans.push_back(tempLst);
  }
  return ans;
} */

vector<vector<int>> pascalsTriangle(int n)
{
  vector<vector<int>> ans(n);
  for(int i = 0;i<n;i++)
  {
    ans[i].resize(i+1, 1);
    for(int j = 1;j<i;j++)
    {
      ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
    }
  }
  return ans;
}


int main(void)
{
  int n;
  cin>>n;
  vector<vector<int>> ans = pascalsTriangle(n);
  for(auto it : ans){
    for(auto ele : it){
      cout<<ele<<" ";
    }
    cout<<"\n";
  }
}
