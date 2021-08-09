#ifndef _MOD_PROGRESSIVE_LOADING_GAME_EVENT_LOADER_H_
#define _MOD_PROGRESSIVE_LOADING_GAME_EVENT_LOADER_H_

#include "ScriptMgr.h"

class GameEventLoader : public WorldScript
{
public:
    GameEventLoader() : WorldScript("ProgressiveLoading_GameEventLoader") {}

    /**
     * @brief Override the `game_event` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeGameEventsQueried(std::string& query) override;

    /**
     * @brief Override the `holiday_dates` query with a progressive version.
     *
     * @param query
     */
    void OnBeforeHolidayDatesQueried(std::string& query) override;
};

#endif