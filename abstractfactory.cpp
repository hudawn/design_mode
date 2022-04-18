#include <string>
#include <iostream>


using namespace std;
namespace ABS {
	class AbstractRealCar
	{
	public:
		virtual void run() = 0;
	};
	class AbstractToyCar
	{
	public:
		virtual void run() = 0;
	};

	class RealBwm :public  AbstractRealCar
	{
	public:
		void run()override { cout << "real bmn run" << endl; }
	};
	class RealBenz :public  AbstractRealCar
	{
	public:
		void run()override { cout << "real benz run" << endl; }
	};

	class ToyBwm :public  AbstractToyCar
	{
	public:
		void run()override { cout << "toy bmn run" << endl; }
	};

	class ToyBenz :public  AbstractToyCar
	{
	public:
		void run()override { cout << "toy benz run" << endl; }
	};

	class AbustractFactory
	{
	public:
		virtual AbstractRealCar* createRealCar() = 0;
		virtual AbstractToyCar* createToyCar() = 0;
	};

	class BwmFactory : public AbustractFactory
	{
	public:
		AbstractRealCar* createRealCar() override {
			return new RealBwm();
		};
		AbstractToyCar* createToyCar() override {
			return new ToyBwm();
		};
	};
	class BenzFactory : public AbustractFactory
	{
	public:
		AbstractRealCar* createRealCar() override {
			return new RealBenz();
		};
		AbstractToyCar* createToyCar() override {
			return new ToyBenz();
		};
	};


	static void test()
	{
		AbustractFactory* factory = new BenzFactory();
		AbstractRealCar* realbwnz = factory->createRealCar();
		realbwnz->run();

	}
}
