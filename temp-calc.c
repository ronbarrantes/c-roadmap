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
 * Celsius to Farenheight
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
 * Farenheight to Celsius
 * @param f The input double.
 */
double ftoc(double f) {
  return (f - 32) * (5.0 / 9);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please pass the temperature with the C|F|K");
    return 1;
  }

  char *temperature = argv[1];
  int length = strlen(temperature);

  char degrees = tolower(temperature[length - 1]);

  char *end_ptr;
  double float_temp = strtod(temperature, &end_ptr);

  // ensure that the degrees is either C or F or K
  if (degrees != 'c' && degrees != 'f' && degrees != 'k') {
    printf("Invalid param. The last character should be C|F|K, you inputed %c\n", degrees);
    return 1;
  }

  double c, f, k;

  switch (degrees) {
  case 'c':
    c = float_temp;
    f = ctof(c);
    k = ctok(c);
    break;
  case 'f':
    f = float_temp;
    c = ftoc(f);
    k = ctok(c);
    break;
  case 'k':
    k = float_temp;
    c = ktoc(k);
    f = ctof(c);

    break;
  default:
    printf("ERROR: there was a problem calculating the temperatures\n");
    return 1;
  }

  printf("%.2fC\n", c);
  printf("%.2fF\n", f);
  printf("%.2fK\n", k);

  return 0;
}
