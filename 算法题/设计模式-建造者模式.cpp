#include <iostream>

class Computer {      //要建造的产品类，有几个组成部分
private:		//其实这里可以用抽象产品类，为了省事直接定义了具体的
	std::string m_cpu;  //cpu
	std::string m_momery;  //内存
	std::string m_screen;  //屏幕
public:
	Computer(std::string cpu, std::string momery, std::string screen):m_cpu(cpu), m_momery(momery), m_screen(screen) {};
	Computer() {};
	~Computer() {};
	void set_m_cpu(std::string cpu)
	{
		this->m_cpu = cpu;
	}
	void set_m_momery(std::string momery)
	{
		this->m_momery = momery;
	}
	void set_m_screen(std::string screen)
	{
		this->m_screen = screen;
	}
	void show(){
		std::cout << "电脑配置如下：" << std::endl;
		std::cout << "cpu：" << this->m_cpu << std::endl;
		std::cout << "内存：" << this->m_momery << std::endl;
		std::cout << "屏幕：" << this->m_screen << std::endl;
	}
};
class AbstractBuilder {        //建造者 的 抽象基类
protected: 
	Computer* m_computer;   //包含要建造的对象（最好是抽象类的指针，这里是具体类）
public:
	AbstractBuilder(Computer* ptr) :m_computer(ptr) {}; //f构造函数中初始化要建造的产品是啥
	
	//具体的建造实现交给子类
	virtual void builde_cpu(std::string cpu) = 0;
	virtual void builde_momery(std::string momery) = 0;
	virtual void builde_screen(std::string screen) = 0;

	Computer* get_producer()
	{
		return m_computer;
	}
	~AbstractBuilder() {
		delete m_computer;
	}
};

class Builder_A :public AbstractBuilder   //具体的建造者，实现了各个电脑部件的建造细节
{
public:
	Builder_A(Computer* ptr) :AbstractBuilder(ptr) {};
	void builde_cpu(std::string cpu) override {
		this->m_computer->set_m_cpu(cpu);
	 };
	void builde_momery(std::string momery)override {
		this->m_computer->set_m_momery(momery);
	 };
	void builde_screen(std::string screen)override {
		this->m_computer->set_m_screen(screen);

	 };
};

//指挥者类，决定如何建造，确定实现细节
class Director {
private:
	AbstractBuilder* m_builder;  //要包含具体的建造者（这里用抽象指针）
public:
	Director(AbstractBuilder* builder) :m_builder(builder) {}; //传递参数要传具体的子类指针
	~Director() {
		delete m_builder;
	}
	Computer* createComputer(std::string cpu, std::string momery, std::string screen)
	{
		//确定构建细节
		m_builder->builde_cpu(cpu);
		m_builder->builde_momery(momery);
		m_builder->builde_screen(screen);
		return m_builder->get_producer();
	}
};
#if 0
int main()
{
	AbstractBuilder* pb = new Builder_A(new Computer()); //创建具体的建造者
	Director* pd = new Director(pb);  //创建指挥者
	Computer* newComputer = pd->createComputer("32核", "24G", "4K"); 
	newComputer->show();
}
#endif

