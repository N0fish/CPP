#include <iostream>
#include <string>

// Объявление класса Person
class Person 
{
    // Приватные данные (доступны только внутри класса)
    private:
        std::string name;
        int age;

    // Публичные методы и конструкторы (доступны извне)
    public:
        // Конструктор по умолчанию
        Person() : name("Неизвестно"), age(0) {
            std::cout << "Конструктор по умолчанию вызван!" << std::endl;
        }

        // Конструктор с параметрами
        Person(const std::string& name, int age) : name(name), age(age) {
            std::cout << "Конструктор с параметрами вызван!" << std::endl;
        }

        // Деструктор
        ~Person() {
            std::cout << "Деструктор вызван! Объект " << name << " удалён." << std::endl;
        }

        // Метод для вывода информации о человеке
        void introduce() const {
            std::cout << "Привет! Меня зовут " << name << ", мне " << age << " лет." << std::endl;
        }

        // Сеттеры (методы для изменения значений)
        void setName(const std::string& newName) {
            name = newName;
        }

        void setAge(int newAge) {
            age = newAge;
        }

        // Геттеры (методы для получения значений)
        std::string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }
};

int main() {
    // Создание объекта с использованием конструктора по умолчанию
    Person person1;
    person1.introduce();  // Выводит: Привет! Меня зовут Неизвестно, мне 0 лет.

    // Изменяем имя и возраст с помощью сеттеров
    person1.setName("Алексей");
    person1.setAge(25);
    person1.introduce();  // Выводит: Привет! Меня зовут Алексей, мне 25 лет.

    // Создание объекта с использованием конструктора с параметрами
    Person person2("Мария", 30);
    person2.introduce();  // Выводит: Привет! Меня зовут Мария, мне 30 лет.

    return 0;
}
