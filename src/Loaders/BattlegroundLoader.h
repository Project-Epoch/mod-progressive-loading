#ifndef _MOD_PROGRESSIVE_LOADING_BATTLEGROUND_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_BATTLEGROUND_LOADER_H_

#include "ScriptMgr.h"

class BattlegroundLoader : public WorldScript
{
public:
    BattlegroundLoader() : WorldScript("ProgressiveLoading_BattlegroundLoader") {}

    /**
     * @brief Override the `battleground_template` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeBattleGroundTemplatesQueried(std::string& query) override;
};

#endif