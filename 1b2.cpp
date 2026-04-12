#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a = 12.72;
    double b = 0.34;
    double c = 0.0290;
    
    std::cout << "Порядок выполняемых операций:\n"; 
    std::cout << "1) a * b = " << a << " * " << b << " = " << a * b << std::endl;
    
    double ab = a * b;
    std::cout << "2) 4 * c = 4 * " << c << " = " << 4.0 * c << std::endl;
    
    double four_c = 4.0 * c;
    std::cout << "3) ab - 4c = " << ab << " - " << four_c << " = " << ab - four_c << std::endl;
    
    double numerator = ab - four_c;
    std::cout << "4) ln(a) = ln(" << a << ") = " << std::log(a) << std::endl;
    
    double ln_a = std::log(a);
    std::cout << "5) ln(a) + b = " << ln_a << " + " << b << " = " << ln_a + b << std::endl;
    
    double denominator = ln_a + b;
    std::cout << "6) Z = (ab-4c) / (ln a + b) = " << numerator << " / " << denominator << " = ";
    
    double Z = numerator / denominator;
    std::cout << Z << std::endl;
    
    // оценка погрешностей
    double da = 0.005, db = 0.005, dc = 0.00005;
  
    // вычисление частных производных
    double dZ_da = (b * denominator - numerator * (1.0/a)) / (denominator * denominator);
    double dZ_db = (a * denominator - numerator * 1.0) / (denominator * denominator);
    double dZ_dc = (-4.0) / denominator;
  
    // расчёт абсолютной и относительной погрешности:
    double absError = std::abs(dZ_da) * da + std::abs(dZ_db) * db + std::abs(dZ_dc) * dc;
    double relError = absError / std::abs(Z);
  
    int digits = -std::floor(std::log10(absError)); // колл-во знаков после запятой
    double roundedZ = std::round(Z * std::pow(10, digits)) / std::pow(10, digits); // округление числа
    
    std::cout << "\nИскомое значение: " << roundedZ << " ± " << absError << std::endl;
    std::cout << "Абсолютная погрешность: ±" << absError << std::endl;
    std::cout << "Относительная погрешность: ±" << relError * 100 << "%" << std::endl;
    
    return 0;
}
