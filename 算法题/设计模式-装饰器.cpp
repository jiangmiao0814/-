#include <iostream>

class Robot {    //��װ�εĻ����˳������
public:
	Robot() {};
	virtual ~Robot() {};
	virtual void doBasicThing() = 0;  //���麯��
};

class Robot_A :public Robot  //���������࣬ʵ���鷽��
{
public:
	Robot_A() {};
	~Robot_A() {};
	void doBasicThing() override
	{
		std::cout << "������A�ᳪ�衢���裡" << std::endl;
	}
};

class RobotDecorator :public Robot   //װ����������࣬����װ�λ�����
{
private:
	Robot* myRobot;
public:
	RobotDecorator(Robot* ptr) :myRobot(ptr) {};
	virtual ~RobotDecorator() {
		delete myRobot;
	}
	void doBasicThing() override
	{
		myRobot->doBasicThing();
	}

	virtual void doMoreThing() = 0;     //���麯����������װ�����������¹���
	
};

class sportDecorator :public RobotDecorator  //�˶�װ����
{
public:
	sportDecorator(Robot* ptr) :RobotDecorator(ptr) {};
	void doMoreThing() override {
		std::cout << "��������ѧ�����˶���" << std::endl;
	}
};

class jokeDecorator :public RobotDecorator    //������װ����
{
public:
	jokeDecorator(Robot* ptr) :RobotDecorator(ptr) {};
	void doMoreThing() override {
		std::cout << "��������ѧ���˽�������" << std::endl;
	}
};

#if 0
int main() {

	RobotDecorator* myde = new sportDecorator(new Robot_A());  //�û���װ����ָ������װ��������һ�ζ�̬�������Ĳ�����Ҫװ�ε�����ָ�루�ڶ��ζ�̬��
	myde->doBasicThing(); //ԭ�ȵĹ���
	myde->doMoreThing();  //װ���������Ĺ���
	myde = new jokeDecorator(new Robot_A());  //����װ����
	
	myde->doMoreThing();  //�µ�װ���������Ĺ���
	return 0;
}
#endif