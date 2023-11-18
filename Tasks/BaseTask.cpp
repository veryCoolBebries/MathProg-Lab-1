//
// Created by maksim on 16.11.23.
//
#include "BaseTask.h"
template<typename TaskCondition, typename OracleResponse>
std::vector<int> BaseTask<TaskCondition,OracleResponse>::SolveTask(std::vector<int> x_values, double epsilon) {
    while(StopCriterion(x_values) > epsilon) {
        auto oracleResponse = OracleRequest(x_values);
        UpdateInformation(taskCondition, oracleResponse);
        x_values = NextPoint(NextPoint(x_values));
    }
    return x_values;
}