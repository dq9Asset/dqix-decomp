#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"
#include "System/Memory.h"
#include "GameState/GameState.h"

void* GetField0x649eForValidIndex_02011aa0(char* base, unsigned int index);

// USA: func_ov004_02165d74
ARM int SetIndexedNameFromField_02165d74_02165d74(void* a) {
    MessageSystem* g = GetGlobalField0x1c020421a0();
    func_02046380(g);
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetUnknownGameObject();
    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);
    strcpy(buf, (char*)GetField0x649eForValidIndex_02011aa0((char*)bs, 0));
    if (combatant != NULL) {
        SetIndexedName02046574(g, 0, *(char**)((char*)combatant + 0x134));
    }
    CopyStringToIndexedField0x2ec_020464e8(g, 0, buf);
    return 0;
}
