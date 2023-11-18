//
// Created by maksim on 16.11.23.
//

#ifndef MATHPROG_BASETASK_H
#define MATHPROG_BASETASK_H

#include <vector>

template<typename TaskCondition, typename OracleResponse>
class BaseTask {
protected:
    BaseTask(TaskCondition taskCondition) : taskCondition(taskCondition) {}

    TaskCondition taskCondition;
public:
    virtual OracleResponse OracleRequest(std::vector<int> x_values) = 0;
    virtual void UpdateInformation(std::vector<int> x_values, OracleResponse oracleResponse) = 0;
    virtual std::vector<int> NextPoint(std::vector<int> x_values) = 0;
    virtual double StopCriterion(std::vector<int> x_values) = 0;
    std::vector<int> SolveTask(std::vector<int> x_values, double epsilon);
};
#endif //MATHPROG_BASETASK_H
