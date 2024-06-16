#include "example-base-lambda.h"
#include <vector>
#include <iostream>

void runExampleBaseLambda01(void) {
	std::vector<int> vec = { 1, 3, 5, 2, 4 };
	int x = 2;
	int y = 4;
	auto ret = std::find_if(vec.begin(), vec.end(), [=](int i) {
		return i > x && i < y;
	});
	std::cout << *ret << std::endl;
}

void runExampleBaseLambda02(void) {
	std::vector<int> vec = { 1, 3, 5, 2, 4 };
	int x = 2;
	int y = 4;
	auto ret = std::find_if(vec.begin(), vec.end(), [&](int i) {
		x = 1;
		y = 3;
		return i > x && i < y;
	});
	std::cout << *ret << std::endl;
}