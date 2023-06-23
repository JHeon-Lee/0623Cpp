#include <iostream>
#include <array>

using namespace std;

// non type parameter ����
template <typename T, unsigned int SIZE>
class MyArray
{
public:
	MyArray() = default;
	~MyArray(){}

	T& operator[](int index)
	{
		return arr2[index];
	}

private:
	T arr1[10];
	T arr2[SIZE];
};

int main()
{
	MyArray<int, 10> arr1; // <> ����ϸ� ���ø��̶� ���� ��, ������ �� �� �����Ե�
	MyArray<float, 20> arr2;

	for (int i = 0; i < 20; i++)
		arr2[i] = i;

	for (int i = 0; i < 20; i++)
		cout << arr2[i] << ' ';

	cout << endl << endl;

	//array ���̺귯�� Ȱ��
	array<int, 10> arr3;

	for (int i = 0; i < 10; i++)
		arr3[i] = i;

	for (int i = 0; i < 10; i++)
		cout << arr3[i] << ' ';

	cout << endl;

	return 0;
}