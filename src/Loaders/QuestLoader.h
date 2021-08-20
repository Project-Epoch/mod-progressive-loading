#ifndef _MOD_PROGRESSIVE_LOADING_QUEST_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_QUEST_LOADER_H_

#include "ScriptMgr.h"

class QuestLoader : public WorldScript
{
public:
    QuestLoader() : WorldScript("ProgressiveLoading_QuestLoader") {}

    /**
     * @brief Override the `quest_templates` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeQuestTemplatesQueried(std::string& query) override;

    void OnBeforeQuestTemplateAddonsQueried(std::string& query) override;

    // quest template addon
    // quest request items
    // quest offer reward
};

#endif