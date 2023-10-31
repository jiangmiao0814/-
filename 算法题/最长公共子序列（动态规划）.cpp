#include<iostream>
#include<vector>
#include<unordered_map>


int lcs_length(std::string& s1, std::string& s2)
{
	const int m = s1.size();
	const int n = s2.size();
	std::vector<std::vector<int> > c(m + 1, std::vector<int>(n + 1, 0));  //��άvector,��¼����
	std::vector<std::vector<int> > b(m + 1, std::vector<int>(n + 1, 0));  //��άvector����¼·����Դ��1��ʾ���ϣ�2��ʾ�ϣ�3��ʾ��
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else 
			{
				c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
				if (c[i][j] == c[i - 1][j])
				{
					b[i][j] = 2;
				}
				if (c[i][j] == c[i][j-1])
				{
					b[i][j] = 3;
				}
			}
		}
	}
	int i = m, j = n;
	std::vector<char > res;
	while (i > 0 && j > 0)   //��ĩβԪ�ر���·���б��ҵ�·��
	{
		if (b[i][j] == 1)
		{
			res.push_back(s1[i - 1]);
			i--;
			j--;
		}
		else if (b[i][j] == 2)
		{
			i--;
		}
		else {
			j--;
		}
	}
	std::reverse(res.begin(), res.end());   
	for (auto it : res)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	return c[m][n];
	

}
int main�����������()
{
	std::string s1 = "abcbdab";
	std::string s2 = "bdcaba";
	std::cout << lcs_length(s1, s2);
	return 0;
}