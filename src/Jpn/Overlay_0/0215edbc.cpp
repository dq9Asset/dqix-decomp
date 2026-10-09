#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct CombatStats {
    char pad0[0xc];
    unsigned short power;
    char pad1[0x2a - 0xe];
    short target2a;
    short target2c;
    char pad2[0x36 - 0x2e];
    short skill36;
    char pad3[0x3b - 0x38];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
};

struct Combatant {
    char pad0[0x138];
    CombatStats* stats;
    char pad1[0x184 - 0x13c];
    unsigned char busy;
};

struct ActionEntry {
    char pad0[0x1c];
    short f1c;
    short pad1e;
    unsigned short id;
    char pad22[0x30 - 0x22];
    int f30;
};

struct TargetNode {
    char pad0[0xe];
    short id;
    char pad10[0x17 - 0x10];
    unsigned char active;
    char pad18[0x24 - 0x18];
};

struct ActionNode {
    unsigned short action;
    char pad2[6];
    unsigned char entryCount;
    unsigned char targetCount;
    char pada[6];
    ActionEntry* entry;
    char pad14[0x28 - 0x14];
};

struct SkillData {
    char pad0[4];
    unsigned int kind : 12;
    char pad8[0x10 - 8];
    unsigned int flags;
    char pad14[0x18 - 0x14];
    unsigned int lo18 : 5;
    unsigned int type : 7;
    char pad1c[0x30 - 0x1c];
    short linked;
};

struct PartyInfo {
    unsigned short action;
    unsigned char target;
    char pad3;
    unsigned char flags;
};

struct Battle {
    char pad0[0x8e00];
    unsigned char tableCount;
    char pad8e01[0x8e14 - 0x8e01];
    signed char aborted;
    char pad8e15[0x8e18 - 0x8e15];
    char* field8e18;
    char pad8e1c[4];
    int field8e20;
    int workCount;
    char pad8e28[0x8e49 - 0x8e28];
    unsigned char mode;
    char pad8e4a[0x8e70 - 0x8e4a];
    ActionEntry* entries;
    TargetNode* targets;
    ActionNode* actions;
    int actionCount;
    unsigned char entryCount;
    unsigned char targetCount;
};

