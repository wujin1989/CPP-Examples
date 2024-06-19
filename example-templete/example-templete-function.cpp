#include "example-templete-function.h"
#include <iostream>

namespace ExampleTempleteFunction {
	template <typename T>
	static T calcMin(T& a, T& b) {
		return a < b ? a : b;
	}
}

void runExampleTempleteFunction01(void) {
	int a = 5;
	int b = 2;
	int ret = ExampleTempleteFunction::calcMin<int>(a, b);	//显示指定模板参数
	std::cout << ret << std::endl;

	double c = 1.0;
	double d = 4.0;
	int ret2 = ExampleTempleteFunction::calcMin(c, d);	//编译器自动推导模板参数
	std::cout << ret2 << std::endl;
}