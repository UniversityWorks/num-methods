#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x - 2 * x - 4;
}

double secantMethod(double x0, double x1, double epsilon, int &iterations) {
    double x2;
    iterations = 0;

    while (true) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        iterations++;
        std::cout << "x" << iterations << " = " << x2 << std::endl; 
        if (fabs(f(x2)) < epsilon) {
            break;
        }

        x0 = x1;
        x1 = x2;
    }
    return x2;
}

int main() {
    double h = 0.8;
    double epsilon = 0.01;
    int iterations;

    cout << fixed << setprecision(5);
    cout << "Значення функції на проміжку [-4; 4] з кроком " << h << ":\n";

    for (double x = -4; x <= 4; x += h) {
        cout << "f(" << x << ") = " << f(x) << endl;
    }

    cout << "\nМетод січних для знаходження кореня на проміжку [-1.6; -0.8]:\n";

    double root = secantMethod(-0.8, -1.6, epsilon, iterations);
    cout << "Знайдений корінь: x = " << root << endl;
    cout << "f(x) = " << f(root) << endl;
    cout << "Кількість ітерацій: " << iterations << endl;

    return 0;
}
