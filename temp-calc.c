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
  return 273.15 - k;
}

/**
 * Farenheight to Celsius
 * @param f The input double.
 */
double ftoc(double f) {
  return (f - 32) * (5.0 / 9);
}

/**
 * Extracts a substring from the given string.
 *
 * @param str The input string.
 * @param initial The starting index of the substring (inclusive).
 * @param end The ending index of the substring (exclusive).
 * @return A dynamically allocated string containing the substring.
 *         The caller is responsible for freeing the memory using free().
 */

char *alloc_substring(char *str, int initial, int end) {
  int length = end - initial;

  char *str_temp = (char *)malloc((length + 1) * sizeof(char));
  if (str_temp == NULL)
    return NULL;

  for (int i = 0; i < length; i++) {
    str_temp[i] = str[initial + i];
  }

  str_temp[length] = '\0';
  return str_temp;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please pass the temperature with the C|F|K");
    return 1;
  }

  char *temperature = argv[1];
  int length = strlen(temperature);

  char degrees = tolower(temperature[length - 1]);
  char *temp_subs = alloc_substring(temperature, 0, length - 1);

  if (temp_subs == NULL) {
    return 1;
  }

  char *end_ptr;
  double float_temp = strtod(temp_subs, &end_ptr);

  if (*end_ptr != '\0') {
    printf("There was a problem with the number %s\n", temp_subs);
    free(temp_subs);

    return 1;
  }

  free(temp_subs);

  // ensure that the degrees is either C or F or K
  if (degrees != 'c' && degrees != 'f' && degrees != 'k') {
    printf("Invalid param. The last character should be C|F|K, you inputed %c\n", degrees);
    return 1;
  }

  double c;
  double f;
  double k;

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
