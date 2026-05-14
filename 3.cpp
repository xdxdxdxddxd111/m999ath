#include <iostream>   // для cout (вывод на экран)
#include <cmath>      // для fabs (модуль числа)
#include <iomanip>    // для setprecision (количество знаков после запятой)

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    double eps = 0.001;   // точность
    int maxIter = 1000;   // защита от бесконечного цикла

    // Начальное приближение все x = 0
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0;

    cout << fixed << setprecision(6); // вывод 6 знаков после запятой
    cout << "Начальное приближение: x1=0, x2=0, x3=0, x4=0" << endl << endl;

    // --- Главный цикл итераций ---
    for (int iter = 1; iter <= maxIter; iter++) {

        // Считаем новые значения по формулам из системы
        // Используем СТАРЫЕ значения x1, x2, x3, x4 (это и есть метод простой итерации)
        double new_x1 = 0.15 * x1 + 0.05 * x2 - 0.08 * x3 + 0.16 * x4 - 0.47;
        double new_x2 = 0.32 * x1 - 0.42 * x2 - 0.13 * x3 + 0.11 * x4 + 1.24;
        double new_x3 = 0.17 * x1 + 0.06 * x2 - 0.08 * x3 + 0.12 * x4 + 1.18;
        double new_x4 = 0.21 * x1 - 0.16 * x2 + 0.39 * x3 - 0.84;

        cout << "Итерация " << iter << ": ";
        cout << "x1=" << new_x1 << "  x2=" << new_x2 << "  x3=" << new_x3 << "  x4=" << new_x4 << endl;

        // Проверяем точность
        double diff = fabs(new_x1 - x1);
        if (fabs(new_x2 - x2) > diff) diff = fabs(new_x2 - x2);
        if (fabs(new_x3 - x3) > diff) diff = fabs(new_x3 - x3); 
        if (fabs(new_x4 - x4) > diff) diff = fabs(new_x4 - x4);

        // Обновляем x (новые значения становятся старыми для следующей итерации)
        x1 = new_x1;
        x2 = new_x2;
        x3 = new_x3;
        x4 = new_x4;

        if (diff < eps) {
            cout << endl << "Решение найдено за " << iter << " итераций!" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
            cout << "x3 = " << x3 << endl;
            cout << "x4 = " << x4 << endl;
            return 0;
        }
    }

    return 0;
}
