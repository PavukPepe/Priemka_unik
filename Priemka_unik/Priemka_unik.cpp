// Priemka_unik.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <list>
using namespace std;

list<Direction> directions;


class Direction {
    string name;
    list<Group> groups;

    Direction(string name) {
        this->name = name;
    }
};

class Group {
    string name;
    list<Student> students;

    Group() {
        cout << "Введите название группы\n";
        cin >> name;
    }

};

class Student {
public:
    string name;
    string surname;
    string patronimic;

    void print() {
        cout << "Имя: " << name << "\tФамилия: " << surname << "\tОтчество: " << patronimic;
    }

    Student(string name, string surname, string patronimic) {
        this->name = name;
        this->surname = surname;
        this->patronimic = patronimic;
    }
};



int main()
{
    SetConsoleCP(1251);
    setlocale(0, "ru");
    int s;
    do {
        cout << "Что вы хотите сделать?\n1. Добавить направление\n2. Добавить группу\n3. Зарегистрировать студента\n4. Изменить направление\n5. Изменить группу\n6. Изменить студента\n7. Исключить студента\n";
        cin >> s;
        string name;
        cin >> name;
        Direction a = Direction("asd");
        switch (s)
        {
        case(1):
            cin >> name;
            Direction a = Direction(name);
            break;
        case(2):
            cin >> b;
            acc1.withdrow(b);
            break;
        case(3):
            cout << acc1.getBalance() << "\n";
            break;
        case(4):
            cout << acc1.getInterest() << "\n";
            break;
        case(5):
            cin >> b;
            acc1.setInterestRate(b);
            break;
        case(6):
            cout << acc1.getAccountNumber() << "\n";
            break;
        case(7):
            cout << "Введите номер аккаунта на который хотите перевести деньги\n";
            cin >> n;
            if (n == acc2.getAccountNumber()) {
                cout << "Сколько хотите перевести?\n";
                cin >> b;
                trancfer(acc1, acc2, b);
                break;
            }
            else {
                cout << "Такого аккаунта нет!\n";
                break;
            }
            break;
        case(8):
            cout << "Пока!";
            break;
        }
    } while (s != 8);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
