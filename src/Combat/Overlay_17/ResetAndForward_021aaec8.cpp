#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct Cont0207fd88;
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);

// USA: func_ov017_021aaec8
ARM void ResetAndForward_021aaec8(char* p) {
	if (*(int*)(p + 0x14) == 5) {
		void* p18 = *(void**)(p + 0x18);
		if (p18 != NULL) CallFunc0204b088OverList0x2c((struct Cont0207fd88*)p18);
	}
	MessageSystem* x = GetGlobalField0x1c020421a0();
	Forward0204359c(x, 8);
	func_020439b0(x, 0);
}
