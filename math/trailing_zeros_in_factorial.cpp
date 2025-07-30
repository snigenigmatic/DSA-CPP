/*
Trainling zeros in the afctorial of a number
input : number N
outout : no. of trailing zeros in N
*/

#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
	  int trailing_zeros(int N)
	  {
	    int ans = 0;
	    while(N/5)
	    {
	      ans+=N/5;
	      N=N/5;
	    }
	    return ans;
	  }
};

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int N;
    cin>>N;
    Solution obj;
    int ans = obj.trailing_zeros(N);
    cout<<ans<<endl;
  }
  return 0;
}
