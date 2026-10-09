#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
#include "System/GamecardBusOwnership.h"

struct FileBlock_0223b324 {
	void* tableBuffer;
	unsigned char pad0[0x84 - 4];
	void* slotArray;
	NitroHandle handle;
	unsigned short lockOwnerId;
};
struct Outer_0223b324 { FileBlock_0223b324* p; };
extern struct Outer_0223b324 data_ov031_02291924;

extern "C" int func_ov031_0223bd40(NitroVM* vm, int tag);
extern "C" int func_ov031_0223bdf4(NitroHandle*, const void*, unsigned int, unsigned int);
extern "C" ARM int func_ov031_0223bda4(NitroHandle* a, void* b, unsigned int c, unsigned int d);

extern "C" ARM void* func_ov031_0223d72c(unsigned int len, int align);
extern "C" void func_020cb6ac(void);
extern "C" ARM void* func_ov031_0223c6cc(int n, int base, int stride);
extern "C" int func_020c8bfc(int a, int b, ...);

extern const char data_ov031_0224d144[];
extern const char data_ov031_02249f90[];
extern const char data_ov031_0224d15c[];

struct FatFntPair_0223b324 { unsigned int offset; unsigned int size; };

// JPN: func_ov031_0223bb04
extern "C" ARM void func_ov031_0223bb04(void) {
	data_ov031_02291924.p = (FileBlock_0223b324*)func_ov031_0223d72c(0xe8, 4);

	NitroVM vm;
	NitroVM_Initialize(&vm);
	if (!NitroVM_PrepareReadFileByPath(&vm, data_ov031_0224d144))
		func_020cb6ac();

	data_ov031_02291924.p->lockOwnerId = GenerateLockOwnerID();
	void* image = (void*)vm.fileInfo.startOffset;
	FatFntPair_0223b324 fnt;
	NitroVM_ReadSync(&vm, &fnt, 8);
	FatFntPair_0223b324 fat;
	NitroVM_ReadSync(&vm, &fat, 8);
	NitroVM_FinishRead(&vm);

	NitroHandle_Initialize(&data_ov031_02291924.p->handle);
	if (!NitroHandle_AddToHandleList(&data_ov031_02291924.p->handle, data_ov031_02249f90, 3))
		func_020cb6ac();

	NitroHandle_SetOpcodeOverride(&data_ov031_02291924.p->handle, func_ov031_0223bd40, 0x602);

	if (!NitroHandle_Populate(&data_ov031_02291924.p->handle, image,
			fat.offset, fat.size, fnt.offset, fnt.size,
			func_ov031_0223bda4, func_ov031_0223bdf4))
		func_020cb6ac();

	unsigned int capacity = NitroHandle_LoadFileTables(&data_ov031_02291924.p->handle, NULL, 0);
	data_ov031_02291924.p->tableBuffer = func_ov031_0223d72c(capacity, 4);
	NitroHandle_LoadFileTables(&data_ov031_02291924.p->handle, data_ov031_02291924.p->tableBuffer, capacity);

	data_ov031_02291924.p->slotArray = func_ov031_0223c6cc(0x20, (int)data_ov031_02291924.p + 4, 4);

	char buf[0x80];
	func_020c8bfc((int)buf, (int)data_ov031_0224d15c, (int)data_ov031_02249f90);
	SetROMFilesystemRoot(buf);
}

#endif
