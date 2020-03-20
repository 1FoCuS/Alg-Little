#include "littlesolver.h"
#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace std;
constexpr int INF = 99;

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

void habr_init(Matrix<double>& matrix)
{
    matrix.item(0,0) = INF;
    matrix.item(0,1) = 20;
    matrix.item(0,2) = 18;
    matrix.item(0,3) = 12;
    matrix.item(0,4) = 8;

    matrix.item(1,0) = 5;
    matrix.item(1,1) = INF;
    matrix.item(1,2) = 14;
    matrix.item(1,3) = 7;
    matrix.item(1,4) = 11;

    matrix.item(2,0) = 12;
    matrix.item(2,1) = 18;
    matrix.item(2,2) = INF;
    matrix.item(2,3) = 6;
    matrix.item(2,4) = 11;

    matrix.item(3,0) = 11;
    matrix.item(3,1) = 17;
    matrix.item(3,2) = 11;
    matrix.item(3,3) = INF;
    matrix.item(3,4) = 12;

    matrix.item(4,0) = 5;
    matrix.item(4,1) = 5;
    matrix.item(4,2) = 5;
    matrix.item(4,3) = 5;
    matrix.item(4,4) = INF;
}
void test_init(Matrix<double>& matrix)
{
    matrix.item(0,0) = INF;
    matrix.item(0,1) = sqrt(800);
    matrix.item(0,2) = sqrt(2900);
    matrix.item(0,3) = sqrt(1700);
    matrix.item(0,4) = 10;

    matrix.item(1,0) = sqrt(800);
    matrix.item(1,1) = INF;
    matrix.item(1,2) = sqrt(1000);
    matrix.item(1,3) = 20;
    matrix.item(1,4) = sqrt(200);

    matrix.item(2,0) = sqrt(2900);
    matrix.item(2,1) = sqrt(1000);
    matrix.item(2,2) = INF;
    matrix.item(2,3) = sqrt(200);
    matrix.item(2,4) = sqrt(2000);

    matrix.item(3,0) = sqrt(1700);
    matrix.item(3,1) = 20;
    matrix.item(3,2) = sqrt(200);
    matrix.item(3,3) = INF;
    matrix.item(3,4) = sqrt(1000);

    matrix.item(4,0) = 10;
    matrix.item(4,1) = sqrt(200);
    matrix.item(4,2) = sqrt(2000);
    matrix.item(4,3) = sqrt(1000);
    matrix.item(4,4) = INF;
}
int main()
{
    Matrix<double> matrix(5);

//    habr_init(matrix);
    test_init(matrix);
    matrix.print();

    LittleSolver worker(matrix);
    worker.solve();

    auto res = worker.getSolution();

    while (!res.empty())
    {
        std::cout << res.front() << std::endl;
        res.pop_front();
    }

}


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
