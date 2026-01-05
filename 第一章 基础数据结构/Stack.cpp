#include <stack>
#include <iostream>

template <typename T>
class Stack2Queue {
public:
	Stack2Queue(){}
	void push(T x) {
		instack.push(x);
	}
	T pop() {
		if (outstack.empty()) in2out();
		T res = outstack.top();
		outstack.pop();
		return res;
	}

	T front() {
		if (outstack.empty()) {
			in2out();
		}
		return outstack.top();
	}
	bool empty() {
		return instack.empty() && outstack.empty();
	}
private:
	std::stack<T> instack;
	std::stack<T> outstack;
	void in2out() {
		while (!instack.empty()) {
			outstack.push(instack.top());
			instack.pop();
		}
	}
};
