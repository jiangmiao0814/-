#include <iostream>


int get_gys1(int num1, int num2)
{
	if (num1 == 0) return num2;
	if (num2 == 0) return num1;
	int res;
	int max_num = std::max(num1, num2);
	int min_num = std::min(num1, num2);
	int mod_num = max_num % min_num;
	res = get_gys1(min_num, mod_num);

	return res;
}
int get_gys2(int num1, int num2)
{
	if (num2 == 0) return num1;
	return get_gys2(num2, num1 % num2);
}

int get_gbs(int num1, int num2)   //两个数的最小公倍数
{
	return num1 * num2 / get_gys2(num1, num2);
}
#if 0
int main()
{
	
	std::cout << get_gbs(42, 3) << std::endl;
	return 0;
}
#endif