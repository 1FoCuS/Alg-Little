#include "littleworker.h"

LittleWorker::LittleWorker(const Matrix<double> &m)
    : _solver(std::make_unique<LittleSolver>(m)) {
}

std::list<size_t> LittleWorker::getSolution() const {
    return _solver->getSolution();
}

double LittleWorker::getRecord() const {
    return _solver->getRecord();
}

LittleSolver::arclist LittleWorker::getLastStep() const {
    return _solver->getLastStep();
}

LittleSolver::arclist LittleWorker::getBestStep() const {
    return _solver->getBestStep();
}
