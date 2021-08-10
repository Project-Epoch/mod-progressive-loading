#include "PatchCondition.h"
#include "../Progression.h"

bool PatchCondition::OnConditionCheck(Condition* condition, ConditionSourceInfo& /*sourceInfo*/)
{
    uint32 patch = condition->ConditionValue1;
    uint32 comparison = condition->ConditionValue2;

    if (! IsValid(condition, patch, comparison))
    {
        return false;
    }

    switch (comparison)
    {
        case 0: // Equals ==
            return sProgression->GetCurrentPatch() == patch;
        case 1: // Greater Than or Equal To >=
            return sProgression->GetCurrentPatch() >= patch;
        case 2: // Less Than or Equal To <=
            return sProgression->GetCurrentPatch() <= patch;
    }

    return false;
}

bool PatchCondition::IsValid(Condition* condition, uint32 patch, uint32 comparison)
{
    if (patch < Patches::PATCH_LAUNCH || patch > Patches::PATCH_FINAL)
    {
        sLog->outErrorDb(
            "Invalid patch %u for progressive loading condition. Source Type: %u Source Group: %u Source Entry: %u", 
            patch, condition->SourceType, condition->SourceGroup, condition->SourceEntry
        );

        return false;
    }

    if (comparison > 2)
    {
        sLog->outErrorDb(
            "Invalid comparison %u for progressive loading condition. Source Type: %u Source Group: %u Source Entry: %u", 
            comparison, condition->SourceType, condition->SourceGroup, condition->SourceEntry
        );

        return false;
    }

    return true;
}