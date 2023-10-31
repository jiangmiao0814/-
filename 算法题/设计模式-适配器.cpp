#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main适配器()
{


	std::vector<int> v1;
	int i = 10;
	while(i--)
	{
		v1.push_back(i);
	}
	int a = 1;
	//这是我们要给for_each的函数，但是要两个参数，不匹配
	auto func = [](int i,int j ) {std::cout << i + j << std::endl; }; 
	//这就是个适配器，把需要两个参数的函数调用转变成需要一个参数的函数，后续可以给for_each使用；
	auto new_func = std::bind(func, std::placeholders::_1, a);
	//std::placeholders::_1 参数占位符，这个位置的值是func函数的第一个参数
	std::for_each(v1.begin(), v1.end(), new_func);
	return 0;
}