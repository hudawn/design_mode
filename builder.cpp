
#include <string>
#include <iostream>

using namespace std;

namespace BUI {
	//xml/json
	class IProduct {
	public:
		virtual void show() = 0;
		virtual string getname() = 0;
	};
	class productxml :public IProduct {
	public:
		void show()override {
			cout << "show xml" << endl;
		}
		string getname()override { return name; }
	private:
		string name;
	};

	class IBuilder
	{
	public:
		virtual void build1() = 0;
		virtual IProduct* getpotect() = 0;
	};
	class ConcreteBuilder : public IBuilder
	{
	public:
		ConcreteBuilder(IProduct* product) :product(product) {};
		void  build1() override { product->getname().append("build1"); }
		IProduct* getpotect() override { return product; }
	private:
		IProduct* product;
	};
	class Director
	{
	public:
		IProduct* construct(IBuilder* bui) {//传入指针唯一目的是对该对象进行构建，构建前后指针地址一直不变
			bui->build1();
			return bui->getpotect();
		}

	};

	static void test()
	{
		IProduct* product = new productxml(); //创建一个初始化的产品
		IBuilder* builder = new ConcreteBuilder(product); //创建构造器，传入产品对象地址准备构造具体产品和功能
		Director().construct(builder); //构建具体产品和功能
		product->show();
	}
}
