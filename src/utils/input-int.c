#ifndef INPUT_INT_BROWSER_HISTORY
#define INPUT_INT_BROWSER_HISTORY

#include <stdio.h>
#include <stdlib.h>

int InputInt() {
  char *endptr_i;
  char str_i[20];
  int i = -1;

  char *fgetsRet = fgets(str_i, 20, stdin);
  i = strtol(str_i, &endptr_i, 0);

  if (*endptr_i != '\n' || str_i[0] == '\n' || endptr_i == str_i ||
      i == -2147483648 || i == 2147483647) {
    puts("ERROR: Inteiro invalido, tente novamente");
    return InputInt();
  }
  return i;
}

#endif
