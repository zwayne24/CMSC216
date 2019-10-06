#include "functions.h"

/* Write your implementations of the functions in this source file.
 * Skeleton versions of the functions already appear below.
 */

int is_valid_triangle(int side1, int side2, int side3) {
  if (side1 + side2 > side3 && side2 + side3 > side1 && side3 + side1 > side2
      && (side1 * side2 * side3 != 0))
    return 1;
  else if (side1 < 0 || side2 < 0 || side3 < 0)
    return -1;
  else
    return 0;
}

int gfn(int n0, int n1, int n) {
  if (n == 0)
    return n0;
  else if (n == 1)
    return n1;
  else
    return gfn(n0, n1, n-1) + gfn(n0, n1, n-2);
}
