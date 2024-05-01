#include <Windows.h>
#include <iostream>
#include <list>
#include <limits>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string surname;
    string patronimic;

    void print() {
        cout << "Имя: " << name << "\tФамилия: " << surname << "\tОтчество: " << patronimic;
    }

    Student(string name, string surname, string patronimic) : name(name), surname(surname), patronimic(patronimic) {}
};

class Group {
public:
    string name;
    list<Student> students;

    Group() {
        cout << "Введите название группы: ";
        cin >> name;
    }

    void addStudent(const Student& student) {
        students.push_back(student);
    }
};

class Direction {
public:
    string name;
    list<Group> groups;

    Direction(const string& name) : name(name) {}

    void addGroup(const Group& group) {
        groups.push_back(group);
    }
};

int main()
{
    SetConsoleCP(1251);
    setlocale(0, "ru");

    list<Direction> directions;
    int choice;

    do {
        cout << "Что вы хотите сделать?\n1. Добавить направление\n2. Добавить группу\n3. Зарегистрировать студента\n4. Изменить направление\n5. Изменить группу\n6. Изменить студента\n7. Исключить студента\n8. Посмотреть всю информацию о студенте\n9. Выйти из программы\n";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string directionName;
            cout << "Введите название направления: ";
            cin >> directionName;
            directions.push_back(Direction(directionName));
            break;
        }
        case 2:
        {
            string groupName;
            cout << "Введите название группы: ";
            cin >> groupName;

            Group newGroup;
            newGroup.name = groupName;

            string directionName;
            cout << "Введите название направления, в которое добавить группу: ";
            cin >> directionName;

            bool directionExists = false;
            for (auto& dir : directions) {
                if (dir.name == directionName) {
                    dir.addGroup(newGroup);
                    directionExists = true;
                    break;
                }
            }

            if (!directionExists) {
                cout << "Направление с таким названием не найдено. Группа не была добавлена.\n";
            }

            break;
        }
        case 3:
        {
            string studentName, studentSurname, studentPatronimic;

            cout << "Введите имя студента: ";
            cin >> studentName;

            cout << "Введите фамилию студента: ";
            cin >> studentSurname;

            cout << "Введите отчество студента: ";
            cin >> studentPatronimic;

            Student newStudent(studentName, studentSurname, studentPatronimic);

            string groupName;
            cout << "Введите название группы, в которую добавить студента: ";
            cin >> groupName;

            bool groupExists = false;
            for (auto& direction : directions) {
                for (auto& group : direction.groups) {
                    if (group.name == groupName) {
                        group.addStudent(newStudent);
                        groupExists = true;
                        break;
                    }
                }
            }

            if (!groupExists) {
                cout << "Группа с таким названием не найдена. Студент не был зарегистрирован.\n";
            }
            else {
                cout << "Студент успешно зарегистрирован в группе.\n";
            }

            break;
        }
        case 4:
        {
            string directionName;
            cout << "Введите название направления для изменения: ";
            cin >> directionName;

            bool directionFound = false;
            for (auto& direction : directions) {
                if (direction.name == directionName) {
                    directionFound = true;

                    string newDirectionName;
                    cout << "Введите новое название направления: ";
                    cin >> newDirectionName;
                    direction.name = newDirectionName;

                    cout << "Название направления успешно изменено.\n";
                    break;
                }
            }

            if (!directionFound) {
                cout << "Направление с указанным названием не найдено.\n";
            }

            break;
        }
        case 5:
        {
            string groupName;
            cout << "Введите название группы для изменения: ";
            cin >> groupName;

            bool groupFound = false;
            for (auto& direction : directions) {
                for (auto& group : direction.groups) {
                    if (group.name == groupName) {
                        groupFound = true;

                        string newGroupName;
                        cout << "Введите новое название группы: ";
                        cin >> newGroupName;

                        group.name = newGroupName;

                        cout << "Название группы успешно изменено.\n";
                        break;
                    }
                }
            }

            if (!groupFound) {
                cout << "Группа с указанным названием не найдена.\n";
            }

            break;
        }
        case 6:
        {
            string studentName, studentSurname, studentPatronimic;

            cout << "Введите имя студента для изменения данных: ";
            cin >> studentName;

            cout << "Введите фамилию студента: ";
            cin >> studentSurname;

            cout << "Введите отчество студента: ";
            cin >> studentPatronimic;

            bool studentFound = false;
            for (auto& direction : directions) {
                for (auto& group : direction.groups) {
                    for (auto& student : group.students) {
                        if (student.name == studentName && student.surname == studentSurname && student.patronimic == studentPatronimic) {
                            string newName, newSurname, newPatronimic;
                            cout << "Введите новые данные студента:\n";
                            cout << "Имя: ";
                            cin >> newName;
                            cout << "Фамилия: ";
                            cin >> newSurname;
                            cout << "Отчество: ";
                            cin >> newPatronimic;

                            student.name = newName;
                            student.surname = newSurname;
                            student.patronimic = newPatronimic;

                            cout << "Данные студента успешно изменены.\n";
                            studentFound = true;
                            break;
                        }
                    }
                }
            }

            if (!studentFound) {
                cout << "Студент с указанными данными не найден.\n";
            }

            break;
        }
        case 7:
        {
            string studentName, studentSurname, studentPatronimic;

            cout << "Введите имя студента для исключения из группы: ";
            cin >> studentName;

            cout << "Введите фамилию студента: ";
            cin >> studentSurname;

            cout << "Введите отчество студента: ";
            cin >> studentPatronimic;

            bool studentRemoved = false;
            for (auto& direction : directions) {
                for (auto& group : direction.groups) {
                    for (auto it = group.students.begin(); it != group.students.end(); ++it) {
                        if (it->name == studentName && it->surname == studentSurname && it->patronimic == studentPatronimic) {
                            it = group.students.erase(it);
                            cout << "Студент успешно исключен из группы.\n";
                            studentRemoved = true;
                            break;
                        }
                    }
                }
            }

            if (!studentRemoved) {
                cout << "Студент с указанными данными не найден для исключения.\n";
            }

            break;
        }
        case 8:
        {
            string studentName, studentSurname, studentPatronimic;

            cout << "Введите имя студента: ";
            cin >> studentName;

            cout << "Введите фамилию студента: ";
            cin >> studentSurname;

            cout << "Введите отчество студента: ";
            cin >> studentPatronimic;

            bool studentFound = false;
            for (auto& direction : directions) {
                for (auto& group : direction.groups) {
                    for (auto& student : group.students) {
                        if (student.name == studentName && student.surname == studentSurname && student.patronimic == studentPatronimic) {
                            student.print();
                            cout << "\tГруппа: " << group.name << "\tНаправление: " << direction.name << endl;
                            studentFound = true;
                            break;
                        }
                    }
                }
            }

            if (!studentFound) {
                cout << "Студент с указанными данными не найден.\n";
            }

            break;
        }
        case 9:
            cout << "До свидания!";
            break;

        default:
            cout << "Некорректный ввод. Попробуйте снова\n";
        }

    } while (choice != 8);

    return 0;
}