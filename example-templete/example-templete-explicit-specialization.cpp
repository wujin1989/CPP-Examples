#include "example-templete-explicit-specialization.h"
#include <iostream>

namespace ExampleTempleteExplicitSpecialization {
	template <typename T>
	class A {
	public:
		A(T& t) : mData(t) {
			std::cout << "通用模板构造" << std::endl;
		}
	private:
		T mData;
	};

	template <>			//这个表示模板显示专用化（也叫全特化）
	class A<int> {
	public:
		A(int& t) : mData(t) {
			std::cout << "专用化模板构造" << std::endl;
		}
	private:
		int mData;
	};
	template <typename T>
	T calcMin(T& m, T& n) {
		std::cout << "通用模板" << std::endl;
		return m < n ? m : n;
	}

	template <>
	float calcMin<float>(float& m, float& n) {	//函数模板的全特化，函数模板没有偏特化
		std::cout << "特化模板" << std::endl;
		return m < n ? m : n;
	}
}

void runExampleTempleteExplicitSpecialization01(void) {
	int n = 30;
	ExampleTempleteExplicitSpecialization::A<int> a(n);

	float m = 30.0;
	ExampleTempleteExplicitSpecialization::A<float> b(m);
}

void runExampleTempleteExplicitSpecialization02(void) {
	float m = 10.0;
	float n = 20.0;
	ExampleTempleteExplicitSpecialization::calcMin<float>(m, n);
}