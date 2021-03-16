#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <limits>
#include <iomanip>

using namespace std::literals;

void _1st() {
    std::cout << "Enter the coordinates of the dot (x,y)"s << std::endl;
    double x, y;
    std::cin >> x >> y;
    if (abs(y) >= (x * x)) {
        std::cout << "Dot belongs"s << std::endl;
    } else {
        std::cout << "Dot doesn't belong"s << std::endl;
    }
    //Задержка для более удобного просмотра результатов
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void _2nd() {
    for (double i = -2.1; i <= -0.1; i += 0.1) {
        double y;
        y = static_cast<double>((1. - sqrt(1. + fabs(sin(i)))) / 2.);
        std::cout << "For x = " << i << ", y = " << std::setprecision(2) << y << std::endl;
    }
    for (double i = 0; i <= 2.2; i += 0.1) {
        double y;
        y = static_cast<double>((1. - sqrt(1. + fabs(sin(i)))) / 2.);
        std::cout << "For x = " << i << ", y = " << std::setprecision(2) << y << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds());
}

void _3rd() {
    double h;
    std::cout << "Enter h"s << std::endl;
    std::cin >> h;
    double a;
    a = sqrt((abs(sin(18 * h)) + 17) / (pow(1 - (sin(4 * h)), 2)));
    double b;
    b = 1 - sqrt((3) / (3 + abs(cos(a * pow(h, 2)) - sin(a * h))));
    double c;
    c = a * pow(h, 2) * sin(b * h) + b * pow(h, 3) * cos(a * h);
    if (std::isnan(c)) {
        std::cout << "There are no roots"s << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    double d;
    d = pow(b, 2) - 4 * a * c;
    if (d < 0) {
        std::cout << "There are no roots"s << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    } else if (d == 0) {
        double x;
        x = (-b / 2 * a);
        if (x == 0) {
            x = std::abs(x);
        }
        std::cout << "Root is: "s << std::setprecision(2) << x << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    double x1, x2;
    x1 = ((-b + sqrt(d)) / 2 * a);
    x2 = ((-b - sqrt(d)) / 2 * a);
    std::cout << "Roots are: " << std::setprecision(2) << x1 << " and "s << std::setprecision(2) << x2 << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}

void _4th() {
    std::cout << std::setw(6) << "x" << std::setw(10) << "y" << std::endl;
    for (double i = -2.1; i <= -0.1; i += 0.1) {
        double y;
        y = static_cast<double>(3 * std::abs(2 * sin(i) - 3 * cos(i)));
        std::cout << "|" << std::setw(5) << i << std::setw(5) << "|" << std::setprecision(2) << std::setw(5) << y << "|"
                  << std::endl;
    }
    for (double i = 0; i <= 2.2; i += 0.1) {
        double y;
        y = static_cast<double>(3 * std::abs(2 * sin(i) - 3 * cos(i)));
        std::cout << "|" << std::setw(5) << i << std::setw(5) << "|" << std::setprecision(2) << std::setw(5) << y << "|"
                  << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds());
}

void _5th() {
    std::cout << "Enter float a and integer n:" << std::endl;
    double a;
    int n;
    std::cin >> a >> n;
    double result = 1;
    for (int i = 0; i * n <= n * n; ++i) {
        result *= a - i * n;
    }
    std::cout << "Result is: " << result << std::endl;
}

void _6th() {
    std::cout << "Enter integer n"s << std::endl;
    int n;
    std::cin >> n;
    double result = 0;
    for (int i = 0; i <= n; ++i) {
        result += (pow(4., i) / pow(5, i + 2.));
    }
    std::cout << std::setprecision(2) << result << std::endl;
}

void _7th() {
    std::cout << "Enter float x: " << std::endl;
    double x;
    std::cin >> x;
    double a, prev_a;
    prev_a = x;
    a = (x / (1. + abs(prev_a))) + 2. * prev_a;
    while (!(std::abs(a - prev_a) < std::numeric_limits<double>::epsilon())) {
        double buff = a;
        a = (x / (1. + abs(prev_a))) + 2. * prev_a;
        prev_a = buff;
    }
    std::cout << "result is: " << a << std::endl;
}

void _8th() {
    std::cout << "Enter float x: " << std::endl;
    double x;
    std::cin >> x;
    double epsilon = std::numeric_limits<double>::epsilon();
    double result = (pow(-1., 2) * (x / (pow(x + 1, 2))));
    while (result >= epsilon) {
        int k = 2;
        result = (pow(-1., k + 1) * (pow(x, 2 * k - 1) / (pow(x + 1, 2 * k))));
        ++k;
    }
    std::cout << "result is: " << std::setprecision(2) << result;
}

int main() {
    //1 номер
     _1st();
    //2 номер
    _2nd();
    //3 номер
    _3rd();
    //4 номер
    _4th();
    //5 номер
    _5th();
    //6 номер
    _6th();
    //7 номер
    _7th();
    //8 номер
    _8th();
}
