#include <globaldefs.h>
#include "Resource/MessageSystem.h"


// USA: func_ov017_021acd00
ARM void ResetAndForwardCount2_021acd00(void*) {
	MessageSystem* x = GetGlobalField0x1c020421a0();
	Forward0204359c(x, 2);
	func_020439b0(x, 0);
}
