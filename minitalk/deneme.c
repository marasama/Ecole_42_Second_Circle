#include <stdio.h>

int checkbit(int a, int b)
{
    unsigned int c = 1 << b;
    unsigned int check = a & c;
    if (check == 0)
        return 0;
    else
        return (1);
}

void sendnumber(int a)
{
    int b;

    unsigned int c = 1048576;
    b = 20;
    unsigned int d = 0;
    while (b >= 0)
    {
        if (checkbit(a, b) == 0)
        {
          printf("0\n");
        }
        else
        {
          d += c;
          printf("1\n");
        }
        c /= 2;
        b--;
    }
    printf("%d",d);
}

int main(){
  sendnumber(142313);
  return 0;
}