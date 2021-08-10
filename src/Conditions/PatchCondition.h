#ifndef _MOD_PROGRESSIVE_LOADING_PATCH_CONDITION_H_
#define _MOD_PROGRESSIVE_LOADING_PATCH_CONDITION_H_

#include "ScriptMgr.h"

/**
 * @brief A condition that allows us to check whether something can only happen before, after and during a specific patch.
 * 
 */
class PatchCondition : public ConditionScript
{
public:
    PatchCondition() : ConditionScript("ProgressiveLoading_PatchCondition") {}

    /**
     * @brief Handles the actual checking of the condition.
     * 
     * @param condition The condition we are checking.
     * @param sourceInfo The source of the condition.
     * @return true 
     * @return false 
     */
    bool OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo) override;

private:
    /**
     * @brief Validates the data provided to the patch progression condition.
     * 
     * @param condition The condition we are checking.
     * @param patch The patch data for the condition.
     * @param comparison The operator we are using.
     * @return true 
     * @return false 
     */
    bool IsValid(Condition* condition, uint32 patch, uint32 comparison);
};

#endif