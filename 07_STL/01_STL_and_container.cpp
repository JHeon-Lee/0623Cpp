#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

// STL : Standard Template Library - �Ϲ�ȭ�� Ư¡.
// �����̳�(container) - �ڷᱸ�� ex) vector
// sequence
// associative
// adapter�� ����
// 
// �ݺ���(iterator) - �����̳��� ���ҵ鿡 �����Ҷ� ���
// 
// �˰���(algorithm) - ���� / ���� �� �Ϲ����� �����

void Sequence_Container(); // �������� ������ ���� --> �������� ������ �ٷ�µ� ����
// �߰��� �����ϴ� �۾��� ����

void Associative_Container(); // �����͸� ������ ��Ģ���� ���� ex) ����Ʈ��, �ؽ����̺�
// �ڵ����� �����ؼ� ����
// key - value �� ������ ����

void Adapter_Container(); // ���� �����̳ʸ� �����ؼ� ����
// Ư�� ������ ���۸��� ����
// �ݺ���(iterator) ���� X

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

		for (const auto& ele : vec) // ������� for ��, ele : element �ظ�, �̰ŷ� ���°� �� ����
			cout << ele << ' ';
		cout << endl << vec[5] << endl; // ���ʹ� �ε��� ������ ���������� �ٸ��� �Ұ����� ��쵵 ����

		cout << endl << endl;
	}

	// 6/28 ~ 
	// Deque : ���� �������ִ� ������ ���� - vector�� ���� �߰�/���� ����� ����
	// ũ�⿹���� �Ұ����Ҷ� ���
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

	// list : �ܹ���, ����� ����
	// ����� : ���Ұ� ���� ��, �ڸ� ����Ų�� �Ǿ�, �ǵڴ� null�� ����Ų��
	// �߰���ġ�� �ٷ� ���� �Ұ�, �ε��� ���� �Ұ�
	// �߰��� ���� ���� �� ����Ű�� �͸� �ٲ��ָ� �ǹǷ� ���� --> ���� ����, ������ ���� �� �ַ� ���
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
	// Set / MultiSet : value ��ü�� key�� ���
	{
		cout << "Set" << endl;

		set<string> strset1;

		strset1.insert("Hello");
		strset1.insert("World");
		strset1.insert("Hello");

		cout << strset1.size() << endl; // 2���� ���� --> �ߺ��� ������� ����

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

		cout << strset2.size() << endl; // 3���� ���� --> Set�� �ٸ��� �ߺ� ���

		for (const auto& ele : strset2)
			cout << ele << ' '; // insert�� ������ �ٸ��� Hello ���� ������ ���� ������ ������ World�� ����
		// ���ĺ� ������ ���ĵ�
		cout << endl << endl;
	}

	// Map / MultiMap : Associative_Container �� ���� �߿�(key - value �� ������ �� ����)
	{
		cout << "Map" << endl;
		
		map<char, int> map; // mapping - key, value�� �ڷ��� ���

		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl; // key�� ��Ī�Ǵ� �� ���

		map['a'] = 100;
		cout << map['a'] << endl;

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' '; // first, second�� key, value ���
		cout << endl << endl; // key ���� ���ĵǼ� ����
	}
	// MultiMap
	{
		cout << "MultiMap" << endl;

		multimap<char, int> multimap;

		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		multimap.insert(make_pair('a', 1000)); // �ڷ��� ���� ����, 17ǥ�ؿ��� pair�� �����Ǳ���
		// insert �Լ��� �Ἥ ���� pair : �ΰ��� ������ �� �ִ� ����ü

		cout << multimap.count('a') << endl; // 2��

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl << endl; // key �� ���� �� ���, a�� value�� insert�� �������
	}
}

void Adapter_Container()
{
	// Stack - LIFO ���� (last in first out) --> vector ����
	// �������� �Ұ�
	{
		cout << "Stack" << endl;

		stack<int> stack;
		stack.push(1); // push �� �����ؼ� ����
		stack.emplace(3); // ���ο� ��ü�� ���� --> �������� ���� ��, �̵�

		cout << stack.top() << endl; // 3
		stack.pop(); // 3 ����
		cout << stack.top() << endl << endl; // 1
	}

	// Queue - �߿���, API�� �޼��� ���� ������� ����, FIFO ���� (first in first out)
	{
		cout << "Queue" << endl;

		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << ' ' << queue.back() << endl; // 1 3
		queue.pop(); // 1 ����
		cout << queue.front() << ' ' << queue.back() << endl << endl; // 2 3
	}

	// Priority Queue - �켱������ ������ --> vector ����
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
