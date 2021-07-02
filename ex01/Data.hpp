#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
# include <string>

struct Data {
private:
    int _int;
    std::string _str1;
    std::string _str2;
public:
    Data();
    ~Data();
    int getInt() const;
    const std::string&    getString1() const;
    const std::string&    getString2() const;
};
#endif