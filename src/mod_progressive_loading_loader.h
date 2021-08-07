#ifndef _MOD_PROGRESSIVE_LOADING_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_LOADER_H_

#include "./World/StartUp.h"
#include "./Player/Welcome.h"

// Add all
void AddModProgressiveLoadingScripts()
{
    new StartUp();
    new Welcome();
}

#endif // _MOD_PROGRESSIVE_LOADING_LOADER_H_