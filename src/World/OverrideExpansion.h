#ifndef _MOD_PROGRESSIVE_LOADING_OVERRIDE_EXPANSION_H_
#define _MOD_PROGRESSIVE_LOADING_OVERRIDE_EXPANSION_H_

#include "ScriptMgr.h"

/**
 * @brief Depending on the patch we're emulating this will override the cores `Expansion` config.
 * 
 */
class OverrideExpansion : public WorldScript
{
public:
    OverrideExpansion() : WorldScript("ProgressiveLoading_OverrideExpansion") {}

    /**
     * @brief Override some configs based on our progressive version.
     *
     */
    void OnAfterConfigLoad(bool reload) override;
};

#endif