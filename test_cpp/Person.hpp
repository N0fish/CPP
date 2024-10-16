#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
    // Приватные данные (инкапсуляция)
    private:
        std::string name;
        int age;

    // Публичные методы
    public:
        // Конструкторы
        Person();  // Конструктор по умолчанию
        Person(const std::string& name, int age);  // Конструктор с параметрами

        // Деструктор
        ~Person();

        // Методы
        void introduce() const;  // Метод для вывода информации

        // Сеттеры
        void setName(const std::string& newName);
        void setAge(int newAge);

        // Геттеры
        std::string getName() const;
        int getAge() const;
};

#endif
