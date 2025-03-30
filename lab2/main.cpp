#include <iostream>
#include <vector>
#include <cmath>


bool Solution(const std::vector<double>& x, const std::vector<double>& prev_x, double epsilon)
{
    for (size_t i = 0; i < x.size(); i++)  {if (fabs(x[i] - prev_x[i]) >= epsilon) return false; }
    return true;
}

int main() 
{
    const double epsilon = 0.01;
    std::vector<double> x = {0, 0, 0}; 
    std::vector<double> prev_x(3);
    int iterations = 0;

    std::cout << "Розв'язок методом простої ітерації:" << std::endl;
    
    do {
        prev_x = x;

        
        x[0] = (15 - prev_x[1] - prev_x[2]) / -2;
        x[1] = (10 - prev_x[0] - prev_x[2]) / -2;
        x[2] = (12 + prev_x[0] - 3 * prev_x[1]) / -6;

        iterations++;
        
        std::cout << "Ітерація " << iterations << ": x1 = " << x[0] << ", x2 = " << x[1] << ", x3 = " << x[2] << std::endl;
    } while (!Solution(x, prev_x, epsilon));

    std::cout << "Знайдене рішення: x1 = " << x[0] << ", x2 = " << x[1] << ", x3 = " << x[2] << std::endl;
    return 0;
}
