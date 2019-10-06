#include <stdio.h>

int side1, side2, side3, ans;

int main() {
  ans= 0;

  scanf("%d %d %d", &side1, &side2, &side3);

  if (side1 <= 0 || side2 <= 0 || side3 <= 0)
    ans= -1;
  else
    if (side1 + side2 > side3 && side1 + side3 > side2 &&
        side2 + side3 > side1)
    ans= 1;

  printf("%d\n", ans);

  return 0;
}
