#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Задание 1
    std::cout << "Задание 1\n";
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    double x1n, x2n, x3n, x4n;
    double eps = 0.001;
    
    do {
        x1n = 0.15 * x1 + 0.05 * x2 - 0.08 * x3 + 0.16 * x4 - 0.47;
        x2n = 0.32 * x1 - 0.42 * x2 - 0.13 * x3 + 0.11 * x4 + 1.24;
        x3n = 0.17 * x1 + 0.06 * x2 - 0.08 * x3 + 0.12 * x4 + 1.18;
        x4n = 0.21 * x1 - 0.16 * x2 + 0.39 * x3 - 0.84;
        
        if (fabs(x1n - x1) < eps && fabs(x2n - x2) < eps && 
            fabs(x3n - x3) < eps && fabs(x4n - x4) < eps) {
            std::cout << std::fixed << std::setprecision(4);
            std::cout << "x1 = " << x1n << "\nx2 = " << x2n 
                      << "\nx3 = " << x3n << "\nx4 = " << x4n << std::endl;
            break;
        }
        
        x1 = x1n;
        x2 = x2n;
        x3 = x3n;
        x4 = x4n;
    } while (true);
    
    // Задание 2
    std::cout << "\nЗадание 2\n";
    double y1 = 0, y2 = 0, y3 = 0;
    double y1n, y2n, y3n;
    
    // Приведение к виду x = αx + β
    // x1 = (-3.7x2 - 4.2x3 + 5.8)/3.3
    // x2 = (-2.7x1 + 2.9x3 + 6.1)/2.3
    // x3 = (4.1x1 + 4.8x2 - 6.9)/5.1
    
    do {
        y1n = (-3.7 * y2 - 4.2 * y3 + 5.8) / 3.3;
        y2n = (-2.7 * y1n + 2.9 * y3 + 6.1) / 2.3;
        y3n = (4.1 * y1n + 4.8 * y2n - 6.9) / 5.1;
        
        if (fabs(y1n - y1) < eps && fabs(y2n - y2) < eps && fabs(y3n - y3) < eps) {
            std::cout << std::fixed << std::setprecision(4);
            std::cout << "x1 = " << y1n << "\nx2 = " << y2n << "\nx3 = " << y3n << std::endl;
            break;
        }
        
        y1 = y1n;
        y2 = y2n;
        y3 = y3n;
    } while (true);
    
    return 0;
}
