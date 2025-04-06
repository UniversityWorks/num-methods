#include <iostream>
#include <cmath>
#include <iomanip>


double f(double x) 
{
    return x * x - 2 * x - 4;
}

double df(double x)
{
    return 2 * x - 2;
}

double secantMethod(double x0, double x1, double epsilon, int &iterations) 
{
    double x2;
    iterations = 0;

    while (true) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
        iterations++;
        std::cout << "x" << iterations << " = " << x2 << std::endl; 
        if (fabs(f(x2)) < epsilon) break;

        x0 = x1;
        x1 = x2;
    }
    return x2;
}

double second_root(double root1, double root2)
{
    return root1 - root2/10.0;
}

int main() 
{
    double h = 0.8;
    double epsilon = 0.01;
    int iterations;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Значення функції на проміжку [-4; 4] з кроком " << h << ":\n";
    std::cout << "Знайдемо корені рівняння: " << std::endl;

    for (double x = -3.2; x <= 4; x += h)
    {
        bool checker = true;

        std::cout << "f(" << x << ") = " << f(x) << std::endl;
        if (f(x) < 0 && f(x-0.8) > 0 || f(x) > 0 && f(x-0.8) < 0 )
        {
            std::cout << "Знайдено Проміжок зміни знаку f(x): " << std::endl;
            std::cout << "Уточнення коренів f'(x):" << std::endl;

            for (double dx = x-0.8; dx <= x; dx+=0.2)
            {
                std::cout << "f'(" << dx << ") = " << df(dx) << std::endl;
              
                if(df(dx) < 0 && df(dx-0.2) > 0 || df(dx) > 0 && df(dx-0.2) < 0 )
                {
                    std::cout << "Зміна знаку в точках на проміжку." << std::endl;
                    checker = false;
                }
                
            }

        }

        if(checker && f(x) < 0 && f(x-0.8) > 0 || checker &&f(x) > 0 && f(x-0.8) < 0 )
        {
            std::cout << "корені x0 та x1 для методу січних: [" << x-0.8 << ';' <<  second_root(x-0.8, x) << "]." << std::endl;
            std::cout << "\nМетод січних для знаходження кореня на проміжку [" << f(x-0.8) << ';' <<  second_root(x-0.8, x) << "]: " << std::endl;

            double root = secantMethod(x-0.8, second_root(x-0.8, x), epsilon, iterations);
            std::cout << "Знайдений корінь: x = " << root << std::endl;
            std::cout << "f(x) = " << f(root) << std::endl;
            std::cout << "Кількість ітерацій: " << iterations << std::endl;
        
        }
        
    }
    

   
      
    



    return 0;
}
