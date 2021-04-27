#include <lib.h>
#include <minix/rs.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int get_pm_endpt(endpoint_t *pt) { return minix_rs_lookup("pm", pt); }

int negateexit(int negate) {
  endpoint_t pm_pt;
  message m;
  m.m_negate_exit.negate = negate;
  
  if (get_pm_endpt(&pm_pt) != 0 || _syscall(pm_pt, PM_NEGATEEXIT, &m) != 0) {
    errno = ENOSYS;
    return -1;
  }
  return m.m_negate_exit.negate;
}
