#include <iostream>

class A {

public:
	
	A(int b,int &d ):m_b(b),m_d(d){}
	~A() {}
	A(const A& a):m_b(a.m_b), m_d(a.m_d) {
		m_a = a.m_a;
		m_c = a.m_c;
	}
	A& operator=(const A& a)
	{
		if (this != &a)
		{
			this->m_a = a.m_a;
			this->m_c = a.m_c;
			this->m_d = a.m_d;
		}
		return *this;
	}
	
public:
	int m_a;
	const int m_b;
	static int m_c;
	int& m_d;
};
//int A::m_c = 2;
#if 0
int main()
{
	int num = 9;
	int& num2 = num;
	int numb = 3;

	A a1(1, num);
	std::cout << a1.m_a << " " << a1.m_b << " " << a1.m_c << " " << a1.m_d << std::endl;
	A a2(2, num);
	std::cout << a2.m_a << " " << a2.m_b << " " << a2.m_c << " " << a2.m_d << std::endl;
	A a3(a1);
	std::cout << a3.m_a << " " << a3.m_b << " " << a3.m_c << " " << a3.m_d << std::endl;
	a3 = a2;
	std::cout << a3.m_a << " " << a3.m_b << " " << a3.m_c << " " << a3.m_d << std::endl;
	return 0;
}
#endif