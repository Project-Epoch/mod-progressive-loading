
#include "ScriptMgr.h"

class ItemLoader : public WorldScript
{
public:
    ItemLoader() : WorldScript("ProgressiveLoading_ItemLoader") {}

    /**
     * @brief Override the `item_template` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeItemTemplatesQueried(std::string& query) override;

        /**
     * @brief Override a `*_loot_template` query with a progressive version.
     * 
     * @param query
     * @param lootStoreName
     */
    void OnBeforeLootTemplateQueried(std::string& query, std::string lootStoreName) override;
};