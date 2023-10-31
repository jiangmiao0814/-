#include <iostream>
#include <vector>

void quick_sork_1(std::vector<int>& v, int left, int right)
{
	if (left >= right) return;
	int temp = v[left];
	int begin = left, end = right;
	while (left < right)
	{
		while (left < right && v[right]>temp)
		{
			right--;
		}
		if(left < right)v[left++] = v[right];
		while (left < right && v[left]<temp)
		{
			left++;
		}
		if (left < right)v[right--] = v[left];
	}

	int mid = left;
	v[left] = temp;
	quick_sork_1(v, begin, mid - 1);
	quick_sork_1(v, mid + 1, end);
	
}
#if 0
int main()
{
	std::vector<int> v1 = { 3,5,16,8,34,27,1,7,9 };
	int left = 0;
	int right = v1.size() - 1;
	quick_sork_1(v1, left, right);
	for (auto it : v1)
	{
		std::cout << it << std::endl;
	}
	return 0;
}
#endif