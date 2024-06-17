#include <iostream>
#include <windows.h>

using namespace std;

class Flat {
private:
    double area; // Площадь квартиры
    double price; // Цена квартиры

public:
    // Конструктор
    Flat(double area = 0.0, double price = 0.0) : area(area), price(price) {}

    // Перегрузка оператора ==
    bool operator==(const Flat& other) const
    {
        return this->area == other.area;
    }

    // Перегрузка оператора присваивания =
    Flat& operator=(const Flat& other)
    {
        if (this != &other)
        {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // Перегрузка оператора >
    bool operator>(const Flat& other) const
    {
        return this->price > other.price;
    }

    // Метод для вывода информации о квартире
    void print() const
    {
        std::cout << "Площадь: " << area << " м.кв, Цена: " << price << " USD" << std::endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Flat flat1(50.0, 100000.0);
    Flat flat2(60.0, 120000.0);
    Flat flat3(50.0, 110000.0);

    std::cout << "Квартира 1: ";
    flat1.print();
    std::cout << "Квартира 2: ";
    flat2.print();
    std::cout << "Квартира 3: ";
    flat3.print();

    // Проверка на равенство площадей
    if (flat1 == flat3)
    {
        std::cout << "Квартира 1 и квартира 3 имеют одинаковую площадь." << std::endl;
    }
    else
    {
        std::cout << "Квартира 1 и квартира 3 имеют разную площадь." << std::endl;
    }

    // Сравнение по цене
    if (flat2 > flat1)
    {
        std::cout << "Квартира 2 дороже, чем квартира 1." << std::endl;
    }
    else
    {
        std::cout << "Квартира 2 дешевле или равна по цене Квартире 1." << std::endl;
    }

    // Присваивание одного объекта другому
    flat1 = flat2;
    std::cout << "После присвоения Квартира 2 Квартира 1, Квартира 1: ";
    flat1.print();

    return 0;
}