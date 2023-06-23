#include <iostream>

using namespace std;

template <class T>
class A
{
public:
	A(const T& value)
		: value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

// 특수화 부분
template <class T>
class A<T*>
{
public:
	A(T* value)
		:value(value)
	{}

	void Print()
	{
		cout << *value << endl;
	}

private:
	T* value;
};

int main()
{
	A<int> Aint(123);
	Aint.Print();

	int temp = 456;
	A<int*> Aptr(&temp);
	Aptr.Print(); // 특수화 없이 출력 --> 주소가 출력됨 --> 포인터에 대해 특수화 필요

	return 0;
}

// homework
// vehicle 클래스는 함수 movement를 가짐
// vehicle 클래스를 상속받는 세 airplane, car, ship 클래스
// 각각 movement를 호출했을때 (비행기 이동), (차 이동), (배 이동) 을 출력하도록 한다
// 모든 이동수단의 총 합이 5를 초과할 경우
// 객체 생성 시 "이동 수단 개체 수가 5를 초과합니다" 를 출력