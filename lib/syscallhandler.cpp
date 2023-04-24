#include <circle/syscallhandler.h>
#include <circle/logger.h>
#include <circle/sched/scheduler.h>
#include <string.h>

int SyscallHandler(int arg1, int arg2, int arg3, int arg4) {
	register long syscall_no asm ("r7");


	// CLogger::Get ()->Write ("SyscallHandler", LogDebug, "syscall_no=0x%x.", syscall_no);

	// TODO: Handle system calls based on syscall_no.

	// Problem 2
	// It has begining has hexa
	return 0;
}
