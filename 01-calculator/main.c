#include <stdio.h>

int main() {
  double a, b;
  char op;

  printf("Enter digits (example: 5 + 3 ): ");
  scanf("%lf %c %lf", &a, &op, &b);

  if (op == '+') printf("%.2f\n", a + b);
  else if (op == '-') printf("%.2f\n", a -b);
  else if (op == '*') printf("%.2f\n", a * b);
  else if (op == '/' && b !=0) printf("%.2f\n", a /b);
  else printf ("ERROR!!\n");

  return 0;

}

