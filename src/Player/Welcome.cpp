#include "Welcome.h"
#include "../Progression.h"

void Welcome::OnLogin(Player* player)
{
    if (! sConfigMgr->GetOption<bool>("ProgressiveLoading.Welcome", true)) {
        return;
    }

    ChatHandler(player->GetSession()).PSendSysMessage("Emulating Patch - '%s'!", sProgression->GetPatchTitle().c_str());
}