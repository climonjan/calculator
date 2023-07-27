#ifndef SOLVER_H_
#define SOLVER_H_
#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <random>
#include <string>
#include "slau.h"
#include <string>

class Solver
{
public:
    Solver();

    void Run();

private:
    double Sum(double a, double b) { return a + b; }
    double Multiplication(double a, double b) { return a * b; }
    double Subtraction(double a, double b) { return a - b; }
    double Division(double a, double b) { return a / b; }
    void Arithmetic();
    void Trigonometry();
    void Bitwise();
    int Factorial(int n);
    int NOD(int a, int b);
    int NOK(int a, int b) { return (a * b) / NOD(a, b); }
    std::string ConvertToBase(int num, int base);
    std::string ConvertBase(std::string numStr, int baseSrc, int baseDst);

    double a, b, w, length, perimeter, apothem, d, rez;
    double e = exp(1);
    int base_src, base_dst, x, y, r, choice = 0, n = 0;
    std::string num_str;
    std::string result = "";
    int remainder, num, power, digit, min = 1, max = 13;
    bool f = true;
    SLAU z;
};

#endif // SOLVER_H_