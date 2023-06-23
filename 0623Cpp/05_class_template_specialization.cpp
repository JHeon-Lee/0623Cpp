#include <iostream>

// 04�� �ٸ��� Ŭ���� ��ü�� Ư��ȭ

using namespace std;

template <class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl; // typeid : ��Ÿ�ӿ� ��ü ���� Ȯ��
	}

	void Test() {}
};

template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}
};

int main()
{
	A<int> aint(10);
	A<float> afloat(10.0f);
	A<char> achar('a');

	aint.DoSomething();
	afloat.DoSomething();
	achar.DoSomething();

	aint.Test();
	// achar.Test(); --> �Ұ���, Ư��ȭ �κп� Test()�� �����ص��� ����

	return 0;
}