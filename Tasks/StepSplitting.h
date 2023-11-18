//
// Created by maksim on 16.11.23.
//

#ifndef MATHPROG_STEPSPLITTING_H
#define MATHPROG_STEPSPLITTING_H


#include "BaseTask.h"
#include "../DataModels/Function.h"
struct StepSplittingTaskCondition {
    const Function& function;
};
struct OracleResponse {
    double func_value_in_x = 0.0;
    double grad_value_in_x = 0.0;
    std::vector<int> derivatives_in_cur_x;
};
class StepSplitting : BaseTask<StepSplittingTaskCondition, OracleResponse> {
public:
    OracleResponse OracleRequest(std::vector<int> x_values) override;
    void UpdateInformation(std::vector<int> x_values, OracleResponse oracleResponse) override = 0;
    std::vector<int> NextPoint(std::vector<int> x_values) override = 0;
    double StopCriterion(std::vector<int> x_values) override = 0;
};


#endif //MATHPROG_STEPSPLITTING_H
