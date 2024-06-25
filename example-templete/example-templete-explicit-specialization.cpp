#include "example-templete-explicit-specialization.h"
#include <iostream>

namespace ExampleTempleteExplicitSpecialization {
	template <typename T>
	class A {
	public:
		A(T& t) : mData(t) {
			std::cout << "ͨ��ģ�幹��" << std::endl;
		}
	private:
		T mData;
	};

	template <>			//�����ʾģ����ʾר�û���Ҳ��ȫ�ػ���
	class A<int> {
	public:
		A(int& t) : mData(t) {
			std::cout << "ר�û�ģ�幹��" << std::endl;
		}
	private:
		int mData;
	};
	template <typename T>
	T calcMin(T& m, T& n) {
		std::cout << "ͨ��ģ��" << std::endl;
		return m < n ? m : n;
	}
	//��ʾ�ػ���ָΪ����ģ���ṩһ�������ʵ�֣������ض���ģ�������
	//��ʾ�ػ�ͨ�������ṩ����ض����͵ĸ�Чʵ�ֻ��ض�����Ϊ
	template <>
	float calcMin<float>(float& m, float& n) {	//����ģ���ȫ�ػ�������ģ��û��ƫ�ػ�
		std::cout << "�ػ�ģ��" << std::endl;
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