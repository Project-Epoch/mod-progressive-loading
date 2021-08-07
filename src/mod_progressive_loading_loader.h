#ifndef _MOD_PROGRESSIVE_LOADING_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_LOADER_H_

#include "./World/StartUp.h"
#include "./Player/Welcome.h"
#include "./Loaders/CreatureLoader.h"
#include "./Loaders/GameObjectLoader.h"

// Add all
void AddModProgressiveLoadingScripts()
{
    new StartUp();
    new Welcome();

    /** Loaders */
    new CreatureLoader();
    new GameObjectLoader();
}

#endif // _MOD_PROGRESSIVE_LOADING_LOADER_H_