// factorials and fibonacci in loops and recursion
// what do I wanna do here
// maybe I want to run the function and it will give me choices
// input fac or fib
// input the number
//
// Maybe I can solve factorial with loop
// and I'll solve fibonacci with recursion
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

int factorial(int n) {
  for (int i = 1; i <= n; i++) {
    n *= i;
  }
  return n;
}

int fibonacci(int n) {
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
    int result = factorial(number);
    printf("The factorial of %d is %d\n", number, result);
  }

  else {
    int result = fibonacci(number);
    printf("The %d fibonacci is %d\n", number, result);
  }

  return 0;
}
