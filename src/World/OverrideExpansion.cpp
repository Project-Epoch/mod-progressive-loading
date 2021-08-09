#include "OverrideExpansion.h"
#include "../Progression.h"

void OverrideExpansion::OnAfterConfigLoad(bool /*reload*/)
{
    uint32 expansion;

    if (sProgression->GetCurrentPatch() <= Patches::PATCH_DRUMS_OF_WAR)
    {
        expansion = Expansions::EXPANSION_CLASSIC;
    }
    else if (sProgression->GetCurrentPatch() >= Patches::PATCH_DARK_PORTAL_OPENS && sProgression->GetCurrentPatch() <= Patches::PATCH_FURY_OF_THE_SUNWELL)
    {
        expansion = Expansions::EXPANSION_THE_BURNING_CRUSADE;
    }
    else
    {
        expansion = Expansions::EXPANSION_WRATH_OF_THE_LICH_KING;
    }

    sWorld->setIntConfig(WorldIntConfigs::CONFIG_EXPANSION, expansion);
}