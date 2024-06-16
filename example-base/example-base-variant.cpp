#include "example-base-variant.h"
#include <variant>
#include <string>
#include <iostream>

void runExampleBaseVariant01(void) {
	std::variant<int, std::string> v;
	std::cout << v.index() << std::endl;

	v = "hello";
	if (std::holds_alternative<std::string>(v)) {
		std::cout << std::get<1>(v) << std::endl;
	}
	std::cout << v.index() << std::endl;
}