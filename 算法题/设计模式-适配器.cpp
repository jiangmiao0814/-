#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main������()
{


	std::vector<int> v1;
	int i = 10;
	while(i--)
	{
		v1.push_back(i);
	}
	int a = 1;
	//��������Ҫ��for_each�ĺ���������Ҫ������������ƥ��
	auto func = [](int i,int j ) {std::cout << i + j << std::endl; }; 
	//����Ǹ�������������Ҫ���������ĺ�������ת�����Ҫһ�������ĺ������������Ը�for_eachʹ�ã�
	auto new_func = std::bind(func, std::placeholders::_1, a);
	//std::placeholders::_1 ����ռλ�������λ�õ�ֵ��func�����ĵ�һ������
	std::for_each(v1.begin(), v1.end(), new_func);
	return 0;
}