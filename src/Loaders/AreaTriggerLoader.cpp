#include "AreaTriggerLoader.h"
#include "../Progression.h"

void AreaTriggerLoader::OnBeforeAreaTriggerTeleportsQueried(std::string& query)
{
    std::string table = "areatrigger_teleport";
    std::string field = "ID";

    query = Acore::StringFormat(
        "SELECT ID, target_map, target_position_x, target_position_y, target_position_z, target_orientation "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}