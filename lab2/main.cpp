#include <iostream>
#include <vector>
#include <cmath>

bool isConverged(std::vector<double>& x, std::vector<double>& prev_x, double epsilon)
{

    for (size_t i = 0; i < x.size(); ++i) if (fabs(x[i] - prev_x[i]) >= epsilon) return false;
   
    return true;

}

std::vector<double> iterate(const std::vector<double>& prev_x)
{
    std::vector<double> x(3);
    x[0] = (15 - prev_x[1] - prev_x[2]) / -2;
    x[1] = (10 - prev_x[0] - prev_x[2]) / -2;
    x[2] = (12 + prev_x[0] - 3 * prev_x[1]) / -6;
    return x;
}

int main() {
    const double epsilon = 0.01;
    int iterations = 0;

    std::vector<double> x = {0, 0, 0};
    std::vector<double> prev_x(3);

    std::cout << "Розв'язок методом простої ітерації:\n";

    do {
        prev_x = x;
        x = iterate(prev_x);

        iterations++;
        std::cout << "Ітерація " << iterations << ": ";
        for (double val : x) std::cout << val << " ";
        std::cout << "\n";

    } while (!isConverged(x, prev_x, epsilon));

    std::cout << "\nЗнайдене рішення:\n";
    for (int i = 0; i < x.size(); ++i) std::cout << "x" << i + 1 << " = " << x[i] << "\n";

    return 0;
}
