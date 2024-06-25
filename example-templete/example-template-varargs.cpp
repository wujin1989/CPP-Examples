#include "example-template-varargs.h"
#include <iostream>

namespace ExampleTemplateVarArgs {
	void print(){} //这个重载函数作用是处理最后情况的

	template <typename HEAD, typename... TAIL>
	void print(const HEAD& first, const TAIL&... args) {
		std::cout << first << " " << sizeof...(args) << std::endl; //注意sizeof...()是返回可变参数个数
		print(args...);
	}
}

void runExampleTemplateVarArgs01(void) {
	ExampleTemplateVarArgs::print(1,"hello", 2);
}