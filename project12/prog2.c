#include <stdio.h>

int v0, v1, num;

static int gfn(int n0, int n1, int n);

static int gfn(int n0, int n1, int n) {
  int i= 1, temp;

  if (n < 0)
    n1= -1;  /* return -1 if n < 0 */
  else
    if (n == 0)
      n1= n0;  /* return n0 if n is 1 */
    else
      while (i < n) {
        temp= n0;
        n0= n1;
        n1 += temp;

        i++;
      }

  return n1;
}

int main() {
  scanf("%d %d %d", &v0, &v1, &num);

  printf("%d\n", gfn(v0, v1, num));

  return 0;
}
