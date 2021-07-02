#include "Data.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

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
    uintptr_t result = static_cast<>
}
Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}
int main() {
    Data data;
    uintptr_t ser = serialize(&data);
    std::cout << sizeof(uintptr_t);
    return 0;
}