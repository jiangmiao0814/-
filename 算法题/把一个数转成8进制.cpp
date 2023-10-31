#include <iostream>
#include <string>
#include <algorithm>
#include <map>


int bit10Tobit2(int num)
{
	std::map<int, char> m1;
	m1.insert(std::make_pair<int, char>(0, '0'));
	m1.insert(std::make_pair<int, char>(1, '1'));
	std::string res = {};
	while (num != 0)
	{
		res.push_back(m1[num % 2]);
		num /= 2;
	}
	std::reverse(res.begin(),res.end());
	return std::stoi(res);
}
#if 0
int main()
{
	int num = 16;
	int res = bit10Tobit2(num);
	std::cout << res << std::endl;
	return 0;
}
#endif