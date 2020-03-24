#include "littleworker.h"
#include <iostream>
#include <cmath>

using namespace std;
constexpr int INF = 99;

Matrix<double> create_matrix(const std::vector<std::pair<double, double>>&);

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
//    Matrix<double> matrix(5);

    auto matrix = create_matrix({{1,1}, {2,2} , {3,3}, {4,4}, {5,5} });
//    habr_init(matrix);
//    test_init(matrix);

    matrix.print();

    LittleSolver worker(matrix);
    worker.solve();

    auto res = worker.getSolution();

    std::cout << "result: ";
    while (!res.empty())
    {
        std::cout << res.front() << " ";
        res.pop_front();
    }
    std::cout << std::endl;
}

Matrix<double> create_matrix(const std::vector<std::pair<double, double>>& points)
{
    Matrix<double> matrix(points.size());

    for(std::size_t i = 0; i<points.size(); ++i)
    {
        for(std::size_t j = 0; j<points.size(); ++j)
        {
            if (i==j) continue;
            const auto x = std::pow(points[i].first - points[j].first, 2);
            const auto y = std::pow(points[i].second - points[j].second, 2);
            matrix(i,j) = sqrt(x + y);
        }
    }

    return matrix;
}
