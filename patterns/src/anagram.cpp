#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string& s1, string& s2)
{
  unordered_map <char, int> ump1;
  unordered_map <char, int> ump2;

  for(auto c1 : s1)
  {
    ump1[c1]++;
  }
  for(auto c2 : s2)
  {
    ump2[c2]++;
  }
  if(ump1 == ump2)
    return true;
  return false;
}

int main(void)
{
  string s1, s2;
  cout<<"Enter two strings: ";
  cin>>s1>>s2;
  bool answer = isAnagram(s1, s2);
  if(answer == true)
    cout<<"Yes Anagrams";
  else
    cout<<"Not Anagrams";
}
