#include "Data.hpp"
#include <iostream>

/*          ВАРИАНТ 1
uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
*/

//          ВАРИАНТ 2
uintptr_t serialize(Data* ptr) {
    ptr->_int = 10;
    ptr->_str1 = "string1";
    ptr->_str2 = "string2";
    void* result = reinterpret_cast<void *>(ptr);
    return reinterpret_cast<uintptr_t>(result);
}
Data* deserialize(uintptr_t raw) {
    Data* res = new Data;
    void* obj = reinterpret_cast<void *>(raw);
    res->_int = *(reinterpret_cast<int *>(obj));
    res->_str1 = std::string(reinterpret_cast<char *>(obj) + 9, 7);
    res->_str2 = std::string(reinterpret_cast<char *>(obj) + 33, 7);

    return res;
}

int main() {
    Data data;
    uintptr_t ser = serialize(&data);
    std::cout << "\nSerialized value = " << ser << std::endl;
    std::cout << "Initial data:" << std::endl;
    std::cout << data._int << std::endl;
    std::cout << data._str1 << std::endl;
    std::cout << data._str2 << std::endl << std::endl;
    Data* sameData = deserialize(ser);
    std::cout << "Size of Data = " << sizeof(data) 
    << "\nSize of int = " << sizeof(data._int)
    << "\nSize of Str1 = " << sizeof(data._str1)
    << "\nSize of Str2 = " << sizeof(data._str2)
    << "\nSize of uintptr = " << sizeof(uintptr_t)
    << "\n\nResult data:" << std::endl;
    std::cout << sameData->_int << std::endl;
    std::cout << sameData->_str1 << std::endl;
    std::cout << sameData->_str2 << std::endl;
    return 0;
}