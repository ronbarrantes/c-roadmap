// temperature calculator
// I want to add a temperature with a sign
// like C or F or K and it will display all
// the 3 different temperatures

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  printf("the argc is '%d'\n", argc);

  if (argc != 2) {
    printf("Please pass the temperature with the C|F|K");
    return 0;
  }

  char *temperature = argv[1];
  int length = strlen(temperature);

  bool is_negative = false;
  char end_char = temperature[length - 1];
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

  // ensure that the end_char is either C or F or K
  if (tolower(end_char) != 'c' && tolower(end_char) != 'f' && tolower(end_char) != 'k') {
    printf("Invalid param. The last character should be C|F|K, you inputed %c\n", end_char);
    return 1;
  }

  printf("int_temp is %f\n", float_temp);
  printf("end_char is %c\n", end_char);
  // check if the first char is - or number
  // contains the C,F,K

  return 0;
}
