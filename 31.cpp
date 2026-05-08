#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double eps = 0.001;
    double x1 = 0, x2 = 0, x3 = 0;
    double x1_old, x2_old, x3_old;
    int iter = 0;
    
    cout << "Решение системы методом Зейделя" << endl;
    cout << "Точность: " << eps << endl << endl;
    
    do {
        x1_old = x1;
        x2_old = x2;
        x3_old = x3;
        
        x1 = (5.8 - 3.7 * x2 - 4.2 * x3) / 3.3;
        x2 = (6.1 - 2.7 * x1 + 2.9 * x3) / 2.3;
        x3 = (6.9 - 4.1 * x1 - 4.8 * x2) / (-5.1);
        
        iter++;
        
        double diff1 = fabs(x1 - x1_old);
        double diff2 = fabs(x2 - x2_old);
        double diff3 = fabs(x3 - x3_old);
        
        double max_diff = diff1;
        if (diff2 > max_diff) max_diff = diff2;
        if (diff3 > max_diff) max_diff = diff3;
        
        cout << "Итерация " << iter << ": ";
        cout << "x1=" << x1 << " x2=" << x2 << " x3=" << x3;
        cout << " погрешность=" << max_diff << endl;
        
        if (max_diff < eps || iter >= 100) break;
        
    } while (true);
    
    cout << "\nРезультат:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    
    return 0;
}
