#include "Data.hpp"

Data::Data() {
    _int = 10;
    _str1 = "string1";
    _str2 = "strin2";
}

Data::~Data() {}

int Data::getInt() const {
    return _int;
}

const std::string&    Data::getString1() const {
    return _str1;
}

const std::string&    Data::getString2() const {
    return _str2;
}