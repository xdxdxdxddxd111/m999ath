#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // a)
    double true1 = 19.0 / 12.0; // вычисляет точное значение дроби
    double approx1 = 1.58; // приближенное значение
    double absErr1 = std::abs(true1 - approx1); // вычисляем абсолютную погрешность, (модуль разности точного и приближённого)
    double relErr1 = absErr1 / std::abs(true1);  // вычисляем относительную погрешность (абсолютная погрешность / модуль точного значения)

    double true2 = std::sqrt(12); // функция вычисления квадратного корня
    double approx2 = 3.46; // приближённое значение
    double absErr2 = std::abs(true2 - approx2); // абсолютная погрешность для корня12
    double relErr2 = absErr2 / std::abs(true2); // относительная погрешность для корня12

    std::cout << "a) 19/12 = " << true1 << ", приближение 1,58, абсолютная погрешность = " << absErr1 << ", относительная = " << relErr1 << std::endl;
    std::cout << "   sqrt(12) = " << true2 << ", приближение 3,46, абсолютная погрешность = " << absErr2 << ", относительная = " << relErr2 << std::endl;
    if (relErr1 < relErr2) // cравниваем относительные погрешности < 
        std::cout << "   Точнее равенство: 19/12 ≈ 1,58\n";
    else
        std::cout << "   Точнее равенство: √12 ≈ 3,46\n";

    // б)
    double num = 4.88445; // исходное число
    double absError = 0.00052; // абсолютная погрешность (сомнительная цифра в 4-м знаке после запятой | верные числа до тысячных)

    double rounded = std::round(num * 1000.0) / 1000.0; // сдвигаем запятую на 3 знака вправо и округляем до целого, после возвращаем запятую
    double newAbsError = std::abs(num - rounded) + absError; // погрешность после округления + исходная погрешность = общая погрешность после округления
  
    std::cout << std::fixed << std::setprecision(6); // 6 знаков после запятой для погрешности
    std::cout << "\nб) Исходное: 4,88445 ± 0,00052\n";
    std::cout << "   Округлённое: " << std::setprecision(3) << rounded << " ± " << newAbsError << std::endl;

    // в)
    double num3 = 4.633;
    double limitAbs = 0.0005; // половина единицы последнего разряда
    double limitRel = limitAbs / std::abs(num3); // предельная абсолютная / модуль числа
    std::cout << "\nв) Число: 4,633 (все цифры верные)\n";
    std::cout << "   Предельная абсолютная погрешность: ±" << limitAbs << std::endl;
    std::cout << "   Предельная относительная погрешность: ±" << limitRel << std::endl;

    return 0;
}
