#include <stdio.h>
#include <stdbool.h>

bool is_lucky(int N)
{
  int l = 2;
  while(l<N)
  {
    if(N%l== 0) return 0;
    N = N-(N/l++);
  }
  return 1;
}

int main()
{
  int n;
  scanf("%d", &n);
  if(is_lucky(n))
  {
    printf("Lucky");
  }
  else
  {
    printf("Not lucky");
  }
  return 0;
}
