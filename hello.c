#include <stdio.h>

int main(int argc, char *argv[]) {

  /* if (argv[1]) { */
  /*   printf("The number of args is %d\n", argc); */
  /*   printf("Hello, %s\n", argv[1]); */
  /*   printf("The pointer to arg 1 is %p\n", &argv[1]); */
  /*   return 0; */
  /* } */

  int total = argc;

  while (argc > 1) {
    printf("%s", argv[total - argc + 1]);

    if (total < argc + 1)
      printf(" ");

    argc--;
  }

  if (total >= 2) {
    printf("\n");
    return 0;
  }

  printf("Hello World\n");
  return 0;
}
