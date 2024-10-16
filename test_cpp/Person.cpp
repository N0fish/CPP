#include "Person.hpp"
#include <iostream>

// Конструктор по умолчанию
Person::Person() : name("Неизвестно"), age(0) {
    std::cout << "Конструктор по умолчанию вызван!" << std::endl;
}

// Конструктор с параметрами
Person::Person(const std::string& name, int age) : name(name), age(age) {
    std::cout << "Конструктор с параметрами вызван!" << std::endl;
}

// Деструктор
Person::~Person() {
    std::cout << "Деструктор вызван! Объект " << name << " удалён." << std::endl;
}

// Метод для вывода информации о человеке
void Person::introduce() const {
    std::cout << "Привет! Меня зовут " << name << ", мне " << age << " лет." << std::endl;
}

// Сеттеры (устанавливают значения)
void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setAge(int newAge) {
    age = newAge;
}

// Геттеры (возвращают значения)
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

int main() {
    // Создание объекта с использованием конструктора по умолчанию
    Person person1;
    person1.introduce();  // Привет! Меня зовут Неизвестно, мне 0 лет.

    // Изменяем имя и возраст с помощью сеттеров
    person1.setName("Алексей");
    person1.setAge(25);
    person1.introduce();  // Привет! Меня зовут Алексей, мне 25 лет.

    // Создание объекта с использованием конструктора с параметрами
    Person person2("Мария", 30);
    person2.introduce();  // Привет! Меня зовут Мария, мне 30 лет.

    return 0;
}
