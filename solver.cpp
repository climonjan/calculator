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
    std::cout << "\nВыберите операцию:\n1 - сложение\n2 - вычитание\n3 - деление\n4 - умножение\n";
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
            std::cout << "Ошибка! Деление на нуль\n";
        else
            std::cout << a << " / " << b << " = " << Division(a, b) << std::endl;

        break;

    case 4:
        std::cout << "a * b:\na = "; std::cin >> a;
        std::cout << "b = "; std::cin >> b;
        std::cout << a << " * " << b << " = " << Multiplication(a, b) << std::endl;
        break;

    default:
        std::cout << "Неправильный ввод!\n";
        break;
    }
}

void Solver::Trigonometry()
{
    std::cout << "\nВыберите операцию: \n1 - sin(x)\n2 - cos(x)\n3 - tg(x)\n4 - ctg(x)\n";
    std::cin >> n;

    if (n < 1 || n > 4)
    {
        std::cout << "Неправильный ввод!\n";
        return;
    }

    std::cout << "Введите число х (в радианах): ";
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
        std::cout << "Неправильный ввод!\n";
        break;
    }
}

void Solver::Bitwise()
{
    std::cout << "\nВыберите операцию: \n1 - побитовое И\n2 - побитовое ИЛИ\n";
    std::cin >> n;

    if (n < 1 || n > 2)
    {
        std::cout << "Неправильный ввод!\n";
        return;
    }

    std::cout << "Введите 2 числа через пробел: ";
    std::cin >> x >> y;

    if ((x != 0) && (x != 1) || (y != 0) && (y != 1))
    {
        std::cout << "Неверный ввод чисел!" << std::endl;
        return;
    }

    switch (n)
    {
    case 1:
        rez = x & y;
        std::cout << "побитовое И = " << rez << std::endl;
        break;

    case 2:
        rez = x | y;
        std::cout << "побитовое ИЛИ = " << rez << std::endl;
        break;

    default:
        std::cout << "Неправильный ввод!\n";
        break;
    }
}

void Solver::Run()
{
    while (f)
    {
        std::cout << "\nВыберите операцию:\n1 - арифметические действия\n2 - тригонометрические вычисления";
        std::cout << "\n3 - побитовые логические вычисления\n4 - степень числа\n5 - факториал\n6 - натуральный логарифм";
        std::cout << "\n7 - НОК и НОД 2 чисел\n8 - конвертация системы счисления";
        std::cout << "\n9 - площадь правильного n-угольника\n10 - решение квадратного уравнения";
        std::cout << "\n11 - сгенерировать число в диапозоне\n12 - Решение СЛАУ методом прогонки\n13 - выход из программы\nВаш выбор: ";
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
            std::cout << "Введите число N: "; std::cin >> n;

            if (n < 0)
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            std::cout << n << "! = " << Factorial(n) << std::endl;
            break;

        case 6:
            std::cout << "Введите число аргумент логарифма w: "; std::cin >> w;
            std::cout << "log(w) = " << log(w) << std::endl;
            break;

        case 7:
            std::cout << "НОД и НОК чисел (x, y)\nx = "; std::cin >> x;
            std::cout << "y = "; std::cin >> y;
            std::cout << "НОД = " << NOD(x, y) << ", НОК = " << NOK(x, y) << std::endl;
            break;

        case 8:
            std::cout << "Введите число: "; std::cin >> num_str;
            std::cout << "Введите основание числа (2, 8, 10, 16): "; std::cin >> base_src;

            if ((base_src != 2) && (base_src != 8) && (base_src != 10) && (base_src != 16))
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            std::cout << "Введите желаемое основание числа (2, 8, 10, 16): "; std::cin >> base_dst;

            if ((base_dst != 2) && (base_dst != 8) && (base_dst != 10) && (base_dst != 16))
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            std::cout << "результат: " << ConvertBase(num_str, base_src, base_dst) << std::endl;
            break;

        case 9:
            std::cout << "Введите кол-во сторон правильного n-угольника: "; std::cin >> n;

            if (n < 3)
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            std::cout << "Введите длину стороны правильного n-угольника: "; std::cin >> length;

            if (length <= 0)
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            perimeter = n * length;
            apothem = length / (2 * tan(M_PI / n));
            std::cout << "Площадь правильного " << n << "-угольника = " << 0.5 * perimeter * apothem << std::endl;
            break;

        case 10:
            std::cout << "Квадратное уравнение имеет вид: ax^2 + bx + c = 0\nВведите коэффиценты:\na = "; std::cin >> a;
            std::cout << "\nb = "; std::cin >> b; std::cout << "\nc = "; std::cin >> w; std::cout << std::endl;

            d = b * b - 4 * a * w;

            if (d < 0)
                std::cout << "Корней нет!\n";

            if (d == 0)
                std::cout << "1 решение: x = " << -b / (2 * a) << std::endl;

            if (d > 0)
                std::cout << "2 решения:\nx1 = " << (-b + sqrt(d)) / (2 * a) << "\nx2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;

            break;

        case 11:
            std::cout << "Cлучайное число в диапозоне [x, y]\nВведите нижнюю границу диапозона = "; std::cin >> x;
            std::cout << "Введите верхнюю границу диапозона = "; std::cin >> y;

            if (y - x < 0)
            {
                std::cout << "Неправильный ввод!\n";
                break;
            }

            std::cout << "Cлучайное число в диапозоне [" << x << ", " << y << "] = " << (rand() % (y - x + 1)) + x << std::endl;
            break;

        case 12:
            z.DecisionSLAU();
            break;

        case 13:
            exit(0);

        default:
            std::cout << "Неправильный ввод!\n";
            break;
        }
    }
}