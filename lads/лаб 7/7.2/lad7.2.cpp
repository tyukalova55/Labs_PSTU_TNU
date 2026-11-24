#include <iostream>
#include <cmath>
#include <cstdarg>
#include <clocale>

using namespace std;

struct Point {
double x, y;
};

double side(Point a, Point b) {
return sqrt(pow(b.x - a.x, 2) +
pow(b.y - a.y, 2));
}

// Функция проверки положения точки
double cross(Point a, Point b, Point m) {
return (b.x - a.x) * (m.y - a.y) -
(b.y - a.y) * (m.x - a.x);
}

// Функция проверки принадлежности треугольнику
bool belong(Point m, Point a, Point b, Point c) {
double x1 = cross(a, b, m);
double x2 = cross(b, c, m);
double x3 = cross(c, a, m);

if ((x1 >= 0 && x2 >= 0 && x3 >= 0) ||
(x1 <= 0 && x2 <= 0 && x3 <= 0))
return true;

return false;
}

// Функция с переменным количеством параметров
bool belong(double mx, double my, int n, ...) {
Point m = {mx, my};

if (n < 3)
return false;

Point p[100];

va_list args;
va_start(args, n);

for (int i = 0; i < n; i++) {
p[i].x = va_arg(args, double);
p[i].y = va_arg(args, double);
}

va_end(args);

bool plus = false;
bool minus = false;

for (int i = 0; i < n; i++) {
double s = cross(p[i], p[(i + 1) % n], m);

if (s > 0)
plus = true;

if (s < 0)
minus = true;
}

if (plus && minus)
return false;

return true;
}

int main() {
system("chcp 65001 > nul");

Point m = {4, 2};

cout << "Координаты точки M: "
<< m.x << " " << m.y << endl;

// Проверка треугольника
Point a = {0, 0};
Point b = {4, 0};
Point c = {2, 4};

if (belong(m, a, b, c))
cout << "Точка принадлежит треугольнику" << endl;
else
cout << "Точка не принадлежит треугольнику" << endl;

// Проверка квадрата
if (belong(2.0, 2.0, 4,
0.0, 0.0,
4.0, 0.0,
4.0, 4.0,
0.0, 4.0))
cout << "Точка принадлежит квадрату" << endl;
else
cout << "Точка не принадлежит квадрату" << endl;

// Проверка другого треугольника
if (belong(2.0, 2.0, 3,
0.0, 0.0,
1.0, 0.0,
0.0, 1.0))
cout << "Точка принадлежит третьему треугольнику" << endl;
else
cout << "Точка не принадлежит третьему треугольнику" << endl;

// Нахождение длины стороны
cout << "Длина стороны AB = "
<< side(a, b) << endl;

return 0;
}
