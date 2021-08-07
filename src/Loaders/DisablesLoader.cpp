#include "DisablesLoader.h"
#include "../Progression.h"

void DisablesLoader::OnBeforeDisablesQueried(std::string& query)
{
    std::string table = "disables";
    std::string min = "patch_min";
    std::string max = "patch_max";

    query = Acore::StringFormat(
        "SELECT sourceType, entry, flags, params_0, params_1 "
        "FROM %s WHERE %s <= %u && %s >= %u",
        table, min, sProgression->GetCurrentPatch(), max, sProgression->GetCurrentPatch()
    );
}