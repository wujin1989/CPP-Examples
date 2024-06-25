#include "example-template-varargs.h"
#include <iostream>

namespace ExampleTemplateVarArgs {
	void print(){} //������غ��������Ǵ�����������

	template <typename HEAD, typename... TAIL>
	void print(const HEAD& first, const TAIL&... args) {
		std::cout << first << " " << sizeof...(args) << std::endl; //ע��sizeof...()�Ƿ��ؿɱ��������
		print(args...);
	}
}

void runExampleTemplateVarArgs01(void) {
	ExampleTemplateVarArgs::print(1,"hello", 2);
}