#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXN = 10;

int rndInt() {
    return rand() % 201 - 100;
}

double rndDouble() {
    return (rand() % 2001 - 1000) / 10.0;
}

int rndPositive(int minV, int maxV) {
    return rand() % (maxV - minV + 1) + minV;
}

int readN() {
    int n;
    do {
        cout << "Введите n (1.." << MAXN << "): ";
        cin >> n;
    } while (n < 1 || n > MAXN);
    return n;
}

void printDouble(double a[], int n) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void printInt(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void z1() {
    int n = readN();
    int a[MAXN];

    for (int i = 0; i < n; ++i) {
        a[i] = rndInt();
    }

    cout << "Исходный массив: ";
    printInt(a, n);

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            a[i] = a[i] * a[i];
        }
        else {
            a[i] = a[i] * 2;
        }
    }

    cout << "Изменённый массив: ";
    printInt(a, n);
}

void z2() {
    int n = readN();
    int a[MAXN];

    for (int i = 0; i < n; ++i) {
        a[i] = rndInt();
    }

    int beta;
    cout << "Введите beta: ";
    cin >> beta;

    cout << "Массив: ";
    printInt(a, n);

    int countPositive = 0;
    long long sumNegative = 0;
    int lastLessBeta = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            ++countPositive;
        }
        if (a[i] < 0) {
            sumNegative += a[i];
        }
        if (a[i] < beta) {
            lastLessBeta = i + 1;
        }
    }

    cout << "Количество положительных элементов: " << countPositive << "\n";
    cout << "Сумма отрицательных элементов: " << sumNegative << "\n";

    if (lastLessBeta == 0) {
        cout << "Нет элементов меньше beta\n";
    }
    else {
        cout << "Номер последнего элемента меньше beta: " << lastLessBeta << "\n";
    }
}

void z3() {
    int n = readN();
    int weight[MAXN];

    for (int i = 0; i < n; ++i) {
        weight[i] = rndPositive(30, 150);
    }

    cout << "Веса: ";
    printInt(weight, n);

    int minW = weight[0];
    int maxW = weight[0];

    for (int i = 1; i < n; ++i) {
        if (weight[i] < minW) minW = weight[i];
        if (weight[i] > maxW) maxW = weight[i];
    }

    cout << "Самый лёгкий: " << minW << "\n";
    cout << "Самый тяжёлый: " << maxW << "\n";
    if (maxW > 2 * minW) {
        cout << "Да, превышает более чем в 2 раза\n";
    }
    else {
        cout << "Нет, не превышает более чем в 2 раза\n";
    }
}

void z4() {
    int n = readN();
    int a[MAXN];

    for (int i = 0; i < n; ++i) {
        a[i] = rndInt();
    }

    cout << "Исходный массив: ";
    printInt(a, n);

    int newN = n;

    for (int i = 0; i < newN; ) {
        if (a[i] < 0) {
            for (int j = i; j < newN - 1; ++j) {
                a[j] = a[j + 1];
            }

            a[newN - 1] = 0;
            --newN;
        }
        else {
            ++i;
        }
    }

    cout << "Массив после удаления отрицательных элементов: ";
    printInt(a, newN);
}

void z5() {
    const int cars = 25;
    double minSpeed = 1e100;

    cout << fixed << setprecision(2);

    for (int i = 0; i < cars; ++i) {
        int length = rndPositive(1, 100);
        int time = rndPositive(1, 20);

        while (time == 0) {
            time = rndInt();
        }

        double speed = (double)length / time;

        cout << "Автомобиль " << i + 1
            << ": путь = " << length
            << " км, время = " << time
            << " ч, скорость = " << speed << " км/ч\n";

        if (speed < minSpeed) {
            minSpeed = speed;
        }
    }

    cout << "Минимальная средняя скорость: " << minSpeed << " км/ч\n";
}

int main() {
    setlocale(LC_ALL, "RUS");

    int choice;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1 — Задание 1\n";
        cout << "2 — Задание 2\n";
        cout << "3 — Задание 3\n";
        cout << "4 — Задание 4\n";
        cout << "5 — Задание 5\n";
        cout << "0 — Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: z1(); break;
        case 2: z2(); break;
        case 3: z3(); break;
        case 4: z4(); break;
        case 5: z5(); break;
        default:
            cout << "Нет такого пункта меню.\n";
        }
    }
    return 0;
}
    