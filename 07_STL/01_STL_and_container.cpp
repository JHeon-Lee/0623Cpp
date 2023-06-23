#include <iostream>
#include <vector>

using namespace std;

// STL : Standard Template Library
// 컨테이너(container) - 자료구조 ex) vector
// sequence
// associative
// adapter로 나뉨
// 
// 반복자(iterator) - 컨테이너의 원소들에 접근할때 사용
// 알고리즘(algorithm) - 정렬 / 삭제 등 일반적인 방법들

void Sequence_Container(); // 선형으로 데이터 저장 --> 연속적인 데이터 다루는데 유리
// 중간에 삽입하는 작업은 느림

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

		for (const auto& ele : vec) // 범위기반 for 문, ele : element 준말, 이거로 쓰는게 더 좋음
			cout << ele << ' ';
		cout << endl << endl;

		cout << vec[5] << endl; // 벡터는 인덱스 접근이 가능하지만 다른건 불가능한 경우도 있음
	}
}
