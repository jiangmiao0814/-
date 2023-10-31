#include <iostream>

class Computer {      //Ҫ����Ĳ�Ʒ�࣬�м�����ɲ���
private:		//��ʵ��������ó����Ʒ�࣬Ϊ��ʡ��ֱ�Ӷ����˾����
	std::string m_cpu;  //cpu
	std::string m_momery;  //�ڴ�
	std::string m_screen;  //��Ļ
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
		std::cout << "�����������£�" << std::endl;
		std::cout << "cpu��" << this->m_cpu << std::endl;
		std::cout << "�ڴ棺" << this->m_momery << std::endl;
		std::cout << "��Ļ��" << this->m_screen << std::endl;
	}
};
class AbstractBuilder {        //������ �� �������
protected: 
	Computer* m_computer;   //����Ҫ����Ķ�������ǳ������ָ�룬�����Ǿ����ࣩ
public:
	AbstractBuilder(Computer* ptr) :m_computer(ptr) {}; //f���캯���г�ʼ��Ҫ����Ĳ�Ʒ��ɶ
	
	//����Ľ���ʵ�ֽ�������
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

class Builder_A :public AbstractBuilder   //����Ľ����ߣ�ʵ���˸������Բ����Ľ���ϸ��
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

//ָ�����࣬������ν��죬ȷ��ʵ��ϸ��
class Director {
private:
	AbstractBuilder* m_builder;  //Ҫ��������Ľ����ߣ������ó���ָ�룩
public:
	Director(AbstractBuilder* builder) :m_builder(builder) {}; //���ݲ���Ҫ�����������ָ��
	~Director() {
		delete m_builder;
	}
	Computer* createComputer(std::string cpu, std::string momery, std::string screen)
	{
		//ȷ������ϸ��
		m_builder->builde_cpu(cpu);
		m_builder->builde_momery(momery);
		m_builder->builde_screen(screen);
		return m_builder->get_producer();
	}
};
#if 0
int main()
{
	AbstractBuilder* pb = new Builder_A(new Computer()); //��������Ľ�����
	Director* pd = new Director(pb);  //����ָ����
	Computer* newComputer = pd->createComputer("32��", "24G", "4K"); 
	newComputer->show();
}
#endif

