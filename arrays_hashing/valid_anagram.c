#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isAnagram(char *a,char *b)
{
  if(strlen(a) != strlen(b))
  {
    return false;
  }

  int count[26] = {0};
  for(int i = 0;i<strlen(a);i++)
  {
    count[a[i] - 'a']++;
    count[b[i] - 'a']--;
  }
  for(int val = 0;val<(sizeof(count)/sizeof(int));val++)
  {
    if(count[val]!=0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  char *a = "carrace";
  char *b = "racecar";
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  bool value = isAnagram(a,b);
  printf("%s\n", value ? "true" : "false");
  end = clock();
  printf("Execution Time : %.8f",((double)(end-start)) / CLOCKS_PER_SEC);
  return 0;
}
