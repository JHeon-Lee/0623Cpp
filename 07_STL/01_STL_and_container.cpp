#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

// STL : Standard Template Library - 일반화가 특징.
// 컨테이너(container) - 자료구조 ex) vector
// sequence
// associative
// adapter로 나뉨
// 
// 반복자(iterator) - 컨테이너의 원소들에 접근할때 사용
// 
// 알고리즘(algorithm) - 정렬 / 삭제 등 일반적인 방법들

void Sequence_Container(); // 선형으로 데이터 저장 --> 연속적인 데이터 다루는데 유리
// 중간에 삽입하는 작업은 느림

void Associative_Container(); // 데이터를 일정한 규칙으로 저장 ex) 이진트리, 해시테이블
// 자동으로 정렬해서 저장
// key - value 의 구조를 가짐

void Adapter_Container(); // 기존 컨테이너를 변형해서 만듬
// 특정 형태의 동작만을 구현
// 반복자(iterator) 지원 X

int main()
{
	// Sequence_Container();
	// Associative_Container();
	Adapter_Container();

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
		cout << endl << vec[5] << endl; // 벡터는 인덱스 접근이 가능하지만 다른건 불가능한 경우도 있음

		cout << endl << endl;
	}

	// 6/28 ~ 
	// Deque : 서로 떨어져있는 데이터 연결 - vector의 원소 추가/삭제 기능을 보완
	// 크기예측이 불가능할때 사용
	{
		cout << "Deque" << endl;

		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl << endl;
	}

	// list : 단방향, 양방향 존재
	// 양방향 : 원소가 서로 앞, 뒤를 가리킨다 맨앞, 맨뒤는 null을 가르킨다
	// 중간위치에 바로 접근 불가, 인덱스 접근 불가
	// 중간에 원소 삽입 시 가리키는 것만 바꿔주면 되므로 빠름 --> 원소 삽입, 삭제가 잦을 때 주로 사용
	{
		cout << "List" << endl;

		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl << endl;
	}
}

void Associative_Container()
{
	// Set / MultiSet : value 자체를 key로 사용
	{
		cout << "Set" << endl;

		set<string> strset1;

		strset1.insert("Hello");
		strset1.insert("World");
		strset1.insert("Hello");

		cout << strset1.size() << endl; // 2개라 나옴 --> 중복을 허용하지 않음

		for (const auto& ele : strset1)
			cout << ele << ' ';
		cout << endl << endl;
	}
	// MultiSet
	{
		cout << "MultiSet" << endl;

		multiset<string> strset2;

		strset2.insert("Hello");
		strset2.insert("World");
		strset2.insert("Hello");

		cout << strset2.size() << endl; // 3개라 나옴 --> Set과 다르게 중복 허용

		for (const auto& ele : strset2)
			cout << ele << ' '; // insert한 순서와 다르게 Hello 끼리 묶여서 먼저 나오고 다음에 World가 나옴
		// 알파벳 순서로 정렬됨
		cout << endl << endl;
	}

	// Map / MultiMap : Associative_Container 중 제일 중요(key - value 의 구조가 잘 나옴)
	{
		cout << "Map" << endl;
		
		map<char, int> map; // mapping - key, value의 자료형 명시

		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl; // key에 매칭되는 값 출력

		map['a'] = 100;
		cout << map['a'] << endl;

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' '; // first, second로 key, value 출력
		cout << endl << endl; // key 값이 정렬되서 나옴
	}
	// MultiMap
	{
		cout << "MultiMap" << endl;

		multimap<char, int> multimap;

		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		multimap.insert(make_pair('a', 1000)); // 자료형 생략 가능, 17표준에선 pair도 생략되긴함
		// insert 함수를 써서 삽입 pair : 두개만 저장할 수 있는 구조체

		cout << multimap.count('a') << endl; // 2개

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl << endl; // key 값 정렬 후 출력, a의 value는 insert한 순서대로
	}
}

void Adapter_Container()
{
	// Stack - LIFO 구조 (last in first out) --> vector 변형
	// 임의접근 불가
	{
		cout << "Stack" << endl;

		stack<int> stack;
		stack.push(1); // push 는 복사해서 넣음
		stack.emplace(3); // 새로운 객체를 만듬 --> 가변인자 통해 들어감, 이동

		cout << stack.top() << endl; // 3
		stack.pop(); // 3 삭제
		cout << stack.top() << endl << endl; // 1
	}

	// Queue - 중요함, API때 메세지 전달 방식으로 쓰임, FIFO 구조 (first in first out)
	{
		cout << "Queue" << endl;

		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << ' ' << queue.back() << endl; // 1 3
		queue.pop(); // 1 삭제
		cout << queue.front() << ' ' << queue.back() << endl << endl; // 2 3
	}

	// Priority Queue - 우선순위가 정해짐 --> vector 변형
	{
		cout << "Priority Queue" << endl;
		priority_queue<int> priorityQueue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			priorityQueue.push(n);

		for (int i = 0; i < 10; i++)
		{
			cout << priorityQueue.top() << endl;
			priorityQueue.pop();
		} // -->  9 8 7 6 5 4 3 2 1 0
	}
}
