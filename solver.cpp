#include "solver.h"

Solver::Solver()
{
	srand(time(NULL));
}

int Solver::Factorial(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return n * Factorial(n - 1);
}

int Solver::NOD(int a, int b)
{
    if (b == 0)
        return a;

    return NOD(b, a % b);
}

std::string Solver::ConvertToBase(int num, int base)
{
    while (num > 0)
    {
        remainder = num % base;
        result = std::to_string(remainder) + result;
        num /= base;
    }

    return result;
}

std::string Solver::ConvertBase(std::string numStr, int baseSrc, int baseDst)
{
    num = 0;
    power = 0;

    for (int i = numStr.length() - 1; i >= 0; i--)
    {
        digit = 0;

        if (numStr[i] >= '0' && numStr[i] <= '9')
        {
            digit = numStr[i] - '0';
        }
        else
            if (numStr[i] >= 'A' && numStr[i] <= 'F')
            {
                digit = numStr[i] - 'A' + 10;
            }

        num += digit * pow(baseSrc, power);
        power++;
    }

    return ConvertToBase(num, baseDst);
}

void Solver::Arithmetic()
{
    std::cout << "\nSelect an operation:\n1 - addition\n2 - subtraction\n3 - division\n4 - multiplication\n";
    std::cin >> n;

    switch (n)
    {
    case 1:
        std::cout << "a + b:\na = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        std::cout << a << " + " << b << " = " << Sum(a, b) << std::endl;
        break;

    case 2:
        std::cout << "a - b:\na = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        std::cout << a << " - " << b << " = " << Subtraction(a, b) << std::endl;
        break;

    case 3:
        std::cout << "a / b:\na = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;

        if (b == 0)
            std::cout << "Error! Division by zero\n";
        else
            std::cout << a << " / " << b << " = " << Division(a, b) << std::endl;

        break;

    case 4:
        std::cout << "a * b:\na = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        std::cout << a << " * " << b << " = " << Multiplication(a, b) << std::endl;
        break;

    default:
        std::cout << "Wrong input!\n";
        break;
    }
}

void Solver::Trigonometry()
{
    std::cout << "\nSelect an operation: \n1 - sin(x)\n2 - cos(x)\n3 - tg(x)\n4 - ctg(x)\n";
    std::cin >> n;

    if (n < 1 || n > 4)
    {
        std::cout << "Wrong input!\n";
        return;
    }

    std::cout << "Enter the number x (in radians): ";
    std::cin >> w;

    switch (n)
    {
    case 1:
        std::cout << "sin(x) = " << sin(w) << std::endl;
        break;

    case 2:
        std::cout << "cos(x) = " << cos(w) << std::endl;
        break;

    case 3:
        std::cout << "tg(x) = " << tan(w) << std::endl;
        break;

    case 4:
        std::cout << "ctg(x) = " << 1 / tan(w) << std::endl;
        break;

    default:
        std::cout << "Wrong input!\n";
        break;
    }
}

void Solver::Bitwise()
{
    std::cout << "\nSelect an operation: \n1 - bitwise AND\n2 - bitwise OR\n";
    std::cin >> n;

    if (n < 1 || n > 2)
    {
        std::cout << "Wrong input!\n";
        return;
    }

    std::cout << "Enter 2 numbers separated by a space: ";
    std::cin >> x >> y;

    if ((x != 0) && (x != 1) || (y != 0) && (y != 1))
    {
        std::cout << "Wrong input!" << std::endl;
        return;
    }

    switch (n)
    {
    case 1:
        rez = x & y;
        std::cout << "bitwise AND = " << rez << std::endl;
        break;

    case 2:
        rez = x | y;
        std::cout << "bitwise OR = " << rez << std::endl;
        break;

    default:
        std::cout << "Wrong input!\n";
        break;
    }
}

