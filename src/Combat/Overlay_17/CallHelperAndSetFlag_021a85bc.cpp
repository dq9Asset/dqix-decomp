#include <globaldefs.h>

struct S021a85bc { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a7dd8(S021a85bc*);

// USA: func_ov017_021a85bc
ARM void CallHelperAndSetFlag_021a85bc(S021a85bc* obj) {
	func_ov017_021a7dd8(obj);
	obj->f1 = 1;
}
