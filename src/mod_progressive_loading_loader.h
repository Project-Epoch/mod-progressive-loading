#ifndef _MOD_PROGRESSIVE_LOADING_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_LOADER_H_

#include "./World/StartUp.h"
#include "./Player/Welcome.h"
#include "./Loaders/CreatureLoader.h"
#include "./Loaders/GameObjectLoader.h"
#include "./Loaders/ItemLoader.h"
#include "./Loaders/TransportLoader.h"
#include "./Loaders/DisablesLoader.h"
#include "./Loaders/GameEventLoader.h"

// Add all
void AddModProgressiveLoadingScripts()
{
    new StartUp();
    new Welcome();

    /** Loaders */
    new CreatureLoader();
    new GameObjectLoader();
    new ItemLoader();
    new TransportLoader();
    new DisablesLoader();
    new GameEventLoader();
}

#endif // _MOD_PROGRESSIVE_LOADING_LOADER_H_