
#include <stdio.h>

#define SOME_FLAG 0x80

typedef struct {
  unsigned info;
  unsigned flags;
} state_t;

state_t do_negateexit(state_t state) {
  state_t reply;
  reply.info = (state.flags & SOME_FLAG) > 0;

  if (state.info != 0) {
    reply.flags |= SOME_FLAG;
  } else {
    reply.flags &= ~SOME_FLAG;
  }

  return reply;
}

int main() {
  state_t state;
  state.info = 1;
  state.flags = 0;

  state = do_negateexit(state);

  printf("%d %d\n", state.info, state.flags);

  return 0;
}
