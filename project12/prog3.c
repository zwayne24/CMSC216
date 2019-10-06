#include <stdio.h>

int v0, v1, num;

static int gfn(int n0, int n1, int n);
static int gfn_helper(int n0, int n1, int n, int i);

int gfn(int n0, int n1, int n) {
  return gfn_helper(n0, n1, n, 0);
}

int gfn_helper(int n0, int n1, int n, int i) {
  int ans;

  if (n < 0)
    ans= -1;
  else
    if (n == 0 || n == i)
      ans= n0;
    else  /* ans < n */
      ans= gfn_helper(n1, n0 + n1, n, i + 1);

  return ans;
}

int main() {
  scanf("%d %d %d", &v0, &v1, &num);

  printf("%d\n", gfn(v0, v1, num));

  return 0;
}
