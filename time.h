#pragma once
#include <iostream>
class Time
{
private:
    int hours;
    int minutes;
    int seconds;
    static int count;
public:
    // Конструктор
    Time(int h, int m, int s);
    // Деструктор
    ~Time();
    // Перегрузка унарных операций
    Time operator++();   // ++ добавление минуты к объекту типа Time
    Time operator--();   // -- вычитание минуты из объекта типа Time
    // Перегрузка операций приведения типа
    explicit operator int() const;  // int (явная) – результатом является количество минут (секунды отбрасываются)
    operator bool() const;  // bool (неявная) – результатом является true, если минуты и секунды не равны нулю и false в противном случае
    // Перегрузка бинарных операций
    Time operator+(int minutes) const;  // + Time t, целое число (минуты). Результат должен быть типа Time.
    Time operator-(int minutes) const;  // - Time t, целое число (минуты). Результат должен быть типа Time.
    // Статический метод для получения количества созданных объектов
    static int getCount();
    // Метод для отображения времени
    void display() const;
};