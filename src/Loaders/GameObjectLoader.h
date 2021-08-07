#ifndef _MOD_PROGRESSIVE_LOADING_GAME_OBJECT_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_GAME_OBJECT_LOADER_H_

#include "ScriptMgr.h"

class GameObjectLoader : public WorldScript
{
public:
    GameObjectLoader() : WorldScript("ProgressiveLoading_GameObjectLoader") {}

    /**
     * @brief Override the `gameobject_template` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeGameObjectTemplateQueried(std::string& query) override;

    /**
     * @brief Override the `gameobject_template_addon` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeGameObjectTemplateAddonQueried(std::string& query) override;

    /**
     * @brief Override the `gameobject` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeGameObjectsQueried(std::string& query) override;

    /**
     * @brief Based on the results of the `gameobject` query adjust the data that has been parsed by the core.
     * Actually handles the spawning of game objects in a way by setting phase mask.
     *
     * @param creatureData
     * @param fields
     */
    void OnAfterGameObjectDataParsed(GameObjectData& gameObjectData, Field* fields) override;

    /**
     * @brief When a game object is added to the grid we check to see if it should be in this patch.
     * If it is not then we remove it.
     * 
     * @param guid The guid of the game object that spawned.
     * @param gameObjectData The full data of the game object that spawned.
     */
    void OnAfterGameObjectAddedToGrid(ObjectGuid::LowType guid, GameObjectData const* gameObjectData) override;

    /**
     * @brief Override the `gameobject_addon` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeGameObjectAddonsQueried(std::string& query) override;
};

#endif