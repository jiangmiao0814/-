#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

//给定一个大的矩阵，判断3*3矩阵里有没有“xiaomi”字符串

bool have_xiaomi(std::unordered_map<char, int>& m1)
{
	if (m1.find('x') != m1.end() && m1.find('a') != m1.end())
	{
		if (m1.find('o') != m1.end() && m1.find('m') != m1.end())
		{
			if (m1.find('i') != m1.end() && m1['i'] > 1)
			{
				return true;
				//std::cout << "--------" << std::endl;
			}
		}
	}
	else {
		return false;
	}
}
int mainfhgSg()
{
	//
	const char* str1 = "wsf";
	char str2[] = "wsf";
	char str3[] = {'a','b','c'};
	char str4[] = { "abc"};
	char* str5 = str3;
	
	std::cout << sizeof(str1) << std::endl;
	std::cout << sizeof(str2) << std::endl;
	std::cout << sizeof(str3) << std::endl;
	std::cout << sizeof(str4) << std::endl;
	std::cout << sizeof(str5) << std::endl;
	int n = 6, m =4 ;
	//std::cin >> n >> m;
	std::vector<std::string> v;
	v.emplace_back(std::string("xiao"));
	v.emplace_back(std::string("miop"));
	v.emplace_back(std::string("kjmi"));
	v.emplace_back(std::string("xiao"));
	v.emplace_back(std::string("xixh"));
	v.emplace_back(std::string("oimx"));
	/*while (n--)
	{
		std::string temp;
		std::cin >> temp;
		v.emplace_back(temp);
	}*/
	int res = 0;
	int row = 0, col = 0;
	std::unordered_map<char, int> str_map1;
	while (row <= n && col <= m)
	{
		
		int i = row + 2,j = col+2;
		
		if (i >= n)
		{
			break;
		}
		else if (j >= m)
		{
			row++;
			col = 0;
			continue;
		}
		else
		{
			
			str_map1.clear();
			for (int k = row; k <= i; k++)
			{
				for (int l = col; l <= j; l++)
				{
					str_map1[v[k][l]]++;
				}
			}
			for (auto it : str_map1)
			{
				std::cout << it.first << it.second << std::endl;
			}
			if (have_xiaomi(str_map1))
			{
				res++;
			}
			//std::cout << "--------" << std::endl;
			col++;
			continue;
		}
	}
	std::cout << res << std::endl;
	return 0;
}