#include "Converter.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "Wrong arguments number." << std::endl;
        return 1;
    }
    Converter convert(av[1]);
    convert.display();
    return 0;
}