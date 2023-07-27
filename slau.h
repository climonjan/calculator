#ifndef SLAU_H_
#define SLAU_H_
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>

class SLAU
{
public:
    SLAU() {};
    ~SLAU() {};

    void DecisionSLAU();

private:
    bool IsSquareMatrix(std::vector<std::vector<double>> A);
    void SolveLinearEquations(std::vector<std::vector<double>> A, std::vector<double> b);

    std::vector<std::vector<double>> a;
    std::vector<double> x, b;
    double m;
    int n, l;
};


#endif // SLAU_H_