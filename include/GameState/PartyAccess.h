#pragma once

class GameState;

void* GetPtrField0x2a04_02010828(GameState* gameState);

// The binary getter returns GameState's embedded party storage.
// T is the caller's existing view of that storage, not a different allocation.
template <class T>
inline T* GetPtrField0x2a04_02010828(GameState* gameState) {
    return static_cast<T*>(GetPtrField0x2a04_02010828(gameState));
}
