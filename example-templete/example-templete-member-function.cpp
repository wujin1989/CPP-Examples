#include "example-templete-member-function.h"
#include <iostream>

namespace ExampleTempleteMemberFunction {
	class A {	//普通类中的成员函数模板
	public:
		template <typename T>
		T calcMin(T& m, T& n);
	};

	template <typename T>
	T A::calcMin(T& m, T& n) {
		return m < n ? m : n;
	}

	template <typename T>
	class B {	//类模板中的成员函数模板
	public:
		template <typename U>
		U calcMin(U& m, U& n);
	};

	template <typename T>	//注意这里要写两个
	template <typename U>
	U B<T>::calcMin(U& m, U& n) {
		return m < n ? m : n;
	}
}

void runExampleTempleteMemberFunction01(void) {
	ExampleTempleteMemberFunction::A a;
	int m = 10;
	int n = 30;
	std::cout << a.calcMin(m, n) << std::endl;
}

