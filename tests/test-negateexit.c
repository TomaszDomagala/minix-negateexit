#include <lib.h>
#include <minix/rs.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  message m;
  m.m_negate_exit.negate = 1;
  endpoint_t pm_ep;
  minix_rs_lookup("pm", &pm_ep);
  printf("PM_NEGATEEXIT %d\n", PM_NEGATEEXIT);
  printf("pm_ep %d\n", pm_ep);

  int res = _syscall(pm_ep, PM_NEGATEEXIT, &m);
  printf("_syscall result %d\n", res);
  printf("message result %d\n", m.m_negate_exit.negate);
  printf("errno %d\n", errno);
  return 0;
}
