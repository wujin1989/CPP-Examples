#include "example-templete-member-function.h"
#include <iostream>

namespace ExampleTempleteMemberFunction {
	class A {	//��ͨ���еĳ�Ա����ģ��
	public:
		template <typename T>
		T calcMin(T& m, T& n);
	};

	template <typename T>
	T A::calcMin(T& m, T& n) {
		return m < n ? m : n;
	}

	template <typename T>
	class B {	//��ģ���еĳ�Ա����ģ��
	public:
		template <typename U>
		U calcMin(U& m, U& n);
	};

	template <typename T>	//ע������Ҫд����
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