void Solver::Run()
{
    while (f)
    {
        std::cout << "\nSelect an operation:\n1 - arithmetic operations\n2 - trigonometric calculations";
        std::cout << "\n3 - bitwise logic calculations\n4 - number degree\n5 - factorial\n6 - natural logarithm";
        std::cout << "\n7 - NOC and NOD of 2 numbers\n8 - number system conversion";
        std::cout << "\n9 - area of a regular n-gon\n10 - quadratic equation solution";
        std::cout << "\n11 - generate a number in a range\n12 - Solving SLAU by the run method\n13 - programme exit\nYour choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            Arithmetic();
            break;

        case 2:
            Trigonometry();
            break;

        case 3:
            Bitwise();
            break;

        case 4:
            std::cout << "a ^ b\na = "; std::cin >> a;
            std::cout << "\nb = "; std::cin >> b;
            std::cout << "a ^ b = " << pow(a, b) << std::endl;
            break;

        case 5:
            std::cout << "Enter a number N: "; std::cin >> n;

            if (n < 0)
            {
                std::cout << "Wrong input!\n";
                break;
            }

            std::cout << n << "! = " << Factorial(n) << std::endl;
            break;

        case 6:
            std::cout << "Enter the number argument of the logarithm w: "; std::cin >> w;
            std::cout << "log(w) = " << log(w) << std::endl;
            break;

        case 7:
            std::cout << "NOD and NOK of numbers (x, y)\nx = "; std::cin >> x;
            std::cout << "y = "; std::cin >> y;
            std::cout << "NOD = " << NOD(x, y) << ", NOK = " << NOK(x, y) << std::endl;
            break;

        case 8:
            std::cout << "Enter a number: "; std::cin >> num_str;
            std::cout << "Enter the base of the number (2, 8, 10, 16): "; std::cin >> base_src;

            if ((base_src != 2) && (base_src != 8) && (base_src != 10) && (base_src != 16))
            {
                std::cout << "Wrong input!\n";
                break;
            }

            std::cout << "Enter the desired base of the number (2, 8, 10, 16): "; std::cin >> base_dst;

            if ((base_dst != 2) && (base_dst != 8) && (base_dst != 10) && (base_dst != 16))
            {
                std::cout << "Wrong input!\n";
                break;
            }

            std::cout << "result: " << ConvertBase(num_str, base_src, base_dst) << std::endl;
            break;

        case 9:
            std::cout << "Enter the number of sides of a regular n-gon: "; std::cin >> n;

            if (n < 3)
            {
                std::cout << "Wrong input!\n";
                break;
            }

            std::cout << "Enter the side length of a regular n-angle: "; std::cin >> length;

            if (length <= 0)
            {
                std::cout << "Wrong input!\n";
                break;
            }

            perimeter = n * length;
            apothem = length / (2 * tan(M_PI / n));
            std::cout << "The area of the right " << n << "-angle = " << 0.5 * perimeter * apothem << std::endl;
            break;

        case 10:
            std::cout << "The quadratic equation has the form: ax^2 + bx + c = 0\nEnter the coefficients:\na = "; std::cin >> a;
            std::cout << "\nb = "; std::cin >> b; std::cout << "\nc = "; std::cin >> w; std::cout << std::endl;

            d = b * b - 4 * a * w;

            if (d < 0)
                std::cout << "There are no roots!\n";

            if (d == 0)
                std::cout << "1 solution: x = " << -b / (2 * a) << std::endl;

            if (d > 0)
                std::cout << "2 solutions:\nx1 = " << (-b + sqrt(d)) / (2 * a) << "\nx2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;

            break;

        case 11:
            std::cout << "Random number in the range [x, y]\nEnter the lower limit of the range = "; std::cin >> x;
            std::cout << "Enter the upper limit of the range = "; std::cin >> y;

            if (y - x < 0)
            {
                std::cout << "Wrong input!\n";
                break;
            }

            std::cout << "Random number in the range [" << x << ", " << y << "] = " << (rand() % (y - x + 1)) + x << std::endl;
            break;

        case 12:
            z.DecisionSLAU();
            break;

        case 13:
            exit(0);

        default:
            std::cout << "Wrong input!\n";
            break;
        }
    }
}