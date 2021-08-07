#ifndef _MOD_PROGRESSIVE_LOADING_START_UP_H_
#define _MOD_PROGRESSIVE_LOADING_START_UP_H_

#include "ScriptMgr.h"

/**
 * @brief World script that will just spit out current emulated patch.
 * 
 */
class StartUp : public WorldScript
{
public:
    StartUp() : WorldScript("ProgressiveLoading_StartUp") {}

    /**
     * @brief Output our emulated patch version into the world server console.
     *
     */
    void OnStartup() override;
};

#endif