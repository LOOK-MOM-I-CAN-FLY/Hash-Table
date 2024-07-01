#include "HashTable.h"

/// @brief Конструктор
/// @param size размер нашей таблицы
HashTable::HashTable(size_t size) : _capacity(size), _filled(0), table(size) {}

/// @brief Деструктор
HashTable::~HashTable() {}

/// @brief тупая Хэш-функция реализуемая методом деления (чепуха). Хочу сделать хэш-функцию типо sha256 от биткоина только хз как 
/// @param key 
/// @return Хэш делённый на вместимость нашей таблицы
size_t HashTable::hash_function(const KeyType &key) const {
    size_t hash = 0;
    for(char ch : key) {
        hash += static_cast<size_t>(ch);
    }
    return hash % _capacity;
}

/// @brief функция для поиска элемента в Хэш-таблице
/// @param key 
/// @param value 
/// @return true or false в зависимости от того найден ключ или нет
bool HashTable::find(const KeyType &key, ValueType &value) const {
    size_t index = hash_function(key);
    for(const auto &entry : table[index]) {
        if(entry.first == key) {
            value = entry.second;
            return true;
        }
    }
    return false;
}

/// @brief Получение коэффициента загрузки
/// @return коэффициент загрузки
double HashTable::getLoadFactor() {
    return static_cast<double>(_filled) / _capacity;
}

/// @brief Оператор доступа к элементу по ключу
/// @param key 
/// @return значение по ключу
ValueType &HashTable::operator[](const KeyType &key) {
    // Вычисляем хэш-значение для ключа и определяем индекс в таблице
    size_t index = hash_function(key);
    // Ищем пару ключ-значение в соответствующей цепочке (списке)
    for(auto &pair : table[index]) {
        if(pair.first == key) {
            // Если нашли ключ, возвращаем ссылку на значение
            return pair.second;
        }
    }
    // Если ключ не найден, добавляем новую пару ключ-значение в цепочку
    table[index].emplace_back(key, ValueType{});
    ++_filled;  // Увеличиваем количество занятых ячеек
    // Проверяем коэффициент загрузки и при необходимости перераспределяем таблицу
    if(getLoadFactor() > 0.75) {
        rehash();
    }
    // Возвращаем ссылку на новое значение
    return table[index].back().second;
}

/// @brief Увеличение размера таблицы и перераспределение элементов
void HashTable::rehash() {
    size_t old_capacity = _capacity;
    _capacity *= 2;
    std::vector<std::list<std::pair<KeyType, ValueType>>> newTable(_capacity);
    for(const auto &chain : table) {
        for(const auto &pair : chain) {
            size_t new_index = hash_function(pair.first);
            newTable[new_index].emplace_back(pair);
        }
    }
    table = std::move(newTable);
}

/// @brief Вставка элемента в хеш-таблицу
/// @param key 
/// @param value 
void HashTable::insert(const KeyType &key, const ValueType &value) {
    size_t index = hash_function(key);
    for(auto &pair : table[index]) {
        if(pair.first == key) {
            pair.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
    ++_filled;
    if(getLoadFactor() > 0.75) {
        rehash();
    }
}

/// @brief удаление элемента по ключу
/// @param key 
void HashTable::remove(const KeyType &key) {
    // Получаем хэш-значение для ключа и определяем индекс в таблице
    size_t index = hash_function(key);
    // Получаем ссылку на цепочку (список) по этому индексу
    auto &chain = table[index];
    // Проходимся по всем элементам в цепочке
    for(auto it = chain.begin(); it != chain.end(); ++it) {
        // Если найден элемент с соответствующим ключом
        if(it->first == key) {
            // Удаляем элемент из цепочки
            chain.erase(it);
            // Уменьшаем счётчик заполненных ячеек
            --_filled;
            // Прерываем выполнение функции, так как элемент удалён
            return;
        }
    }
}
