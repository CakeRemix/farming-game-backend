#include "plant.h"
#include "game.h"

int plant::GetTime() {
    return RemainingTime;
}

bool plant::decrement(int &PassedTime,int (&storage)[6]) {
    RemainingTime -= PassedTime;
    PassedTime=0;
    if (RemainingTime <= 0){
        store(type,storage);
        delete this;
        return true;
    }
    return false;
}
