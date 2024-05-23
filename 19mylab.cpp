#include <iostream>
#include <string>
#include <list>

struct Abonent {
    std::string phoneNumber;
    std::string fullName;
    std::string passportNumber;
};

bool compareAbonent(const Abonent &a, const Abonent &b) {
    return a.fullName < b.fullName;
}

int main() {
    std::list<Abonent> cardIndex;

    // Ввод количества абонентов
    int n;
    std::cout << "Введите количество абонентов: ";
    std::cin >> n;
    std::cin.ignore(); // очистка буфера

    // Ввод данных абонентов
    for (int i = 0; i < n; ++i) {
        Abonent abonent;
        std::cout << "Введите номер телефона: ";
        std::getline(std::cin, abonent.phoneNumber);
        std::cout << "Введите ФИО владельца: ";
        std::getline(std::cin, abonent.fullName);
        std::cout << "Введите паспортные данные (номер): ";
        std::getline(std::cin, abonent.passportNumber);

        cardIndex.push_back(abonent);
    }

    // Сортировка по алфавиту
    cardIndex.sort(compareAbonent);

    // Вывод всей картотеки
    std::cout << "\nКартотека абонентов:\n";
    for (const Abonent &abonent : cardIndex) {
        std::cout << "Номер телефона: " << abonent.phoneNumber << std::endl;
        std::cout << "ФИО владельца: " << abonent.fullName << std::endl;
        std::cout << "Паспортные данные (номер): " << abonent.passportNumber << std::endl;
        std::cout << std::endl;
    }

    // Ввод номера телефона и поиск владельца
    std::string searchPhoneNumber;
    std::cout << "Введите номер телефона для поиска: ";
    std::getline(std::cin, searchPhoneNumber);

    bool found = false;
    for (const Abonent &abonent : cardIndex) {
        if (abonent.phoneNumber == searchPhoneNumber) {
            std::cout << "Владелец номера " << searchPhoneNumber << " - " << abonent.fullName << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Абонент с номером " << searchPhoneNumber << " не найден!" << std::endl;
    }

    return 0;
}