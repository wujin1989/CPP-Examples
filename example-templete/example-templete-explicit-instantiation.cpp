#include "example-templete-explicit-instantiation.h"
#include <iostream>

template <typename T>
T calcMin(T& m, T& n) {
	return m < n ? m : n;
}

template int calcMin<int>(int& m, int& n);	//模板的显示实例化

void runExampleTempleteExplicitInstantiation01(void) {
	int a = 10;
	int b = 30;
	
	std::cout << calcMin<int>(a, b) << std::endl;
}

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

void runExampleTempleteExplicitInstantiation02(void) {
	A<int> a(20);
}