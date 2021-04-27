#include "pm.h"
#include <sys/wait.h>
#include <assert.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <minix/sched.h>
#include <minix/vm.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <signal.h>
#include "mproc.h"

int do_negateexit(void) {
  mp->mp_reply.m_negate_exit.negate = (mp->mp_flags & NEGATE_EXIT) > 0;

  if (m_in.m_negate_exit.negate != 0) {
    mp->mp_flags |= NEGATE_EXIT;
  } else {
    mp->mp_flags &= ~NEGATE_EXIT;
  }

  return OK;
}