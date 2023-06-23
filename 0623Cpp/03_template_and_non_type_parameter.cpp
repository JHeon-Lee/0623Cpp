#include <iostream>
#include <array>

using namespace std;

// non type parameter 삽입
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
	MyArray<int, 10> arr1; // <> 사용하면 템플릿이라 보면 됨, 컴파일 될 때 잡히게됨
	MyArray<float, 20> arr2;

	for (int i = 0; i < 20; i++)
		arr2[i] = i;

	for (int i = 0; i < 20; i++)
		cout << arr2[i] << ' ';

	cout << endl << endl;

	//array 라이브러리 활용
	array<int, 10> arr3;

	for (int i = 0; i < 10; i++)
		arr3[i] = i;

	for (int i = 0; i < 10; i++)
		cout << arr3[i] << ' ';

	cout << endl;

	return 0;
}