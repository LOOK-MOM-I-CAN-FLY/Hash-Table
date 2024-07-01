#include "HashTable.h"

int main() {
    // Создание хэш-таблицы с начальной вместимостью 5 для большей вероятности коллизий
    HashTable hashTable(5);

    // Вставка элементов в хэш-таблицу
    // Эти ключи намеренно подобраны так, чтобы вызвать коллизии при использовании простой хэш-функции
    hashTable.insert("cat", 3.14);
    hashTable.insert("tac", 2.71); // 'cat' и 'tac' должны вызвать коллизию, так как они могут иметь одинаковый хэш
    hashTable.insert("act", 1.41); // 'cat', 'tac' и 'act' могут иметь одинаковый хэш

    // Попытка найти элементы
    ValueType value;
    if (hashTable.find("cat", value)) {
        std::cout << "Found 'cat': " << value << std::endl;
    } else {
        std::cout << "'cat' not found." << std::endl;
    }

    if (hashTable.find("tac", value)) {
        std::cout << "Found 'tac': " << value << std::endl;
    } else {
        std::cout << "'tac' not found." << std::endl;
    }

    if (hashTable.find("act", value)) {
        std::cout << "Found 'act': " << value << std::endl;
    } else {
        std::cout << "'act' not found." << std::endl;
    }

    // Печать коэффициента загрузки
    std::cout << "Load factor: " << hashTable.getLoadFactor() << std::endl;

    // Использование оператора []
    hashTable["dog"] = 1.61;
    std::cout << "'dog' set to: " << hashTable["dog"] << std::endl;

    // Удаление элемента
    hashTable.remove("tac");

    // Попытка снова найти удаленный элемент
    if (hashTable.find("tac", value)) {
        std::cout << "Found 'tac': " << value << std::endl;
    } else {
        std::cout << "'tac' not found." << std::endl;
    }

    // Попытка снова найти элементы после удаления
    if (hashTable.find("cat", value)) {
        std::cout << "Found 'cat': " << value << std::endl;
    } else {
        std::cout << "'cat' not found." << std::endl;
    }

    if (hashTable.find("act", value)) {
        std::cout << "Found 'act': " << value << std::endl;
    } else {
        std::cout << "'act' not found." << std::endl;
    }
    // Печать коэффициента загрузки
    std::cout << "Load factor: " << hashTable.getLoadFactor() << std::endl;

    return 0;
}