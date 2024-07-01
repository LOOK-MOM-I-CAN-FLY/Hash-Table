#include "HashTable.h"

int main() {
    HashTable hashTable(5);

    // Вставка элементов
    hashTable.insert("apple", 1.0);
    hashTable.insert("banana", 2.0);
    hashTable.insert("orange", 3.0);
    hashTable.insert("grape", 4.0);
    hashTable.insert("melon", 5.0);
    hashTable.insert("lemon", 6.0);
    hashTable.insert("lime", 7.0);
    hashTable.insert("cherry", 8.0);
    hashTable.insert("berry", 9.0);
    hashTable.insert("mango", 10.0);

    // Проверка коллизий и их решение
    std::cout << "Value for 'apple': " << hashTable["apple"] << std::endl;
    std::cout << "Value for 'banana': " << hashTable["banana"] << std::endl;
    std::cout << "Value for 'orange': " << hashTable["orange"] << std::endl;
    std::cout << "Value for 'grape': " << hashTable["grape"] << std::endl;
    std::cout << "Value for 'melon': " << hashTable["melon"] << std::endl;
    std::cout << "Value for 'lemon': " << hashTable["lemon"] << std::endl;
    std::cout << "Value for 'lime': " << hashTable["lime"] << std::endl;
    std::cout << "Value for 'cherry': " << hashTable["cherry"] << std::endl;
    std::cout << "Value for 'berry': " << hashTable["berry"] << std::endl;
    std::cout << "Value for 'mango': " << hashTable["mango"] << std::endl;

    // Проверка изменения значений
    hashTable["apple"] = 1.1;
    hashTable["banana"] = 2.2;
    std::cout << "Updated value for 'apple': " << hashTable["apple"] << std::endl;
    std::cout << "Updated value for 'banana': " << hashTable["banana"] << std::endl;

    // Проверка коэффициента загрузки
    std::cout << "Load Factor: " << hashTable.getLoadFactor() << std::endl;

    // Проверка удаления
    hashTable.remove("apple");
    hashTable.remove("banana");

    ValueType value;
    if (hashTable.find("apple", value)) {
        std::cout << "Found 'apple' with value: " << value << std::endl;
    } else {
        std::cout << "'apple' not found" << std::endl;
    }

    if (hashTable.find("banana", value)) {
        std::cout << "Found 'banana' with value: " << value << std::endl;
    } else {
        std::cout << "'banana' not found" << std::endl;
    }

    return 0;
}