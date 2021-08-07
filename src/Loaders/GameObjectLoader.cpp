#include "GameObjectLoader.h"
#include "../Progression.h"

void GameObjectLoader::OnBeforeGameObjectTemplateQueried(std::string& query)
{
    std::string table = "gameobject_template";
    std::string field = "entry";

    query = Acore::StringFormat(
        "SELECT entry, type, displayId, name, IconName, castBarCaption, unk1, size, "
        "Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Data8, Data9, Data10, Data11, Data12, "
        "Data13, Data14, Data15, Data16, Data17, Data18, Data19, Data20, Data21, Data22, Data23, AIName, ScriptName "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void GameObjectLoader::OnBeforeGameObjectTemplateAddonQueried(std::string& query)
{    
    std::string table = "gameobject_template_addon";
    std::string field = "entry";

    query = Acore::StringFormat(
        "SELECT entry, faction, flags, mingold, maxgold "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void GameObjectLoader::OnBeforeGameObjectsQueried(std::string& query)
{
    std::string table = "gameobject";

    //               0                1   2    3           4           5           6
    query = "SELECT gameobject.guid, id, map, position_x, position_y, position_z, orientation, "
            //   7          8          9          10         11             12            13     14         15         16          17       18         19
            "rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, spawnMask, phaseMask, eventEntry, pool_entry, patch_min, patch_max "
            "FROM gameobject LEFT OUTER JOIN game_event_gameobject ON gameobject.guid = game_event_gameobject.guid "
            "LEFT OUTER JOIN pool_gameobject ON gameobject.guid = pool_gameobject.guid";
}

void GameObjectLoader::OnAfterGameObjectDataParsed(GameObjectData& gameObjectData, Field* fields)
{
    /** Load needed fields */
    uint16 patchMin = fields[18].GetUInt16();
    uint16 patchMax = fields[19].GetUInt16();
    ObjectGuid::LowType guid = fields[0].GetUInt32();

    /** Ensure values are within bounds and warn if not with correction */
    if ((patchMin > patchMax) || (patchMax > PATCH_FINAL))
    {
        sLog->outErrorDb("Table `gameobject` GUID %u (entry %u) has invalid values min_patch=%u, max_patch=%u.", guid, gameObjectData.id, patchMin, patchMax);
        patchMin = PATCH_LAUNCH;
        patchMax = PATCH_FINAL - 1;
    }

    /** Not in patch, hide it. */
    if (!((sProgression->GetCurrentPatch() >= patchMin) && (sProgression->GetCurrentPatch() <= patchMax)))
    {
        gameObjectData.phaseMask = 0;
    }
}

void GameObjectLoader::OnAfterGameObjectAddedToGrid(ObjectGuid::LowType guid, GameObjectData const* gameObjectData)
{
    if (gameObjectData->phaseMask == 0)
    {
        sObjectMgr->RemoveGameobjectFromGrid(guid, gameObjectData);
    }
}

void GameObjectLoader::OnBeforeGameObjectAddonsQueried(std::string& query)
{
    std::string table = "gameobject_addon";
    std::string field = "guid";

    query = Acore::StringFormat(
        "SELECT guid, invisibilityType, invisibilityValue "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}