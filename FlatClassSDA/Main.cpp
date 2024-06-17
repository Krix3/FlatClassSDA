#include <iostream>
#include <windows.h>

using namespace std;

class Flat {
private:
    double area; // ������� ��������
    double price; // ���� ��������

public:
    // �����������
    Flat(double area = 0.0, double price = 0.0) : area(area), price(price) {}

    // ���������� ��������� ==
    bool operator==(const Flat& other) const
    {
        return this->area == other.area;
    }

    // ���������� ��������� ������������ =
    Flat& operator=(const Flat& other)
    {
        if (this != &other)
        {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // ���������� ��������� >
    bool operator>(const Flat& other) const
    {
        return this->price > other.price;
    }

    // ����� ��� ������ ���������� � ��������
    void print() const
    {
        std::cout << "�������: " << area << " �.��, ����: " << price << " USD" << std::endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Flat flat1(50.0, 100000.0);
    Flat flat2(60.0, 120000.0);
    Flat flat3(50.0, 110000.0);

    std::cout << "�������� 1: ";
    flat1.print();
    std::cout << "�������� 2: ";
    flat2.print();
    std::cout << "�������� 3: ";
    flat3.print();

    // �������� �� ��������� ��������
    if (flat1 == flat3)
    {
        std::cout << "�������� 1 � �������� 3 ����� ���������� �������." << std::endl;
    }
    else
    {
        std::cout << "�������� 1 � �������� 3 ����� ������ �������." << std::endl;
    }

    // ��������� �� ����
    if (flat2 > flat1)
    {
        std::cout << "�������� 2 ������, ��� �������� 1." << std::endl;
    }
    else
    {
        std::cout << "�������� 2 ������� ��� ����� �� ���� �������� 1." << std::endl;
    }

    // ������������ ������ ������� �������
    flat1 = flat2;
    std::cout << "����� ���������� �������� 2 �������� 1, �������� 1: ";
    flat1.print();

    return 0;
}