struct IdList { short v[16]; };
struct TargetList { short v[8]; };
struct PartyList { signed char v[4]; };
struct Candidate { int id; float weight; };
struct Sim { char buf[0x7c]; };
struct Big { char buf[0x678]; };

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" Combatant* _ZN9GameState19GetCombatantByIndexEi(void* gs, int id);
extern "C" char* func_0207a6d0(void);
extern "C" int func_ov000_021555c0(void* obj, short* buf, int max, int start);
extern "C" void _Z21UpdateCombatantAttackii(void* self, int id);
extern "C" void _Z22UpdateCombatantDefenseii(void* self, int id);
extern "C" void _Z22UpdateCombatantAgilityii(void* self, int id);
extern "C" void _Z20UpdateCombatantCharmii(void* self, int id);
extern "C" void _Z27UpdateCombatantMagicalMightii(void* self, int id);
extern "C" void _Z29UpdateCombatantMagicalMendingii(void* self, int id);
extern "C" void func_ov024_021f6fc4(void);
extern "C" void __clear(void* buf, int n);
extern "C" int _Z13NextRandomMaxP6Randomi(void* rng, int max);
extern "C" int func_ov000_021613e0(void* self);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void* rng, float lo, float hi);
extern "C" void func_02075b38(void* arr, int lo, int hi, int mode);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* alloc, unsigned int size);
extern "C" void _ZN13SafeAllocator4FreeEPv(void* alloc, void* p);
extern "C" Combatant* func_0200fd78(void* gs, int id);
extern "C" Combatant* func_0200fd00(void* gs, int id);
extern "C" PartyInfo* func_02055138(Combatant* c);
extern "C" void func_020ddf50(signed char id, signed char* out, signed char* count);
extern "C" void func_ov000_021617b0(void* obj);
extern "C" void func_ov000_02159494(ActionEntry* e);
extern "C" void func_ov000_0215945c(void* obj);
extern "C" int func_ov000_0215771c(void* self, int id, int checkSub);
extern "C" void func_ov024_021f7b84(Big* b);
extern "C" void func_ov024_021f97fc(Big* b, void* self, int id, ActionNode* node);
extern "C" int func_ov000_0215b514(void* self, int id);
extern "C" void func_0208b204(int* out);
extern "C" int func_0208b210(int* p0, void* self, int id, int* outCount, short* outTargets);
extern "C" SkillData* func_0207ac64(char* data, int id);
extern "C" void* func_0207203c(void* container, int key);
extern "C" void func_0204969c(Combatant* c, void* e);
extern "C" void func_ov000_0216184c(ActionNode* obj, TargetNode* node);
extern "C" void func_ov000_021617e8(ActionNode* obj, ActionEntry* node);
extern "C" int func_ov000_02160cfc(void* self, int id);
extern "C" void func_ov000_02160890(void* self);
extern "C" void func_ov000_0216092c(void* self);
extern "C" int func_0200fee4(Combatant* c);
extern "C" int func_ov000_0215538c(Combatant* c);
extern "C" int func_ov000_0215b15c(Combatant* c);
extern "C" ActionNode* func_ov000_02160158(void* self);
extern "C" ActionEntry* func_ov000_02160098(void* self);
extern "C" TargetNode* func_ov000_02161878(ActionNode* list, int index);
extern "C" ActionEntry* func_ov000_02161814(ActionNode* list, int index);
extern "C" void func_ov000_02158dfc(void* self, ActionNode* src, ActionNode* dst);
extern "C" void func_ov024_021ebcdc(Sim* s);
extern "C" void func_ov024_021ebd9c(Sim* s, void* self, ActionNode* a, ActionNode* b, int mode);
extern "C" void func_ov000_021594bc(void* self, ActionNode* a, int flag);
extern "C" void func_ov000_0215d6dc(void* self, ActionNode* a);
extern "C" void func_ov000_0215d33c(void* self, ActionNode* a);
extern "C" void func_ov000_0215da50(void* self, ActionNode* a);
extern "C" void func_ov000_0215c9f8(void* self, ActionNode* a);
extern "C" void func_ov000_0215c600(void* self);
extern "C" void func_ov000_0215cd20(void* self, ActionNode* a);
extern "C" void func_ov000_0215c308(void* self);
extern "C" void func_ov000_0215c918(void* self);
extern "C" void func_ov000_0215dc4c(void* self);

extern IdList data_ov000_02183dec;
extern PartyList data_ov000_02183b18;
extern TargetList data_ov000_02183c5c;
extern TargetList data_ov000_02183bbc;

static inline Combatant* GetCombatant(int id) {
    GameState* bs = GameState::GetInstance();
    return (Combatant*)bs->GetCombatantByIndex(id);
}

