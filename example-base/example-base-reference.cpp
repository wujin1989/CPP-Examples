#include "example-base-reference.h"
#include <iostream>
#include <utility>

namespace ExampleBaseReference {
	template <typename F, typename T, typename U>
	static void funcTemplate01(F f, T&& t, U&& u) {
		f(t, u);
	}
	template <typename F, typename T, typename U>
	static void funcTemplate02(F f, T&& t, U&& u) {
		f(std::forward<T>(t), u);	//完美转发，需要配合万能引用使用
	}
	static void func01(int i, int& j) {
		i += 10;
		j += 10;
		std::cout << "i: " << i << ", j: " << j << std::endl;
	}
	static void func02(int&& i, int& j) {
		i += 10;
		j += 10;
		std::cout << "i: " << i << ", j: " << j << std::endl;
	}
}

void runExampleBaseReference01(void) {
	//int& a = 42; //error: 因为非常量左值引用，只能绑定左值
	const int& a = 42; //ok

	int b = 42;
	int& c = b;
}

void runExampleBaseReference02(void) {
	//完美转发
	int j = 100;
	ExampleBaseReference::funcTemplate01(ExampleBaseReference::func01, 20, j);
	//无法将参数 1 从“T”转换为“int &&
	/*ExampleBaseReference::funcTemplate01(ExampleBaseReference::func02, 20, j);*/
	ExampleBaseReference::funcTemplate02(ExampleBaseReference::func02, 20, j);
}