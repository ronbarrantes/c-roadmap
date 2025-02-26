#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char get_sign() {
  bool valid_sign = false;
  char sign;

  printf("Operation (+ - * / %%): ");
  while (!valid_sign) {
    scanf(" %c", &sign); // space before %c to ignore white space
    valid_sign = (sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '%');

    if (!valid_sign) {
      printf("Invalid input, try again: ");
    }

    while (getchar() != '\n' && !feof(stdin)) {
      // Always clear buffer
    }
  }

  return sign;
}

int get_input_with_prompt(const char *prompt) {
  int num;
  printf("%s: ", prompt);
  while (scanf("%d", &num) != 1) {
    printf("That wasn't a number. Try again: ");
    while (getchar() != '\n') {
    }
  }

  return num;
}

void perform_calculation(char sign, int first_number, int second_number) {
  printf("The result of %d%c%d is: ", first_number, sign, second_number);
  switch (sign) {

  case '+':
    printf("%d\n", first_number + second_number);
    break;
  case '-':
    printf("%d\n", first_number - second_number);
    break;
  case '*':
    printf("%d\n", first_number * second_number);
    break;
  case '/':
    printf("%.3f\n", (float)first_number / (float)second_number);
    break;
  case '%':
    printf("%d\n", first_number % second_number);
    break;
  default:
    printf("something really bad happend and could not compute\n");
  }
}

int main() {
  int first_number, second_number;
  char sign;

  sign = get_sign();

  first_number = get_input_with_prompt("Choose the first number");

  do {
    second_number = get_input_with_prompt("Choose the second number");

    if (second_number == 0 && sign == '/') {
      printf("Yo, you trying to divide by zero!\n");
    }
  } while (second_number == 0 && sign == '/');

  printf("--------\n");
  perform_calculation(sign, first_number, second_number);
  printf("--------\n");
  printf("Good bye\n");
  return 0;
}
