/**
 *
 */
#include <iostream>

#include "utils/Any.hpp"

int main() {

	util::Any a;
	a = 5ul;

	::std::cout << a.typeinfo().name() << std::endl;
	::std::cout << a.get<unsigned long>() << std::endl;
}
