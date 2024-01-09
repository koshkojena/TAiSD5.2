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
    // �����������
    Time(int h, int m, int s);
    // ����������
    ~Time();
    // ���������� ������� ��������
    Time operator++();   // ++ ���������� ������ � ������� ���� Time
    Time operator--();   // -- ��������� ������ �� ������� ���� Time
    // ���������� �������� ���������� ����
    explicit operator int() const;  // int (�����) � ����������� �������� ���������� ����� (������� �������������)
    operator bool() const;  // bool (�������) � ����������� �������� true, ���� ������ � ������� �� ����� ���� � false � ��������� ������
    // ���������� �������� ��������
    Time operator+(int minutes) const;  // + Time t, ����� ����� (������). ��������� ������ ���� ���� Time.
    Time operator-(int minutes) const;  // - Time t, ����� ����� (������). ��������� ������ ���� ���� Time.
    // ����������� ����� ��� ��������� ���������� ��������� ��������
    static int getCount();
    // ����� ��� ����������� �������
    void display() const;
};