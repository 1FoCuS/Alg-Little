#ifndef LITTLEWORKER_H
#define LITTLEWORKER_H

#include "littlesolver.h"
#include "matrix.h"

class LittleWorker
{
public:
    explicit LittleWorker(const Matrix<double> &m);

    std::list<size_t> getSolution() const;
    LittleSolver::arclist getLastStep() const;
    LittleSolver::arclist getBestStep() const;
    double getRecord() const;

    void process();

private:
    std::unique_ptr<LittleSolver> _solver;
};

#endif // LITTLEWORKER_H
