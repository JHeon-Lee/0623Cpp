#include <iostream>

// 04와 다르게 클래스 전체를 특수화

using namespace std;

template <class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl; // typeid : 런타임에 객체 형식 확인
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
	// achar.Test(); --> 불가능, 특수화 부분에 Test()는 구현해두지 않음

	return 0;
}