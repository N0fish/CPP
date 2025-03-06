#include <iostream>
#include <cmath>
#include <limits>

// g++ generate_special_cases.cpp -o generate_special_cases -lm

// DBL_MIN: 2.22507e-308
// DBL_MAX: 1.79769e+308
// DBL_EPSILON: 2.22045e-16
// Infinity: inf
// NaN: nan

void	double_print()
{
    std::cout << "DBL_MIN: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "DBL_MAX: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "DBL_EPSILON: " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "Infinity: " << std::numeric_limits<double>::infinity() << std::endl;
    std::cout << "NaN: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
}

// sqrt(-1)=nan
// 0.0 / 0.0=nan
// 1.0 / 0.0=inf
// -1.0 / 0.0=-inf
// exp(1000)=inf
// log(0.0)=-inf

int main() {
    std::cout << "sqrt(-1)=" << std::sqrt(-1) << std::endl;
    std::cout << "0.0 / 0.0=" << (0.0 / 0.0) << std::endl;
    std::cout << "1.0 / 0.0=" << (1.0 / 0.0) << std::endl;
    std::cout << "-1.0 / 0.0=" << (-1.0 / 0.0) << std::endl;
    std::cout << "exp(1000)=" << std::exp(1000) << std::endl;
    std::cout << "log(0.0)=" << std::log(0.0) << std::endl;
	
	std::cout << std::endl;
	double_print();
}
