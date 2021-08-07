#ifndef _MOD_PROGRESSIVE_LOADING_TRANSPORT_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_TRANSPORT_LOADER_H_

#include "ScriptMgr.h"

class TransportLoader : public WorldScript
{
public:
    TransportLoader() : WorldScript("ProgressiveLoading_TransportLoader") {}

    /**
     * @brief Override the `transports` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeTransportsQueried(std::string& query) override;
};

#endif