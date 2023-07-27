#include "slau.h"

bool SLAU::IsSquareMatrix(std::vector<std::vector<double>> A)
{
    n = A.size();

    for (int i = 0; i < n; i++)
    {
        if (A[i].size() != n)
            return false;
    }

    return true;
}

void SLAU::SolveLinearEquations(std::vector<std::vector<double>> A, std::vector<double> b)
{
    x.resize(n, 0);

    for (int k = 0; k < n - 1; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            m = A[i][k] / A[k][k];

            for (int j = k + 1; j < n; j++)
            {
                A[i][j] = A[i][j] - m * A[k][j];
            }

            b[i] = b[i] - m * b[k];
        }
    }

    x[n - 1] = b[n - 1] / A[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        double sum = 0;

        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }

        x[i] = (b[i] - sum) / A[i][i];
    }
}

void SLAU::DecisionSLAU()
{
    std::cout << "Введите размер матрицы A: ";
    std::cin >> l;

    a.resize(l, std::vector<double>(l, 0));
    b.resize(l, 0);

    std::cout << "Введите эл-ты матрицы A: " << std::endl;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            std::cin >> a[i][j];
        }
    }

    if (!IsSquareMatrix(a))
    {
        std::cout << "Ошибка: матрица не квадратная" << std::endl;
        return;
    }

    std::cout << "Введите эл-ты вектора b: " << std::endl;

    for (int i = 0; i < l; i++)
    {
        std::cin >> b[i];
    }

    n = a.size();

    for (int i = 0; i < n; i++)
    {
        if (a[i].size() != n)
        {
            std::cout << "Ошибка: матрица не квадратная" << std::endl;
            return;
        }
    }

    if (b.size() != n)
    {
        std::cout << "ошибка: вектор b имеет некорректный размер" << std::endl;
        return;
    }

    SolveLinearEquations(a, b);

    if (x.empty())
    {
        std::cout << "Ошибка: СЛАУ не имеет решения" << std::endl;
    }
    else
    {
        std::cout << "Решение введенной СЛАУ: ";

        for (int i = 0; i < l; i++)
        {
            std::cout << x[i] << " ";
        }

        std::cout << std::endl;
    }
}