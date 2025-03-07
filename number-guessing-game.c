#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_the_number(char *prompt) {
  int number;

  printf("%s: ", prompt);
  while (scanf(" %d", &number) != 1) {
    printf("That wasn't a number\n");
    while (getchar() != '\n') {
    }
  }

  return number;
}

int main() {
  srand(time(NULL));
  int random_number = (rand() % 100) + 1; // seed the random number generator

  int current_number;
  int number_of_tries = 0;

  current_number = get_the_number("Guess a number between 1 and 100");

  while (random_number != current_number) {
    number_of_tries++;
    if (current_number < random_number) {
      printf("Number %d too small. ", current_number);
    } else if (current_number > random_number) {
      printf("Number %d too big. ", current_number);
    }

    while (getchar() != '\n') {
    }

    current_number = get_the_number("Try again");
  }

  printf("---------------");
  printf("\nYay, the number was %d\n", random_number);
  printf("It took %d number of tries\n", number_of_tries);

  return 0;
}