static inline Combatant* GetFlagged0x400(int id) {
    GameState* bs = GameState::GetInstance();
    return func_0200fd00(bs, id);
}

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_ov000_0215edbc
extern "C" ARM void ProcessCombatTurn(Battle* self, SafeAllocator* alloc) {
    long j;
    void* gs = _ZN9GameState11GetInstanceEv();
    char* data = func_0207a6d0();
    IdList ids = data_ov000_02183dec;
    long count = func_ov000_021555c0(self, ids.v, 0x10, 1);

    for (long i = 0; i < count; i++) {
        int id = ids.v[i];
        _Z21UpdateCombatantAttackii(self, id);
        _Z22UpdateCombatantDefenseii(self, id);
        _Z22UpdateCombatantAgilityii(self, id);
        _Z20UpdateCombatantCharmii(self, id);
        _Z27UpdateCombatantMagicalMightii(self, id);
        _Z29UpdateCombatantMagicalMendingii(self, id);
    }

    func_ov024_021f6fc4();

    Candidate cands[16];
    __clear(cands, sizeof(cands));
    unsigned char n = 0;
    for (long i = 0; i < count; i++) {
        short id = ids.v[i];
        Combatant* c = GetCombatant(id);
        if (c == 0) {
            continue;
        }
        if (self->field8e20 == 0) {
            if (self->mode == 2) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (party) {
                    continue;
                }
                if (n != 0 && _Z13NextRandomMaxP6Randomi(self, 100) >= 0x43) {
                    continue;
                }
            } else if (self->mode == 1) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (!party) {
                    continue;
                }
            }
        }
        if (func_ov000_021613e0(self) != 0) {
            int id = ids.v[i];
            int party = 0;
            if (!(id < 0 || id > 3)) {
                party = 1;
            }
            if (party && id != 0) {
                continue;
            }
        }
        cands[n].id = ids.v[i];
        unsigned int power = c->stats->power;
        cands[n].weight = (float)power * _Z22NextRandomFloatBetweenP6Randomff(self, 0.51f, 1.0f);
        n++;
    }

    count = n;
    func_02075b38(cands, 0, n - 1, 1);
    memset(&ids, 0, sizeof(ids));
    for (j = 0; j < count; j++) {
        ids.v[j] = cands[j].id;
    }

    self->entries = (ActionEntry*)alloc->Allocate(0x48 * sizeof(ActionEntry));
    self->entryCount = 0;
    self->targets = (TargetNode*)alloc->Allocate(0x88 * sizeof(TargetNode));
    self->targetCount = 0;
    self->actions = (ActionNode*)alloc->Allocate(0x48 * sizeof(ActionNode));
    self->actionCount = 0;

    for (long i = 0; i < count; i++) {
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Combatant* c = func_0200fd78(gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = func_02055138(c);
                if (info != 0 && (info->flags & 1)) {
                    PartyList members = data_ov000_02183b18;
                    signed char partyCount = 0;
                    func_020ddf50(ids.v[i], members.v, &partyCount);
                    for (unsigned int j = 0; j < partyCount; j++) {
                        Combatant* m = func_0200fd78(gs, members.v[j]);
                        if (m != 0) {
                            PartyInfo* mi = func_02055138(m);
                            if (mi != 0) {
                                mi->flags |= 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (long i = 0; i < count; i++) {
        ActionNode* node = &self->actions[self->actionCount];
        func_ov000_021617b0(node);
        node->entryCount = 1;
        node->entry = &self->entries[self->entryCount];
        func_ov000_02159494(node->entry);
        node->entry->id = ids.v[i];

        TargetList targets = data_ov000_02183c5c;
        int numTargets = 0;
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Combatant* c = func_0200fd78(gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = func_02055138(c);
                if (info != 0 && (info->flags & 1)) {
                    continue;
                }
            }
        }

        if (func_ov000_0215771c(self, ids.v[i], 1) != 0) {
            node->action = 0x1f7;
        } else {
            node->action = 2;
            int party = 0;
            if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                party = 1;
            }
            if (party) {
                Combatant* c = func_0200fd78(gs, ids.v[i]);
                if (c != 0) {
                    PartyInfo* info = func_02055138(c);
                    if (info != 0) {
                        node->action = info->action;
                    }
                    if (node->action == 0) {
                        continue;
                    }
                    Big big;
                    func_ov024_021f7b84(&big);
                    func_ov024_021f97fc(&big, self, ids.v[i], node);
                    if (node->action == 0x92) {
                        int target = info->target;
                        Combatant* t = GetCombatant(target);
                        if (t != 0) {
                            t->stats->target2c = ids.v[i];
                        }
                        c->stats->target2a = info->target;
                        numTargets = 1;
                        targets.v[0] = info->target;
                    }
                }
            } else {
                int kind = func_ov000_0215b514(self, (short)node->entry->id);
                int selfId = (short)node->entry->id;
                Combatant* me = GetFlagged0x400(selfId);
                if (kind != 2) {
                    int work;
                    func_0208b204(&work);
                    node->action = func_0208b210(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                    SkillData* sk = func_0207ac64(data, (short)node->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = func_0207203c(self->field8e18 + 0x684, sk->linked);
                            if (e != 0) {
                                func_0204969c(me, e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets.v, -1, sizeof(targets));
                            numTargets = 0;
                            node->action = func_0208b210(&work, self, (unsigned short)node->entry->id, &numTargets, targets.v);
                            sk = func_0207ac64(data, (short)node->action);
                            if (sk == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node->action == 0x92 || node->action == 0x3a1) {
                    Combatant* t = GetCombatant(targets.v[0]);
                    if (t != 0) {
                        t->stats->target2c = ids.v[i];
                    }
                    me->stats->target2a = targets.v[0];
                }
            }
        }

        node->targetCount = 0;
        for (int j = 0; j < numTargets; j++) {
            TargetNode* tn = &self->targets[self->targetCount];
            func_ov000_0215945c(tn);
            tn->id = targets.v[j];
            tn->active = 1;
            func_ov000_0216184c(node, tn);
            self->targetCount++;
        }
        self->actionCount++;
        self->entryCount++;

        int extra = func_ov000_02160cfc(self, ids.v[i]);
        for (int k = 0; k < extra; k++) {
            ActionNode* node2 = &self->actions[self->actionCount];
            func_ov000_021617b0(node2);
            node2->entryCount = 1;
            node2->entry = &self->entries[self->entryCount];
            func_ov000_02159494(node2->entry);
            node2->entry->id = ids.v[i];

            TargetList targets2 = data_ov000_02183bbc;
            int numTargets2 = 0;
            if (func_ov000_0215771c(self, ids.v[i], 1) != 0) {
                node2->action = 0x1f7;
            } else {
                node2->action = 2;
                int kind = func_ov000_0215b514(self, (short)node2->entry->id);
                Combatant* me = func_0200fd00(gs, node2->entry->id);
                if (kind != 2) {
                    int work2;
                    func_0208b204(&work2);
                    node2->action = func_0208b210(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                    SkillData* sk = func_0207ac64(data, (short)node2->action);
                    if (sk != 0) {
                        while (sk->type == 0x22) {
                            void* e = func_0207203c(self->field8e18 + 0x684, sk->linked);
                            if (e != 0) {
                                func_0204969c(me, e);
                                me->stats->skill36 = sk->linked;
                            }
                            memset(targets2.v, -1, sizeof(targets2));
                            numTargets2 = 0;
                            node2->action = func_0208b210(&work2, self, (unsigned short)node2->entry->id, &numTargets2, targets2.v);
                            sk = func_0207ac64(data, (short)node2->action);
                            if (sk == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node2->action == 0x92 || node2->action == 0x3a1) {
                    Combatant* t = GetCombatant(targets2.v[0]);
                    if (t != 0) {
                        t->stats->target2c = node2->entry->id;
                    }
                    me->stats->target2a = targets2.v[0];
                }
            }

            node2->targetCount = 0;
            for (int j = 0; j < numTargets2; j++) {
                TargetNode* tn = &self->targets[self->targetCount];
                func_ov000_0215945c(tn);
                tn->id = targets2.v[j];
                tn->active = 1;
                func_ov000_0216184c(node2, tn);
                self->targetCount++;
            }
            self->actionCount++;
            self->entryCount++;
        }
    }

    func_ov000_02160890(self);
    func_ov000_0216092c(self);

    for (j = 0; j < self->actionCount; j++) {
        ActionNode* node = &self->actions[j];
        int id = (short)node->entry->id;
        Combatant* c = GetCombatant(id);
        if (c == 0) {
            continue;
        }
        if (func_0200fee4(c) != 0) {
            continue;
        }
        if (c->stats->flag2) {
            continue;
        }
        if (func_ov000_0215538c(c) != 0) {
            continue;
        }
        if (c->stats->flag0) {
            continue;
        }
        int party = (node->entry->id >= 0 && node->entry->id <= 3) ? 1 : 0;
        if (!party) {
            Combatant* m = GetFlagged0x400((short)node->entry->id);
            if (m != 0 && m->busy != 0) {
                continue;
            }
        }

        int modFlag = func_ov000_0215b15c(c);
        ActionNode* w = func_ov000_02160158(self);
        if (w == 0) {
            break;
        }
        func_ov000_021617b0(w);
        func_ov000_02158dfc(self, node, w);
        Sim sim;
        func_ov024_021ebcdc(&sim);
        func_ov024_021ebcdc(&sim);
        func_ov024_021ebd9c(&sim, self, w, node, 0);
        if (func_ov000_0215771c(self, ids.v[j], 1) != 0) {
            modFlag = 0;
        }
        func_ov000_021594bc(self, w, modFlag);
        self->workCount++;
        if (self->aborted != 0) {
            func_ov000_0215d6dc(self, w);
            func_ov000_0215d33c(self, w);
            func_ov000_0215da50(self, w);
            break;
        }

        func_ov000_0215c9f8(self, w);
        if (modFlag == 0) {
            func_ov000_0215d6dc(self, w);
        }
        func_ov000_0215c600(self);
        func_ov000_0215cd20(self, w);
        func_ov000_0215c308(self);
        func_ov000_0215c918(self);
        if (modFlag == 0) {
            func_ov000_0215d33c(self, w);
            func_ov000_0215da50(self, w);
        }
        func_ov000_0215dc4c(self);
        if (modFlag == 0) {
            continue;
        }

        SkillData* sk = func_0207ac64(func_0207a6d0(), (short)w->action);
        int again = 1;
        if (sk != 0 && (sk->flags & 0x400) && sk->kind != 0x1c) {
            ActionNode* echo = &self->actions[0x47];
            ActionNode* w2 = func_ov000_02160158(self);
            if (w2 != 0) {
                func_ov000_021617b0(w2);
                func_ov000_021617b0(echo);
                w2->action = echo->action = w->action;
                for (int j = 0; j < w->targetCount; j++) {
                    TargetNode* src = func_ov000_02161878(w, j);
                    int srcId = src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        continue;
                    }
                    if (func_0200fee4(t) != 0) {
                        continue;
                    }
                    if (func_ov000_0215538c(t) != 0) {
                        break;
                    }
                    TargetNode* tn = &self->targets[self->targetCount];
                    func_ov000_0215945c(tn);
                    tn->id = src->id;
                    tn->active = 1;
                    func_ov000_0216184c(echo, tn);
                    self->targetCount++;
                }
                for (int k = 0; k < w->entryCount; k++) {
                    ActionEntry* src = func_ov000_02161814(w, k);
                    int srcId = (short)src->id;
                    Combatant* t = GetCombatant(srcId);
                    if (t == 0) {
                        break;
                    }
                    if (func_0200fee4(t) != 0) {
                        break;
                    }
                    if (func_ov000_0215538c(t) != 0) {
                        break;
                    }
                    ActionEntry* e = func_ov000_02160098(self);
                    if (e == 0) {
                        break;
                    }
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    func_ov000_021617e8(w2, e);
                    self->tableCount++;
                    e = &self->entries[self->entryCount];
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->f30 = 0;
                    e->id = src->id;
                    func_ov000_021617e8(echo, e);
                    self->entryCount++;
                }
                if (echo->targetCount != 0 && w->entryCount == w2->entryCount) {
                    again = 0;
                    Sim sim2;
                    func_ov024_021ebcdc(&sim2);
                    func_ov024_021ebcdc(&sim2);
                    func_ov024_021ebd9c(&sim2, self, w2, echo, 1);
                    func_ov000_021594bc(self, w2, 0);
                    self->workCount++;
                    if (self->aborted == 0) {
                        func_ov000_0215c9f8(self, w);
                    }
                    func_ov000_0215d6dc(self, w);
                    if (self->aborted == 0) {
                        func_ov000_0215c600(self);
                        func_ov000_0215cd20(self, w2);
                        func_ov000_0215c308(self);
                        func_ov000_0215c918(self);
                    }
                    func_ov000_0215d33c(self, w2);
                    func_ov000_0215da50(self, w2);
                    if (self->aborted == 0) {
                        func_ov000_0215dc4c(self);
                    }
                }
            }
        }
        if (again) {
            func_ov000_021594bc(self, w, 0);
            func_ov000_0215d6dc(self, w);
            func_ov000_0215d33c(self, w);
            func_ov000_0215da50(self, w);
        }
        if (self->aborted != 0) {
            break;
        }
    }

    alloc->Free(self->actions);
    alloc->Free(self->targets);
    alloc->Free(self->entries);
    self->entries = 0;
    self->entryCount = 0;
    self->targets = 0;
    self->targetCount = 0;
    self->actions = 0;
    self->actionCount = 0;
}

#endif
