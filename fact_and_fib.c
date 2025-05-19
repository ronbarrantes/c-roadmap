#include <stdio.h>
#include <string.h>

const char *fac = "fac";
const char *fib = "fib";

int get_the_number(char *prompt) {
  int number;

  printf("%s: ", prompt);
  while (scanf(" %d", &number) != 1 || number <= 0) {
    printf("Try again with a positive number: ");
    while (getchar() != '\n')
      ;
  }

  return number;
}

char *get_fac_or_fib(char *prompt) {
  static char fac_fib[4];

  printf("%s: ", prompt);
  while (scanf(" %3s", fac_fib) != 1 || (strcmp(fac_fib, fac) != 0 && strcmp(fac_fib, fib) != 0)) {
    printf("Write %s or %s: ", fac, fib);
    while ((getchar()) != '\n')
      ;
  }

  return fac_fib;
}

unsigned long long factorial(int n) {
  unsigned long long res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

unsigned long long fibonacci(int n, unsigned long long arr[]) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  if (arr[n] != 0)
    return arr[n];

  arr[n] = fibonacci(n - 2, arr) + fibonacci(n - 1, arr);
  return arr[n];
}

int main() {
  char *operation = get_fac_or_fib("Input fac or fib");
  int number = get_the_number("Input a positive number");

  if (strcmp(operation, fac) == 0) {
    unsigned long long result = factorial(number);
    printf("The factorial of %d is %llu\n", number, result);
  }

  else {
    // init elements to zero

    unsigned long long arr[number + 1];
    memset(arr, 0, sizeof(arr));
    unsigned long long result = fibonacci(number, arr);
    printf("The %d fibonacci is %llu\n", number, result);
  }

  return 0;
}
