#include <iostream>
#include <string>
#include <list>

using namespace std;
namespace OBS {

	class Observer//抽象观察者 
	{
	public:
		virtual void update(int status) = 0;//更新
	};
	class Subject //抽象目标
	{
	public:
		virtual void Attch(Observer*) = 0;//添加观察者
		virtual void Detch(Observer*) = 0;//删除观察者
		virtual void Notify() = 0;//通知
		virtual void setstatus(int) = 0;
	};

	class ConcreateObserver : public Observer
	{
	public:
		ConcreateObserver(Subject* psub) :m_psub(psub) {}
		void update(int status) override {
			cout << "concreateobserver updata status=" << status << endl;
		}
	private:
		Subject* m_psub;
	};

	class ConctreateSubject : public Subject
	{
	public:
		void Attch(Observer* ovs)override {
			m_ovlist.push_back(ovs);
		}
		void Detch(Observer* ovs)override {
			m_ovlist.remove(ovs);
		}
		void Notify()override {
			for (auto avs : m_ovlist)
			{
				avs->update(m_status);
			}
		}
		void setstatus(int status) override
		{
			m_status = status;
		}
	private:
		std::list<Observer*> m_ovlist;
		int m_status;

	};

	static void test()
	{

		Subject* psub = new ConctreateSubject();//目标
		Observer* pobs = new ConcreateObserver(psub);//观察者

		psub->Attch(pobs);
		psub->setstatus(1);
		psub->Notify();



	}
}

