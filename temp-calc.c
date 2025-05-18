#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Celsius to Kelvin
 * @param c The input double.
 */
double ctok(double c) {
  return c + 273.15;
}

/**
 * Celsius to Fahrenheit
 * @param c The input double.
 */
double ctof(double c) {
  return c * (9.0 / 5) + 32;
}

/**
 * Kelvin to Celsius
 * @param k The input double.
 */

double ktoc(double k) {
  return k - 273.15;
}

/**
 * Fahrenheit to Celsius
 * @param f The input double.
 */
double ftoc(double f) {
  return (f - 32) * (5.0 / 9);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number><C|F|K>\n", argv[0]);
    return 1;
  }

  char *input = argv[1];
  char *end_ptr;
  double input_temp = strtod(input, &end_ptr);

  // Check that a valid number was parsed
  if (end_ptr == input || *end_ptr == '\0') {
    fprintf(stderr, "Invalid input: temperature must end with C, F, or K (e.g., 100C)\n");
    return 1;
  }

  char unit = tolower(*end_ptr);
  if (*(end_ptr + 1) != '\0' || (unit != 'c' && unit != 'f' && unit != 'k')) {
    fprintf(stderr, "Invalid temperature unit: use C, F, or K\n");
    return 1;
  }

  double c, f, k;

  switch (unit) {
  case 'c':
    c = input_temp;
    f = ctof(c);
    k = ctok(c);
    break;
  case 'f':
    f = input_temp;
    c = ftoc(f);
    k = ctok(c);
    break;
  case 'k':
    k = input_temp;
    c = ktoc(k);
    f = ctof(c);

    break;
  default:
    fprintf(stderr, "Unknown error occurred\n");
    return 1;
  }

  printf("%.2fC\n", c);
  printf("%.2fF\n", f);
  printf("%.2fK\n", k);

  return 0;
}
