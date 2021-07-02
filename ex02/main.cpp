#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base * generate(void) {
    int random = rand() % 3;
    if (random == 0)
        return reinterpret_cast<Base *>(new A());
    if (random == 1)
        return reinterpret_cast<Base *>(new B());
    return reinterpret_cast<Base *>(new C());
}

void    identify(Base* p) {
    if (dynamic_cast<A *>(p) != 0)
        std::cout << "type is A" << std::endl;
    else if (dynamic_cast<B *>(p) != 0)
        std::cout << "type is B" << std::endl;
    else if (dynamic_cast<C *>(p) != 0)
        std::cout << "type is C" << std::endl;
}

void    identify(Base& p) {
    if (dynamic_cast<A *>(&p) != 0)
        std::cout << "type is A" << std::endl;
    else if (dynamic_cast<B *>(&p) != 0)
        std::cout << "type is B" << std::endl;
    else if (dynamic_cast<C *>(&p) != 0)
        std::cout << "type is C" << std::endl;
}

void    identify2(Base& p) {
    try {
        A& ref = dynamic_cast<A&>(p);
        std::cout << "type is A" << std::endl;
        static_cast<void>(ref);
    }
    catch(std::bad_cast &e) {}
    try {
        B& ref = dynamic_cast<B&>(p);
        std::cout << "type is B" << std::endl;
        static_cast<void>(ref);
    }
    catch(std::bad_cast &e) {}
    try {
        C& ref = dynamic_cast<C&>(p);
        std::cout << "type is C" << std::endl;
        static_cast<void>(ref);
    }
    catch(std::bad_cast &e) {}
}

int main() {
    srand(time(0));
    Base*  var1 = generate();
    Base*  var2 = generate();
    Base*  var3 = generate();

    std::cout << "Pointers :" << std::endl;
    identify(var1);
    identify(var2);
    identify(var3);

    std::cout << "References :" << std::endl;
    identify(*var1);
    identify(*var2);
    identify(*var3);

    std::cout << "References2 :" << std::endl;
    identify2(*var1);
    identify2(*var2);
    identify2(*var3);

    return 0;
}