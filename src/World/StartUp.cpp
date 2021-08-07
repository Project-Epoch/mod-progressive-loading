#include "StartUp.h"
#include "../Progression.h"

void StartUp::OnStartup()
{
    sLog->outString("\n>> Current content patch is set to %s (%u).\n", sProgression->GetPatchTitle().c_str(), sProgression->GetCurrentPatch());
}