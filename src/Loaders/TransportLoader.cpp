#include "TransportLoader.h"
#include "../Progression.h"

void TransportLoader::OnBeforeTransportsQueried(std::string& query)
{
    std::string table = "transports";
    std::string field = "entry";

    query = Acore::StringFormat(
        "SELECT guid, entry "
        "FROM %s t1 WHERE patch=(SELECT max(patch) FROM %s t2 WHERE t1.%s=t2.%s && patch <= %u)",
        table, table, field, field, sProgression->GetCurrentPatch()
    );
}