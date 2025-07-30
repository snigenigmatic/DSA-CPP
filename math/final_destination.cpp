/*
Given a start pointer at (0,0), and ending co-ordinates(a,b) and n (number of
steps), find if it is possible to reach there by moving only 1 unit steo at a
time
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int CanReach(long long a, long long b, long long x)
    {
      a = abs(a);
      b = abs(a);
      long long c = a+b;

      if(a ==0 && b==0 && x%2!=0){return 0;}
      if(c>x) return 0;
      if(c==x) return 1;
      if(c<x) {return (((x-c)%2)?0:1);}
    }
};

int main()
{
  long long a,b,x;
  cin>>a>>b>>x;
  Solution obj;
  cout<<obj.CanReach(a,b,x)<<endl;
  return 0;
}

