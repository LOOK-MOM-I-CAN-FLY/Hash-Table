#include "HashTable.h"

int main() {
    // Создание хэш-таблицы с начальной вместимостью 10
    HashTable table(10);

    // Вставка элементов в хэш-таблицу
    table.insert("apple", 3.14);
    table.insert("banana", 2.71);
    table.insert("orange", 1.41);

    // Попытка найти элементы
    ValueType value;
    if (table.find("apple", value)) {
        std::cout << "Found 'apple': " << value << std::endl;
    } else {
        std::cout << "'apple' not found." << std::endl;
    }

    if (table.find("banana", value)) {
        std::cout << "Found 'banana': " << value << std::endl;
    } else {
        std::cout << "'banana' not found." << std::endl;
    }

    if (table.find("grape", value)) {
        std::cout << "Found 'grape': " << value << std::endl;
    } else {
        std::cout << "'grape' not found." << std::endl;
    }

    // Удаление элемента
    table.remove("banana");

    // Попытка снова найти удаленный элемент
    if (table.find("banana", value)) {
        std::cout << "Found 'banana': " << value << std::endl;
    } else {
        std::cout << "'banana' not found." << std::endl;
    }

    // Использование оператора []
    table["cherry"] = 1.61;
    std::cout << "'cherry' set to: " << table["cherry"] << std::endl;

    // Проверка коэффициента загрузки
    std::cout << "Load factor: " << table.getLoadFactor() << std::endl;

    return 0;
}
