#include "example-base-reference.h"
#include <iostream>

void runExampleBaseReference01(void) {
	//int& a = 42; //error: ��Ϊ�ǳ�����ֵ���ã�ֻ�ܰ���ֵ
	const int& a = 42; //ok

	int b = 42;
	int& c = b;
}