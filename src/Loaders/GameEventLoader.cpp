#include "GameEventLoader.h"
#include "../Progression.h"

void GameEventLoader::OnBeforeGameEventsQueried(std::string& query)
{
    sLog->outError("OnBeforeGameEventsQueried Fired...");

    std::string table = "game_event";
    std::string field = "eventEntry";

    query = Acore::StringFormat(
        "SELECT eventEntry, UNIX_TIMESTAMP(start_time), UNIX_TIMESTAMP(end_time), occurence, length, holiday, holidayStage, description, world_event, announce "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}

void GameEventLoader::OnBeforeHolidayDatesQueried(std::string& query)
{
    sLog->outError("OnBeforeHolidayDatesQueried Fired...");

    std::string table = "holiday_dates";
    std::string field = "id";
    std::string min = "patch_min";
    std::string max = "patch_max";

    query = Acore::StringFormat(
        "SELECT id, date_id, date_value, holiday_duration "
        "FROM %s WHERE %s <= %u && %s >= %u",
        table, min, sProgression->GetCurrentPatch(), max, sProgression->GetCurrentPatch()
    );
}