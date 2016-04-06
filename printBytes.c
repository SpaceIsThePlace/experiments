/* 
// Shows byte stored in virtual memory for any entered int,
// and following casts to float and double.
// Original idea from Computer Systems - A programmer perspective (R. E. Bryant, D. R. O'Halloran), Third edition 
*/

#include <stdio.h>

typedef unsigned char *bytePointer;

void showBytes(bytePointer start, size_t len)
{
  unsigned int i;
  printf("Byte:");
  for (i = 0; i != len; i++)
    {
      printf("      ");
      printf("%d", i);
    }
  printf("\n"); 
  printf("Location:  ");
  for (i = 0; i != len; i++)
    {
      printf("%.2x ", &start[i]);
    }
  printf("\n");
  printf("=========  ");
  for (i = 0; i != len; i++)
    {
      printf("====== ");
    }
  printf("\n");
  printf("Value:     ");
  for (i = 0; i != len; i++)
    {
      printf("%.2x     ", start[i]);
    }
  printf("\n\n");
}

void showInt(int x)
{
  printf("Type: int\n");
  showBytes((bytePointer) &x, sizeof(int));
}

void showFloat(float x)
{
  printf("Type: float\n");
  showBytes((bytePointer) &x, sizeof(float));
}

void showDouble(double x)
{
  printf("Type: double\n");
  showBytes((bytePointer) &x, sizeof(double));
}

void showPointer(void *x)
{
  printf("Type: pointer (to first byte)\n");
  showBytes((bytePointer) &x, sizeof(void *));
}


void testShowBytes(int val)
{
  int ival = val;
  float fval = (float) ival;
  long dval = (double) ival;
  int *pval = &ival;
  showInt(ival);
  showFloat(fval);
  showDouble(dval);
  showPointer(pval);
}

int main(int argc, char *argv[])
{
  int num;
  printf("Enter number: ");
  scanf("%d", &num);
  printf("\n");
  testShowBytes(num);

  return 0;
}

