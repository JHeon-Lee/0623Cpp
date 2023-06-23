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

// Ư��ȭ �κ�
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
	Aptr.Print(); // Ư��ȭ ���� ��� --> �ּҰ� ��µ� --> �����Ϳ� ���� Ư��ȭ �ʿ�

	return 0;
}

// homework
// vehicle Ŭ������ �Լ� movement�� ����
// vehicle Ŭ������ ��ӹ޴� �� airplane, car, ship Ŭ����
// ���� movement�� ȣ�������� (����� �̵�), (�� �̵�), (�� �̵�) �� ����ϵ��� �Ѵ�
// ��� �̵������� �� ���� 5�� �ʰ��� ���
// ��ü ���� �� "�̵� ���� ��ü ���� 5�� �ʰ��մϴ�" �� ���