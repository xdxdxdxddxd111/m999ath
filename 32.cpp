#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    // Точность
    double eps = 0.001;

    // Начальные значения
    double x1 = 0;
    double x2 = 0;
    double x3 = 0;

    // Переменная новых значений
    double new_x1, new_x2, new_x3;

    // Счетчик переменой
    int iteration = 0;

    // Максимальное число итераций
    int maxIterations = 100;

    while (iteration < maxIterations) // цикл работает пока счётчик итераций не достигнет 100
    {
        // Сохраняем старые значения
        double old_x1 = x1;
        double old_x2 = x2;
        double old_x3 = x3;

        // Формулы метода Зейделя
        new_x1 = (5.8 - 3.7 * old_x2 - 4.2 * old_x3) / 3.3;

        new_x2 = (6.1 - 2.7 * new_x1 + 2.9 * old_x3) / 2.3;

        new_x3 = (4.1 * new_x1 + 4.8 * new_x2 - 6.9) / 5.1;

        // Обновляем значения
        x1 = new_x1;
        x2 = new_x2;
        x3 = new_x3;

        iteration++;

        // Вывод итерации
        cout << "Итерация " << iteration << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
        cout << "-------------------" << endl;

        // Проверка точности
        if (
            fabs(x1 - old_x1) < eps &&
            fabs(x2 - old_x2) < eps &&
            fabs(x3 - old_x3) < eps
            )
        {
            break;
        }
    }

    // Вывод результата
    cout << endl;
    cout << "Результат:" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    return 0;
}









































//Если препод спросит «почему метод плохо сходится»
//
//Говоришь - Для данной системы не выполняется условие диагонального преобладания, поэтому метод Зейделя может расходиться.
