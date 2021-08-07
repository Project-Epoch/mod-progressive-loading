#include "CreatureLoader.h"
#include "../Progression.h"

void CreatureLoader::OnBeforeCreatureTemplateQueried(std::string& query)
{
    std::string table = "creature_template";
    std::string field = "entry";

    query = Acore::StringFormat(
        "SELECT entry, difficulty_entry_1, difficulty_entry_2, difficulty_entry_3, KillCredit1, KillCredit2, modelid1, modelid2, modelid3, "
        "modelid4, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, exp, faction, npcflag, speed_walk, speed_run, detection_range, "
        "scale, `rank`, dmgschool, DamageModifier, BaseAttackTime, RangeAttackTime, BaseVariance, RangeVariance, unit_class, unit_flags, unit_flags2, "
        "dynamicflags, family, trainer_type, trainer_spell, trainer_class, trainer_race, type, "
        "type_flags, lootid, pickpocketloot, skinloot, PetSpellDataId, VehicleId, mingold, maxgold, AIName, MovementType, "
        "InhabitType, HoverHeight, HealthModifier, ManaModifier, ArmorModifier, ExperienceModifier, RacialLeader, movementId, RegenHealth, mechanic_immune_mask, spell_school_immune_mask, flags_extra, ScriptName "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void CreatureLoader::OnBeforeCreatureTemplateAddonQueried(std::string& query)
{
    std::string table = "creature_template_addon";
    std::string field = "entry";

    query = Acore::StringFormat(
        "SELECT entry, path_id, mount, bytes1, bytes2, emote, isLarge, auras "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void CreatureLoader::OnBeforeCreatureTemplateSpellsQueried(std::string& query)
{
    std::string table = "creature_template_spell";
    std::string field = "CreatureID";

    query = Acore::StringFormat(
        "SELECT CreatureID, `Index`, Spell "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void CreatureLoader::OnBeforeCreatureTemplateResistancesQueried(std::string& query)
{
    std::string table = "creature_template_resistance";
    std::string field = "CreatureID";

    query = Acore::StringFormat(
        "SELECT CreatureID, School, Resistance "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void CreatureLoader::OnBeforeCreatureEquipTemplateQueried(std::string& query)
{
    std::string table = "creature_equip_template";
    std::string field = "CreatureID";

    query = Acore::StringFormat(
        "SELECT CreatureID, ID, ItemID1, ItemID2, ItemID3 "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void CreatureLoader::OnBeforeCreaturesQueried(std::string& query)
{
    std::string table = "creature";

    //              0              1   2    3        4             5           6           7           8            9              10
    query = "SELECT creature.guid, id, map, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, wander_distance, "
            //   11               12         13       14            15         16         17          18          19                20                   21                  22          23
            "currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask, eventEntry, pool_entry, creature.npcflag, creature.unit_flags, creature.dynamicflags, patch_min, patch_max "
            "FROM creature "
            "LEFT OUTER JOIN game_event_creature ON creature.guid = game_event_creature.guid "
            "LEFT OUTER JOIN pool_creature ON creature.guid = pool_creature.guid";
}

void CreatureLoader::OnAfterCreatureDataParsed(CreatureData& creatureData, Field* fields)
{
    /** Load needed fields */
    uint16 patchMin = fields[22].GetUInt16();
    uint16 patchMax = fields[23].GetUInt16();
    ObjectGuid::LowType spawnId = fields[0].GetUInt32();

    /** Ensure values are within bounds and warn if not with correction */
    if ((patchMin > patchMax) || (patchMax > PATCH_FINAL))
    {
        sLog->outErrorDb("Table `creature` GUID %u (entry %u) has invalid values min_patch=%u, max_patch=%u.", spawnId, creatureData.id, patchMin, patchMax);
        patchMin = PATCH_LAUNCH;
        patchMax = PATCH_FINAL - 1;
    }

    /** Not in patch, hide it. */
    if (!((sProgression->GetCurrentPatch() >= patchMin) && (sProgression->GetCurrentPatch() <= patchMax)))
    {
        creatureData.phaseMask = 0;
    }
}

void CreatureLoader::OnAfterCreatureAddedToGrid(ObjectGuid::LowType spawnId, CreatureData const* creatureData)
{
    if (creatureData->phaseMask == 0)
    {
        sObjectMgr->RemoveCreatureFromGrid(spawnId, creatureData);
    }
}

void CreatureLoader::OnBeforeCreatureAddonsQueried(std::string& query)
{
    std::string table = "creature_addon";
    std::string field = "guid";

    query = Acore::StringFormat(
        "SELECT guid, path_id, mount, bytes1, bytes2, emote, isLarge, auras "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}