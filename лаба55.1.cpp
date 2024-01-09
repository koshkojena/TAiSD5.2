#include "Time.h"
#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int h, m, s;
    cout << "Введите часы: ";
    cin >> h;
    cout << "Введите минуты: ";
    cin >> m;
    cout << "Введите секунды: ";
    cin >> s;
    Time t(h, m, s);
    t.display();
    int minutesToAdd;
    cout << "Введите количество минут для добавления: ";
    cin >> minutesToAdd;
    t = t + minutesToAdd;
    t.display();
    int minutesToSubtract;
    cout << "Введите количество минут для вычитания: ";
    cin >> minutesToSubtract;
    t = t - minutesToSubtract;
    t.display();
    int totalMinutes = static_cast<int>(t);
    cout << "Общее количество минут: " << totalMinutes << endl;
    bool nonZero = t;
    cout << "Ненулевое время: " << (nonZero ? "true" : "false") << endl;
    //cout << "Количество объектов времени: " << Time::getCount() << endl;
    return 0;
}