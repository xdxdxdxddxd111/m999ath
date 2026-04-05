#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void task1() {
    setlocale(LC_ALL, "Rus");
    // Проверка точности равенств
    double frac = 19.0 / 12.0;    // Вычисление точного значения 19/12
    double sqrt12 = sqrt(12.0);  // Вычисление точного значения корня из 12

    double error1 = abs(frac - 1.58);  // Абсолютная погрешность первого равенства
    double error2 = abs(sqrt12 - 3.46);  // Абсолютная погрешность второго равенства

    cout << "Задание 1а:\n";  // Вывод заголовка
    cout << "Точность 19/12 = 1.58: " << error1 << endl;  // Вывод погрешности первого равенства
    cout << "Точность sqrt(12) = 3.46: " << error2 << endl;  // Вывод погрешности второго равенства

    if (error1 < error2)  // Сравнение погрешностей
        cout << "Первое равенство точнее\n"; 
    else
        cout << "Второе равенство точнее\n";

    // Округление числа
    double number = 4.88445;  // Исходное число
    double delta = 0.00052;  // Заданная погрешность

    cout << "\nЗадание 1б:\n"; 
    cout << "Исходное число: " << number << " ± " << delta << endl;  // Вывод исходных данных
    double rounded = round(number * 1000.0) / 1000.0;  // Округление до трех знаков
    double absError = 0.001;  // Абсолютная погрешность округления

    cout << "Округленное число: " << rounded << endl;  
    cout << "Абсолютная погрешность: " << absError << endl;

    // Погрешности числа 4.633
    cout << "\nЗадание 1в:\n";  
    double x = 4.633;  // Заданное число
    double absError3 = 0.0005;  // Абсолютная погрешность
    double relError = absError3 / x * 100.0;  // Расчет относительной погрешности

    cout << "Абсолютная погрешность: " << absError3 << endl;  
    cout << "Относительная погрешность: " << relError << "%\n";  
}


void task2() {
    double a = 12.72;
    double b = 0.34;
    double c = 0.0290;

    cout << "\nЗадание 2:\n";

    // Вычисление ln(a)
    double lna = log(a);  // Натуральный логарифм от a
    double delta_lna = 0.001;  // Погрешность вычисления логарифма

    // Вычисление ab
    double ab = a * b;  // Произведение a и b
    double delta_ab = 0.0001;  // Погрешность произведения

    // Вычисление 4c/ln(a)
    double term = 4 * c / lna;  // Вычисление дроби
    double delta_term = 0.0002;  // Погрешность дроби

    // Итоговое вычисление
    double Z = ab - term + b;  // Расчет итогового значения Z

    // Расчет погрешностей
    double delta_Z = sqrt(delta_ab * delta_ab + delta_term * delta_term);  // Абсолютная погрешность результата
    double relError_Z = delta_Z / Z * 100.0;  // Относительная погрешность результата

    cout << "Значение Z: " << fixed << setprecision(4) << Z << endl;
    cout << "Абсолютная погрешность: " << delta_Z << endl;
    cout << "Относительная погрешность: " << relError_Z << "%\n";
}

int main() {
    task1();
    task2();
    return 0;
}
