#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main(void)
{
  vector<int> arr = {5,6,7,8};
  int x = 7;
  auto it = find(arr.begin(), arr.end(), x);
  if(it!=arr.end()){
    int index = distance(arr.begin(), it);
    cout<<"Element found at index "<<index<<endl;
  }
  else{
    cout<<"Element not found"<<endl;
  }
}
