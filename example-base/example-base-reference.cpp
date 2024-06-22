#include "example-base-reference.h"
#include <iostream>

void runExampleBaseReference01(void) {
	//int& a = 42; //error: 因为非常量左值引用，只能绑定左值
	const int& a = 42; //ok

	int b = 42;
	int& c = b;
}