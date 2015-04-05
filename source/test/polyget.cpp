/**
 *
 */
#include <iostream>

#include "utils/Any.hpp"

struct Base {
    Base(int val) : value(val) {}
    virtual ~Base() {}
    virtual void foo() = 0;
    int value;
};

class Derived : public virtual Base {
public:
    Derived() : Base(5) {}
    void foo() override {
        ::std::cout << "Hello from Derived";
    }
};

::std::ostream& operator<<(::std::ostream& stream, const Base& base)
{
    return stream << base.value;
}

int main() {

    util::Any a;
    a = Derived{};


    //.........

    ::std::cout << a.typeinfo().name() << std::endl;
    ::std::cout << a.poly_get<Base>() << std::endl;
    a.poly_get<Base>().foo();
    return 0;
}
