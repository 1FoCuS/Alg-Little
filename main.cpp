#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <numeric>
#include <iomanip>

#define DEBUG
constexpr double INF = DBL_MAX;

using namespace std;
template <typename T>
using Matrix = std::vector<std::vector<T>>;

template<typename T>
ostream& operator<<(ostream& ss, const vector<T>& m)
{
	for(const auto& a:m)
	{
		ss << std::setprecision(2) <<  (a==INF ? -1 : a) << "\t";
	}
	return ss;
}
template<typename T>
ostream& operator<<(ostream& ss, const Matrix<T>& m)
{
	for(const auto& a:m)
	{
		ss << a << std::endl;
	}
	return ss;
}
// ==========================================================================================================
class LittleSolver
{
public:
	LittleSolver() 
	{
		matrix = {
			{	INF,	20,		18,		12,		8	},
			{	5,		INF,	14,		7,		11	},
			{	12,		18,		INF, 	6, 		11	},
			{	11, 	17,		11,		INF,	12	},
			{	5,		5,		5,		5,		INF	}
		};
#ifdef DEBUG
	std::cout << matrix << std::endl;
#endif // DEBUG
	}
	
	double prepare()
	{
		std::vector<double> minRow(matrix.size(), INF), minColumn(matrix.size(), INF);

		for( std::size_t i=0; i<matrix.size(); ++i)
		{
			for(std::size_t j=0; j<matrix.size(); ++j)
			{
				minRow[i] = std::min(matrix[i][j], minRow[i]);
			}

			for(std::size_t j=0; j<matrix.size(); ++j)
			{
				if(matrix[i][j] < INF) matrix[i][j] -= minRow[i];
				minColumn[j] = std::min(matrix[i][j], minColumn[j]);
			}
		}
		for( std::size_t j=0; j<matrix.size(); ++j)
		{
			for(std::size_t i=0; i<matrix.size(); ++i)
			{
				if (matrix[i][j] < INF) matrix[i][j] -= minColumn[j];
			}
		}

		subtractSum = std::accumulate(minRow.begin(), minRow.end(), subtractSum);
		subtractSum = std::accumulate(minColumn.begin(), minColumn.end(), subtractSum);

#ifdef DEBUG
	std::cout << "After subtracting:" << std::endl; 
	std::cout << matrix << std::endl;
#endif // DEBUG

    	return subtractSum;

	}
private:
	Matrix<double> matrix;
	double subtractSum = 0; 		// сумма всех вычтенных значений
	double low_borderline = 0; 		// нижняя граница
};
// ==========================================================================================================




// @todo part 2
int main() 
{
	LittleSolver solver;
	solver.prepare();
}
