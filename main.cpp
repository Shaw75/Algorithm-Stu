#include <iostream>
#include "第一章 基础数据结构/List.cpp"
#include "第一章 基础数据结构/Stack.cpp"

int main() {
	// 单元测试
	{
		List<int> list;
		queue<int> queue;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_front(0);
		list.foreach();
		queue.push(1);
		queue.push(2);
		int res;
		queue.pop(res);
		std::cout << res << std::endl;
		std::cout << queue.front() << std::endl;
		queue.push(3);
		queue.push(4);
		queue.push(5);
		queue.push(6);
		queue.pop(res);
		queue.foreach();
	}

	{
		Stack2Queue<int> s2q;
		s2q.push(1);
		s2q.push(2);
		s2q.push(3);
		s2q.push(4);
		s2q.push(5);
		// s2q.pop();
		s2q.pop();
		s2q.pop();
		s2q.pop();
		s2q.pop();
		while (!s2q.empty()) {
			std::cout << s2q.pop() << std::endl;
		}
		std::cout << s2q.empty() << std::endl;
	}
	return 0;
}