#if defined(jpn)
#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct BattleScriptPairCommand {
    unsigned int opcode;
    BattleScriptPairCommand* next;
    unsigned int hasPrimary : 1;
    unsigned int primary : 15;
    unsigned int useDefaultSecondary : 1;
    unsigned int hasSecondary : 1;
    unsigned int unknownFlags : 14;
    unsigned int secondary : 15;
    unsigned int unknownSecondary : 17;
};
struct BattleCommandQueueView {
    void* unknown00;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern BattleCommandQueueView data_ov000_02185364;
    void func_ov000_0216b2a4(BattleScriptPairCommand*);
}

// JPN: func_ov000_0216cc90
// Parses battle script tag 0x37 into a queued two-parameter command.
// The game meaning of these parameters is not yet established from the JP consumer.
extern "C" ARM int func_ov000_0216cc90(Script::Parameter* parameters, int parameterCount)
{
    BattleScriptPairCommand* command = static_cast<BattleScriptPairCommand*>(
        data_ov000_02185364.allocator->Allocate(sizeof(BattleScriptPairCommand)));
    if (!command)
        return 0;
    command->opcode = 0;
    command->next = NULL;
    command->opcode = 0x37;
    int primary = parameters[0].ToInt();
    if (primary < 0) {
        command->hasPrimary = 0;
    } else if (primary == 0) {
        command->hasPrimary = 1;
        command->primary = 1;
    } else {
        command->hasPrimary = 1;
        command->primary = primary;
    }
    command->useDefaultSecondary = 1;
    command->hasSecondary = 0;
    command->secondary = 0;
    if (parameterCount >= 2) {
        int secondary = parameters[1].ToInt();
        if (secondary >= 0) {
            command->useDefaultSecondary = 0;
            command->hasSecondary = 1;
            command->secondary = secondary;
        } else if (secondary != -2) {
            command->useDefaultSecondary = 0;
            command->hasSecondary = 0;
            command->secondary = 0;
        }
    }
    func_ov000_0216b2a4(command);
    return 1;
}

#endif
