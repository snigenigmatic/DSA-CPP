#include <stdio.h>
#include <math.h>

float Q_rsqrt(float number){
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number*0.5F;
  y = number;
  i = * (long *) &y;
  i = 0x5f379df - (i>>1);
  y = *(long *)&i;
  y = y*(threehalfs - (x2*y*y));

  return y;
}

int main(){
  float x = 5.0,y = 7.0, z = 9.0;
  float sum_squares = x*x + y*y + z*z;
  float ans = Q_rsqrt(sum_squares);
  printf("inverse square root : %f", ans);
  return 0; 
}
