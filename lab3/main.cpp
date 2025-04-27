#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateNextX(double y) { return 2 * log(y) + 2 * y * y;} // calc x


double calculateNextY(double x, double y) { return (2 * x * x - x * y + 2) / 4;}// calc y

bool checkAccuracy(double x_prev, double x_curr, double y_prev, double y_curr, double epsilon) 
{
   return (fabs(x_curr - x_prev) < epsilon) && (fabs(y_curr - y_prev) < epsilon);
}

void checkEquations(double x, double y)  //check var
{
    double eq1 = 2 * x * x - x * y - 4 * y + 2;
    double eq2 = x - 2 * log(y) - 2 * y * y;
    
    std::cout << "Перевірка рівнянь для x = " << x << ", y = " << y << ":" << std::endl;
    std::cout << "2x^2-xy-4y+2 = " << eq1 << std::endl;
    std::cout << "x-2ln(y)-2y^2 = " << eq2 << std::endl;
}

void calculateDerivativeSums(double x, double y) //df/dx df/dy 
{ 

    double df1_dx = 4 * x - y;
    double df1_dy = -x;
    double sum1 = fabs(df1_dx) + fabs(df1_dy);
    
    double df2_dx = 1;
    double df2_dy = -2/y + 4*y;
    double sum2 = fabs(df2_dx) + fabs(df2_dy);
    
    std::cout << "Суми модулів частинних похідних:" << std::endl;
    std::cout << "|df1/dx| + |df1/dy| = " << sum1 << std::endl;
    std::cout << "|df2/dx| + |df2/dy| = " << sum2 << std::endl;
}

int main() {

    double x0 = -0.3;
    double y0 = 0.6;
    double epsilon = 0.01;
    
    std::cout << "Розв'язання системи нелінійних рівнянь методом простої ітерації" << std::endl;
    std::cout << "2x^2-xy-4y+2 = 0" << std::endl;
    std::cout << "x-2ln(y)-2y^2 = 0" << std::endl;
    std::cout << "Початкове наближення: x0 = " << x0 << ", y0 = " << y0 << std::endl;
    std::cout << "Точність: E = " << epsilon << std::endl << std::endl;
    
    calculateDerivativeSums(x0, y0);
    std::cout << std::endl;
    
    double x_prev = x0;
    double y_prev = y0;
    double x_curr, y_curr;
    int iterations = 0;
    
    std::cout << std::fixed << setprecision(6);
    std::cout << "Ітерація " << iterations << ": x = " << x_prev << ", y = " << y_prev << std::endl;
    
    do {
        iterations++;
        
        x_curr = calculateNextX(y_prev);
        y_curr = calculateNextY(x_prev, y_prev);
        
        std::cout << "Ітерація " << iterations << ": x = " << x_curr << ", y = " << y_curr 
             << ", |x - x_prev| = " << fabs(x_curr - x_prev)
             << ", |y - y_prev| = " << fabs(y_curr - y_prev) << std::endl;
        
        x_prev = x_curr;
        y_prev = y_curr;
        
    } while (!checkAccuracy(x_prev, x_curr, y_prev, y_curr, epsilon) && iterations < 100);
    
    
        std::cout << std::endl << "Розв'язок знайдено за " << iterations << " ітерацій:" << std::endl;
        std::cout << "x = " << x_curr << ", y = " << y_curr << std::endl << std::endl;
        
        checkEquations(x_curr, y_curr);
   
    
    return 0;
}