#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> multiplyMatrixVector(const vector<vector<double>>& matrix, const vector<double>& vec) 
{
    vector<double> result(matrix.size(), 0.0);
  
    for (size_t i = 0; i < matrix.size(); ++i) 
    {
        for (size_t j = 0; j < matrix[i].size(); ++j) result[i] += matrix[i][j] * vec[j];
    }
    return result;
}

vector<double> addVectors(const vector<double>& a, const vector<double>& b)
 {
    vector<double> result(a.size());
    for (size_t i = 0; i < a.size(); ++i)  result[i] = a[i] + b[i];
    return result;
}

bool isConverged(const vector<double>& x, const vector<double>& prev_x, double epsilon) 
{
    for (size_t i = 0; i < x.size(); ++i) 
    {
        if (fabs(x[i] - prev_x[i]) >= epsilon) return false;
    }
    return true;
}

vector<double> solveBySimpleIteration(const vector<vector<double>>& iterMatrix, const vector<double>& constVector, double epsilon) {
    size_t n = constVector.size();
    vector<double> x(n, 0.0);     
    vector<double> prev_x(n);
    int iteration = 0;
    
    cout << "Розв'язок методом простої ітерації:" << endl;
    
    do {
        prev_x = x;
        vector<double> iterPart = multiplyMatrixVector(iterMatrix, prev_x);
        x = addVectors(iterPart, constVector);
        
        iteration++;
        
        cout << "Ітерація " << iteration << ": ";
        for (double val : x) {
            cout << fixed << setprecision(5) << val << " ";
        }
        cout << endl;
        
    } while (!isConverged(x, prev_x, epsilon) && iteration < 100);
    
    return x;
}

int main() {
    
    vector<vector<double>> iterMatrix = {
        {0,    0.5,  0.5},
        {0.5,  0,    0.5},
        {-1.0/6, 0.5,  0}
    };
    
    vector<double> constVector = {-7.5, -5, -2};
    
    vector<double> solution = solveBySimpleIteration(iterMatrix, constVector, 0.01);
    
    cout << "\nЗнайдене рішення:" << endl;
    for (size_t i = 0; i < solution.size(); ++i) cout << "x" << i+1 << " = " << solution[i] << endl;
    
    return 0;
}