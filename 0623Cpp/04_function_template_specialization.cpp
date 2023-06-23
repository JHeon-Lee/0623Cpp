#include <iostream>

// 템플릿 특수화

using namespace std;

template <typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

template <> // 특수화 부분
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl;
	return (x > y) ? x : y;
}

template <class T>
class Storage
{
public:
	Storage(T value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};

template <> // 클래스 전체 특수화가 아니라 Print 함수만 특별화 하는거임
void Storage<double>::Print()
{
	cout << "double : " << value << endl;
}

int main()
{
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.0f, 4.0f) << endl;
	cout << GetMax('a', 'b') << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.2);
	s2.Print();

	return 0;
}