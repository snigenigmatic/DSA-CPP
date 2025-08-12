#include<bits/stdc++.h>
#include <string>
#include <sys/types.h>
using namespace std;

string decToBinary(int n){
  if (n==0) return 0;
  string ans;
  while(n>0){
    ans=char('0'+n%2)+ans;
    n/=2;
  }
  return ans;
}

int main(void){
  int n;
  cin>>n;
  cout<<decToBinary(n)<<endl;
}
