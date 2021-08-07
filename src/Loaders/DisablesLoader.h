#ifndef _MOD_PROGRESSIVE_LOADING_DISABLES_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_DISABLES_LOADER_H_

#include "ScriptMgr.h"

class DisablesLoader : public WorldScript
{
public:
    DisablesLoader() : WorldScript("ProgressiveLoading_DisablesLoader") {}

    /**
     * @brief Override the `disables` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeDisablesQueried(std::string& query) override;
};

#endif