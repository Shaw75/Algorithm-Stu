#include <iostream>
#include "第一章 基础数据结构/list.cpp"
#include "第一章 基础数据结构/stack.cpp"
#include "第一章 基础数据结构/tree.cpp"
#include "第一章 基础数据结构/priority_queue.cpp"


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


	{
		Tree<int> tree;
		int a[] = { 6,4,8,2,5,7,9,1,3 };
		for (int i = 0; i < 9; ++i) {
			tree.insert(a[i]);
		}
		tree.foreach();
		std::cout << "\n" << tree.height() << std::endl;
		std::cout << tree.weight() ;
		tree.erase(3);
		tree.foreach();
		std::cout << "\n";
	}
	{
		priority_queue q;
		q.push(5);
		q.push(6);
		q.push(7);
		q.push(3);
		q.push(2);
		q.push(1);
		q.foreach();
		q.pop();
		q.foreach();
	}
	return 0;
}