#include <assert.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
  printf("%d should be %d\n", negateexit(1), 0);
  printf("%d should be %d\n", negateexit(1), 1);
  printf("%d should be %d\n", negateexit(0), 1);
  // printf("%d should be %d\n", negateexit(1), 0);

  return 0;
}
