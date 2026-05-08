#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double eps = 0.001;
    double x[4] = {0, 0, 0, 0};      // текущие значения
    double x_new[4];                  // новые значения
    double B[4][4] = {                // коэффициенты
        {0.15, 0.05, -0.08, 0.16},
        {0.32, -0.42, -0.13, 0.11},
        {0.17, 0.06, -0.08, 0.12},
        {0.21, -0.16, 0.39, 0}
    };
    double g[4] = {-0.47, 1.24, 1.18, -0.84};  // свободные члены
    int iter = 0;
    
    cout << "Решение системы методом простой итерации\nТочность: " << eps << "\n\n";
    
    do {
        double max_diff = 0;
        
        // вычисляем новые значения
        for (int i = 0; i < 4; i++) {
            x_new[i] = g[i];
            for (int j = 0; j < 4; j++) {
                x_new[i] += B[i][j] * x[j];
            }
            // считаем погрешность
            double diff = fabs(x_new[i] - x[i]);
            if (diff > max_diff) max_diff = diff;
        }
        
        // выводим результат итерации
        iter++;
        cout << "Итерация " << iter << ": ";
        cout << "x1=" << x_new[0] << " x2=" << x_new[1] << " ";
        cout << "x3=" << x_new[2] << " x4=" << x_new[3] << " ";
        cout << "погрешность=" << max_diff << endl;
        
        // обновляем переменные (без этого никак)
        for (int i = 0; i < 4; i++) {
            x[i] = x_new[i];
        }
        
        if (max_diff < eps || iter >= 100) break;
        
    } while (true);
    
    cout << "\nРезультат:\n";
    cout << "x1 = " << x[0] << "\nx2 = " << x[1] << "\nx3 = " << x[2] << "\nx4 = " << x[3] << endl;
    
    return 0;
}
