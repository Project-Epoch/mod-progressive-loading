#ifndef _MOD_PROGRESSIVE_LOADING_WELCOME_H_
#define _MOD_PROGRESSIVE_LOADING_WELCOME_H_

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class Welcome : public PlayerScript
{
public:
    Welcome() : PlayerScript("ProgressiveLoading_Welcome") { }

    void OnLogin(Player* player) override;
};

#endif