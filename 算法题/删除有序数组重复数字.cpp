#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

std::vector<int> remove_num(std::vector<int>& v)
{
	std::vector<int> res;
	if (v.empty()) return res;
	res.push_back(v[0]);
	int i = 1, j = 0;
	while (i < v.size())
	{
		if (v[i] != res[j])
		{
			res.push_back(v[i++]);
			j++;
		}
		else {
			i++;
		}
	}
	return res;
}

int mainsdaddf()
{
	std::string sss;
	getline(std::cin, sss);
	std::vector<int> v1 = { 1,1,1,1,2,2,2,3,3,4,4,5,6,6,7,7 };
	std::vector<int> res = remove_num(v1);
	for (auto it : res)
	{
		std::cout << it << " ";
	}
	
	return 0;
}
