#include <circle/syscallhandler.h>
#include <circle/logger.h>
#include <circle/sched/scheduler.h>
#include <string.h>

int SyscallHandler(int arg1, int arg2, int arg3, int arg4) {
	register long syscall_no asm ("r7");
	//CLogger::Get ()->Write ("SyscallHandler", LogDebug, "syscall_no=0x%x.", syscall_no);

	// TODO: Handle system calls based on syscall_no.

	// switch(syscall_no){
	// 	case 0L:
	// 		return (int)CTimer::Get()->GetUptime();

	// 	case 1L:
	// 		CTask * currtask = CScheduler::Get()->GetCurrentTask();
	// 		memcpy((void*)arg1, currtask->GetName(), (size_t)arg2);
	// 		break;

	// 	case 2L:
	// 		CLogger::Get()->Write("SyscallHandler", LogNotice, "%s", (const char*)arg1);
	// 		break;

	// 	case (long)0x03:
	// 		CTask * currtask = CScheduler::Get()->GetCurrentTask();
	// 		DisableIRQs();
	// 		currtask->m_State = TaskStateSleeping;
	// 		currtask->m_Event.Set();
	// 		CScheduler::Get()->Yield();
	// 		break;

	// 	case (long)0x04:
	// 		CTask * currtask = CScheduler::Get()->GetCurrentTask();
	// 		DisableIRQs();
	// 		currtask->m_State = TaskStateTerminated;
	// 		currtask->m_Event.Set();
			
	// 		CScheduler::Get()->Yield();
	// 		break;


	// }
	if (syscall_no == 0L){
		return (int)(CTimer::Get()->GetUptime());
	}
	else if (syscall_no == 1L){
		CTask * currtask = CScheduler::Get()->GetCurrentTask();
		memcpy((void*)arg1, currtask->GetName(), (size_t)arg2);
	}
	else if (syscall_no == 2L){
		CLogger::Get()->Write("SyscallHandler", LogNotice, "%s", (const char*)arg1);
	}
	else if (syscall_no == (long)0x03){
		CTask * currtask = CScheduler::Get()->GetCurrentTask();
		
		CScheduler::Get()->Sleep((unsigned)arg1);

	}else if (syscall_no == (long)0x04){
		CTask * currtask = CScheduler::Get()->GetCurrentTask();
		DisableIRQs();
		currtask->m_State = TaskStateTerminated;
		currtask->m_Event.Set();
		
		CScheduler::Get()->Yield();
	}
	return 0;
}
