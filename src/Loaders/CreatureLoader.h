#ifndef _MOD_PROGRESSIVE_LOADING_CREATURE_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_CREATURE_LOADER_H_

#include "ScriptMgr.h"

class CreatureLoader : public WorldScript
{
public:
    CreatureLoader() : WorldScript("ProgressiveLoading_CreatureLoader") {}

    /**
     * @brief Override the `creature_template` query with a progressive version.
     * 
     * @param query 
     */
    void OnBeforeCreatureTemplateQueried(std::string& query) override;

    /**
     * @brief Override the `creature_template_addon` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreatureTemplateAddonQueried(std::string& query) override;

    /**
     * @brief Override the `creature_template_spell` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreatureTemplateSpellsQueried(std::string& query) override;

    /**
     * @brief Override the `creature_template_resistance` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreatureTemplateResistancesQueried(std::string& query) override;

    /**
     * @brief Override the `creature_equip_template` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreatureEquipTemplateQueried(std::string& query) override;

    /**
     * @brief Override the `creature` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreaturesQueried(std::string& query) override;

    /**
     * @brief Based on the results of the `creature` query adjust the data that has been parsed by the core.
     * Actually handles the spawning of creatures in a way by setting phase mask.
     *
     * @param creatureData
     * @param fields
     */
    void OnAfterCreatureDataParsed(CreatureData& creatureData, Field* fields) override;

    /**
     * @brief When a creature is added to the grid we check to see if it should be in this patch.
     * If it is not then we remove it.
     * 
     * @param spawnId The guid of the creature that spawned.
     * @param creatureData The full data of the creature that spawned.
     */
    void OnAfterCreatureAddedToGrid(ObjectGuid::LowType spawnId, CreatureData const* creatureData) override;

    /**
     * @brief Override the `creature_addon` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeCreatureAddonsQueried(std::string& query) override;
};

#endif