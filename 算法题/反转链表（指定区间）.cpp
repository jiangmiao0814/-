#include <iostream>

struct node {
	node *next;
	int val;
	node(){ next = nullptr; }
	node(int a) :val(a) { next = nullptr; }
};

#if 0
int main()
{
	node* n1 = new node(1);
	node* n2 = new node(2);
	node* n3 = new node(3);
	node* n4 = new node(4);
	node* n5 = new node(5);
	node* n6 = new node(6);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = nullptr;
	
	
	node* pre = nullptr;
	//pre->next = n1;
	node* cur = n1;
	node* afterone = cur->next;
	while (afterone != nullptr)
	{
		
		cur->next = pre;
		pre = cur;
		cur = afterone;
		afterone = afterone->next;

	}
	cur->next = pre;
	node* ptr = n6;
	while (ptr != nullptr)
	{
		std::cout << ptr->val << std::endl;
		ptr = ptr->next;
	}
	return 0;
}
#endif