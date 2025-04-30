#include <iostream>
#include <string>
#include <vector>
#include <limits>

// Структура для хранения информации о человеке
struct Person {
    std::string name;
    int age;
};

// Функция для ввода данных человека с проверкой
void inputPerson(Person &p) {
    // Очищаем буфер после ввода числа
    std::cout << "Enter name: ";
    std::getline(std::cin, p.name);  // Читаем имя

    std::cout << "Enter age: ";
    while (true) {
        std::cin >> p.age;  // Читаем возраст
        if (std::cin.fail() || p.age <= 0) {  // Проверка на ошибку ввода
            std::cin.clear();  // Сбрасываем ошибку потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
            std::cout << "Invalid age. Please enter a valid positive integer for age: ";
        } else {
            break;  // Если ввод успешен, выходим из цикла
        }
    }

    std::cin.ignore();  // Очистим буфер после ввода возраста, чтобы избежать проблемы с последующими строками
}

// Функция для вывода информации о человеке
void printPerson(const Person &p) {
    std::cout << "Name: " << p.name << ", Age: " << p.age << std::endl;
}

int main() {
    std::vector<Person> people;  // Массив для хранения людей
    int count;

    std::cout << "How many people do you want to enter? ";
    std::cin >> count;
    std::cin.ignore();  // Очищаем буфер после ввода числа

    for (int i = 0; i < count; ++i) {
        Person p;
        inputPerson(p);  // Вводим данные для каждого человека
        people.push_back(p);  // Добавляем в список
    }

    // Выводим информацию о всех людях
    std::cout << "\nEntered information:\n";
    for (const auto &p : people) {
        printPerson(p);
    }

    return 0;
}