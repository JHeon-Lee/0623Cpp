#include <iostream>
#include <vector>

using namespace std;

// STL : Standard Template Library
// �����̳�(container) - �ڷᱸ�� ex) vector
// sequence
// associative
// adapter�� ����
// 
// �ݺ���(iterator) - �����̳��� ���ҵ鿡 �����Ҷ� ���
// �˰���(algorithm) - ���� / ���� �� �Ϲ����� �����

void Sequence_Container(); // �������� ������ ���� --> �������� ������ �ٷ�µ� ����
// �߰��� �����ϴ� �۾��� ����

int main()
{
	Sequence_Container();

	return 0;
}

void Sequence_Container()
{
	//vector
	{
		cout << "Vector" << endl;

		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec) // ������� for ��, ele : element �ظ�, �̰ŷ� ���°� �� ����
			cout << ele << ' ';
		cout << endl << endl;

		cout << vec[5] << endl; // ���ʹ� �ε��� ������ ���������� �ٸ��� �Ұ����� ��쵵 ����
	}
}
