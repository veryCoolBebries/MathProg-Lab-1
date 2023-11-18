//
// Created by maksim on 16.11.23.
//

#include "StepSplitting.h"

OracleResponse StepSplitting::OracleRequest(std::vector<int> x_values) {
    OracleResponse oracleResponse;
    for(auto value : x_values) {

    }

}

StepSplitting::StepSplitting(Function &function) : BaseTask<StepSplittingTaskCondition, OracleResponse>(
        StepSplittingTaskCondition(function)) {
    for () {

    }
}


