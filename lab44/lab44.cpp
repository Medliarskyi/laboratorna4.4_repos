#include <iostream>
#include <cmath>
#include <iomanip> // для setw
using namespace std;

int main() {
    double x1, xn, d; // початкове значення, кінцеве значення та крок
    double R; // вхідний параметр
    double y; // результат обчислення виразу

    // Введення значення R з перевіркою
    cout << "R = ";
    cin >> R;
    while (R <= 0) {
        cout << "Enter R > 0" << endl;
        cout << "R = ";
        cin >> R;
    }

    // Введення інтервалу та кроку
    cout << "Enter start value x1: ";
    cin >> x1;
    cout << "Enter end value xn: ";
    cin >> xn;
    cout << "Enter step d: ";
    cin >> d;

    // Заголовок таблиці
    cout << setw(10) << "x" << setw(10) << "y" << endl;
    cout << "-------------------" << endl;

    // Цикл для обчислення значень на заданому інтервалі
    for (double x = x1; x <= xn; x += d) {
        // Розгалуження в повній формі
        if (x <= -8 - R)
            y = -R;
        else if (-8 - R < x && x <= -8 + R) {
            // Розрахунок значення під коренем для кола
            double value_under_sqrt = pow(R, 2) - pow(x + 8, 2);

            // Перевірка, чи значення під коренем не є від'ємним
            if (value_under_sqrt >= 0)
                y = -R + sqrt(value_under_sqrt);  // Обчислення значення функції
            else {
                cout << "Warning: sqrt of negative number at x = " << x << endl;
                y = -R;  // Встановлення значення, якщо значення під коренем некоректне
            }
        }
        else if (-8 + R < x && x <= 2)
            y = (1. / 2) * x + 1;
        else if (2 < x && x <= 6)
            y = 0;
        else
            y = pow((x - 6), 2);

        // Вивід результату в таблиці
        cout << setw(10) << x << setw(10) << y << endl;
    }

    return 0;
}