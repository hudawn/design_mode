#include <iostream>
#include <string>
#include <list>
using namespace std;
namespace VIS
{
	class Element;

	class Visitor
	{
	public:
		virtual void visitorConcreateElement(Element* elmentA,string name) = 0;
	};
	class Element
	{
	public:
		virtual void accept(Visitor* vis) = 0;
		void setstatus(string name,int status) {
			m_status = status;
			cout << name << " ==" << status << endl;
		};
	private:
		int m_status;
	};
	class ConcreateVistorA : public Visitor
	{
	public:
		void visitorConcreateElement(Element* elmentA, string name) override {
			elmentA->setstatus(name, 1);
		}
	};
	
	class ConcreateElementA : public Element
	{
	public:
		void accept(Visitor* vis)override
		{
			vis->visitorConcreateElement(this,"ConcreateElementA");
		}
	};
	class ConcreateElementB : public Element
	{
	public:
		void accept(Visitor* vis) override
		{
			vis->visitorConcreateElement(this,"ConcreateElementB");
		}
	};


	static void test()
	{
		Element* peleA = new ConcreateElementA();
		Element* peleB = new ConcreateElementB();

		Visitor* visA = new ConcreateVistorA();

		peleA->accept(visA);
		peleB->accept(visA);

		delete peleA;
		delete peleB;
		delete visA;
	}
}
