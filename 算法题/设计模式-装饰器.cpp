#include <iostream>

class Robot {    //被装饰的机器人抽象基类
public:
	Robot() {};
	virtual ~Robot() {};
	virtual void doBasicThing() = 0;  //纯虚函数
};

class Robot_A :public Robot  //机器人子类，实现虚方法
{
public:
	Robot_A() {};
	~Robot_A() {};
	void doBasicThing() override
	{
		std::cout << "机器人A会唱歌、跳舞！" << std::endl;
	}
};

class RobotDecorator :public Robot   //装饰器抽象基类，用来装饰机器人
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

	virtual void doMoreThing() = 0;     //纯虚函数，让子类装饰器来定义新功能
	
};

class sportDecorator :public RobotDecorator  //运动装饰器
{
public:
	sportDecorator(Robot* ptr) :RobotDecorator(ptr) {};
	void doMoreThing() override {
		std::cout << "机器人又学会了运动！" << std::endl;
	}
};

class jokeDecorator :public RobotDecorator    //讲相声装饰器
{
public:
	jokeDecorator(Robot* ptr) :RobotDecorator(ptr) {};
	void doMoreThing() override {
		std::cout << "机器人又学会了讲相声！" << std::endl;
	}
};

#if 0
int main() {

	RobotDecorator* myde = new sportDecorator(new Robot_A());  //让基类装饰器指向子类装饰器（第一次多态），传的参数是要装饰的子类指针（第二次多态）
	myde->doBasicThing(); //原先的功能
	myde->doMoreThing();  //装饰器新增的功能
	myde = new jokeDecorator(new Robot_A());  //换个装饰器
	
	myde->doMoreThing();  //新的装饰器新增的功能
	return 0;
}
#endif