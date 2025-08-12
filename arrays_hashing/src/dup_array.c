#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_integers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main()
{
  int vec[] = {10,20,35,3,23, 10};
  int n = sizeof(vec)/sizeof(int);
  qsort(vec, n, sizeof(int), compare_integers);
  for(int i = 0;i<n;i++)
  {
    if(vec[i] == vec[i+1])
    {
      printf("Duplicate Exists");
      return 1;
    }
  }
  printf("No dulicates");
  return 0;
}
