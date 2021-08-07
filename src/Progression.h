#ifndef _MOD_PROGRESSIVE_LOADING_PROGRESSION_H_
#define _MOD_PROGRESSIVE_LOADING_PROGRESSION_H_

#include <string>
#include "Define.h"
#include "Config.h"
#include <memory>

/** Client Build Numbers */
enum Patches
{
    /** Classic */
    PATCH_LAUNCH = 4125,
    PATCH_MYSTERIES_OF_MARAUDON = 4149,
    PATCH_RUINS_OF_THE_DIRE_MAUL = 4284,
    PATCH_CALL_TO_WAR = 4341,
    PATCH_BATTLEGROUNDS = 4442,
    PATCH_ASSAULT_ON_BLACKWING_LAIR = 4500,
    PATCH_RISE_OF_THE_BLOOD_GOD = 4671,
    PATCH_DRAGONS_OF_NIGHTMARE = 4735,
    PATCH_GATES_AHN_QIRAJ = 4937,
    PATCH_STORMS_OF_AZEROTH = 5195,
    PATCH_SHADOW_OF_THE_NECROPOLIS = 5428,
    PATCH_DRUMS_OF_WAR = 5595,

    /** The Burning Crusade */
    PATCH_DARK_PORTAL_OPENS = 6299,
    PATCH_BURNING_CRUSADE = 6546,
    PATCH_BLACK_TEMPLE = 6692,
    PATCH_BREWFEST = 7318,
    PATCH_GODS_OF_ZULAMAN = 7799,
    PATCH_FURY_OF_THE_SUNWELL = 8478,

    /** Wrath of the Lich King */
    PATCH_ECHOES_OF_DOOM = 9056,
    PATCH_WRATH_OF_THE_LICH_KING = 9183,
    PATCH_SECRETS_OF_ULDUAR = 9947,
    PATCH_CALL_OF_THE_CURSADE = 10192,
    PATCH_ONYXIAS_LAIR = 10482,
    PATCH_FALL_OF_THE_LICH_KING = 10958,
    PATCH_DEFENDING_THE_RUBY_SANCTUM = 12340,

    /** Allows anything above 12340 to be custom content */
    PATCH_FINAL = 32767
};

/**
 * @brief A basic class that will be the primary entry point for figuring out
 * which "Patch" we should be emulating.
 */
class Progression
{
public:
    /**
     * @brief Get the integer representation of the current "Patch" that we have loaded.
     * 
     * @return int16 
     */
    inline int16 GetCurrentPatch()
    {
        return sConfigMgr->GetOption<int16>("ProgressiveLoading.Patch", 12340);
    }

    /**
     * @brief Get the title of the "Patch" that we are currently emulating.
     * 
     * @return std::string 
     */
    inline std::string GetPatchTitle()
    {
        switch(GetCurrentPatch())
        {
            /** Classic */
            case PATCH_LAUNCH:
                return "World of Warcaft";
            case PATCH_MYSTERIES_OF_MARAUDON:
                return "Mysteries of Maraudon";
            case PATCH_RUINS_OF_THE_DIRE_MAUL:
                return "Ruins of Dire Maul";
            case PATCH_CALL_TO_WAR:
                return "Call to War";
            case PATCH_BATTLEGROUNDS:
                return "Battlegrounds";
            case PATCH_ASSAULT_ON_BLACKWING_LAIR:
                return "Assault on Blackwing Lair";
            case PATCH_RISE_OF_THE_BLOOD_GOD:
                return "Rise of the Blood God";
            case PATCH_DRAGONS_OF_NIGHTMARE:
                return "Dragons of Nightmare";
            case PATCH_GATES_AHN_QIRAJ:
                return "The Gates of Ahn'Qiraj";
            case PATCH_STORMS_OF_AZEROTH:
                return "Storms of Azeroth";
            case PATCH_SHADOW_OF_THE_NECROPOLIS:
                return "Shadow of the Necropolis";
            case PATCH_DRUMS_OF_WAR:
                return "Drums of War";

            /** The Burning Crusade */
            case PATCH_DARK_PORTAL_OPENS:
                return "Before the Storm";
            case PATCH_BURNING_CRUSADE:
                return "The Burning Crusade";
            case PATCH_BLACK_TEMPLE:
                return "The Black Temple";
            case PATCH_BREWFEST:
                return "Brewfest";
            case PATCH_GODS_OF_ZULAMAN:
                return "The Gods of Zul’Aman";
            case PATCH_FURY_OF_THE_SUNWELL:
                return "Fury of the Sunwell";

            /** Wrath of the Lich King */
            case PATCH_ECHOES_OF_DOOM:
                return "Echoes of Doom";
            case PATCH_WRATH_OF_THE_LICH_KING:
                return "Wrath of the Lich King";
            case PATCH_SECRETS_OF_ULDUAR:
                return "Secrets of Ulduar";
            case PATCH_CALL_OF_THE_CURSADE:
                return "Call of the Crusade";
            case PATCH_ONYXIAS_LAIR:
                return "Onyxia's Lair";
            case PATCH_FALL_OF_THE_LICH_KING:
                return "Fall of the Lich King";
            case PATCH_DEFENDING_THE_RUBY_SANCTUM:
                return "Defending the Ruby Sanctum";

            /** Fallback */
            default:
                return "Unknown Patch";
        }
    }
};

/**
 * @brief Get a reference to the Progression class once created.
 * 
 * @return std::unique_ptr<Progression>& 
 */
inline std::unique_ptr<Progression>& getInstance()
{
    static std::unique_ptr<Progression> instance = std::make_unique<Progression>();

    return instance;
}

/**
 * @brief A re-usable instance of the Progression class.
 */
#define sProgression getInstance()

#endif