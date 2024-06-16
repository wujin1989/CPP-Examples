#include "example-templete-function.h"
#include <iostream>

template <typename T>
static T calcMin(T& a, T& b) {
	return a < b ? a : b;
}

void runExampleTempleteFunction01(void) {
	int a = 5;
	int b = 2;
	int ret = calcMin<int>(a, b);	//��ʾָ��ģ�����
	std::cout << ret << std::endl;

	double c = 1.0;
	double d = 4.0;
	int ret2 = calcMin(c, d);	//�������Զ��Ƶ�ģ�����
	std::cout << ret2 << std::endl;
}