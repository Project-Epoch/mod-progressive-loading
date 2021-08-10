#ifndef _MOD_PROGRESSIVE_LOADING_AREA_TRIGGER_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_AREA_TRIGGER_LOADER_H_

#include "ScriptMgr.h"

class AreaTriggerLoader : public WorldScript
{
public:
    AreaTriggerLoader() : WorldScript("ProgressiveLoading_AreaTriggerLoader") {}

    /**
     * @brief Override the `areatrigger_teleports` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeAreaTriggerTeleportsQueried(std::string& query) override;
};

#endif