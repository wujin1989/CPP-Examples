#include "example-templete-explicit-instantiation.h"
#include <iostream>

namespace ExampleTempleteExplicitInstantiation {
	template <typename T>
	T calcMin(T& m, T& n) {
		return m < n ? m : n;
	}

	template int calcMin<int>(int& m, int& n);	//模板的显示实例化


	template <typename T>
	class A {
	public:
		A(T t) {
			data = t;
		}
	private:
		T data;
	};

	template class A<int>;
}
void runExampleTempleteExplicitInstantiation01(void) {
	int a = 10;
	int b = 30;
	
	std::cout << ExampleTempleteExplicitInstantiation::calcMin<int>(a, b) << std::endl;
}

void runExampleTempleteExplicitInstantiation02(void) {
	ExampleTempleteExplicitInstantiation::A<int> a(20);
}