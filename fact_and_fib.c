#include <stdio.h>
#include <string.h>

char *fac = "fac";
char *fib = "fib";

int get_the_number(char *prompt) {
  int number;

  printf("%s: ", prompt);
  while (scanf(" %d", &number) != 1) {
    printf("Try again with a number: ");
    while (getchar() != '\n') {
    }
  }

  return number;
}

char *get_fac_or_fib(char *prompt) {
  static char fac_fib[4];

  printf("%s: ", prompt);
  while (scanf(" %3s", fac_fib) != 1 || (strcmp(fac_fib, fac) != 0 && strcmp(fac_fib, fib) != 0)) {
    printf("Write %s or %s: ", fac, fib);
    while (getchar() != '\n') {
    }
  }

  return fac_fib;
}

long factorial(int n) {
  long res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
    printf("res -->> %ld\n", res);
  }
  return res;
}

long fibonacci(int n) {
  // recursion
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  n = fibonacci(n - 2) + fibonacci(n - 1);
  return n;
}

int main() {
  char *operation = get_fac_or_fib("Input fac or fib");
  int number = get_the_number("Input a number");

  if (strcmp(operation, fac) == 0) {
    long result = factorial(number);
    printf("The factorial of %d is %ld\n", number, result);
  }

  else {
    long result = fibonacci(number);
    printf("The %d fibonacci is %ld\n", number, result);
  }

  return 0;
}
