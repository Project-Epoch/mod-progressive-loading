#include "BattlegroundLoader.h"
#include "../Progression.h"

void BattlegroundLoader::OnBeforeBattleGroundTemplatesQueried(std::string& query)
{
    std::string table = "battleground_template";
    std::string field = "ID";

    query = Acore::StringFormat(
        "SELECT ID, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, StartMaxDist, Weight, ScriptName "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}