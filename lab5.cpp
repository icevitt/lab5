#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;

//Завдання 1 
double f1(double x) {
    return std::pow(std::sin(x), 5) + std::fabs(5 * x - 1.5);
}

void task1() {
    std::cout << "\nЗавдання 1\n";
    double x[5];
    std::cout << "Введіть 5 значень x через пробіл: ";
    for (int i = 0; i < 5; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < 5; i++) {
        std::cout << "x = " << x[i] << "   y = " << f1(x[i]) << "\n";
    }
}

//Завдання 2 (варіант 4)
void task2() {
    std::cout << "\nЗавдання 2\n";
    int sum = 0;
    for (int k = 1; k <= 25; k++) {
        sum = sum + k * k;
    }
    std::cout << "Сума квадратів від 1 до 25: " << sum << "\n";
}

//Завдання 3 (варіант 4)
double f3(double x) {
    return 5 * x * x * x + std::sqrt(6 - x);
}

bool inDomain(double x) {
    return 6 - x >= 0;
}

void task3() {
    std::cout << "\nЗавдання 3 (варіант 4)\n";
    double a, b, h;
    std::cout << "Введіть a, b та h через пробіл: ";
    std::cin >> a >> b >> h;

    if (h <= 0) {
        std::cout << "Крок h має бути додатним!\n";
        return;
    }

    const std::string line = "-------------------------";
    std::cout << line << "\n";
    std::cout << ":     X     :     Y     :\n";
    std::cout << line << "\n";

    double x = a;
    while (x <= b + 1e-9) {
        if (!inDomain(x)) {
            std::cout << "x = " << x << " не належить ОДЗ. Виведення припинено.\n";
            break;
        }
        std::cout << std::fixed << std::setprecision(3)
            << ":" << std::setw(10) << x
            << " :" << std::setw(10) << f3(x) << " :\n";
        std::cout << line << "\n";
        x += h;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    task1();
    task2();
    task3();
    return 0;
}