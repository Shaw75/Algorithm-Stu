#include <iostream>
template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class List {
public:
	List() {
		head = new Node<T>();
		head->next = nullptr;
		tail = head;
	}

	~List() {
		Node<T>* curr = head;
		while (curr) {
			Node<T>* next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
	}

	bool push_back(T data) {
		Node<T>* p = new Node<T>();
		p->data = data;
		p->next = nullptr;
		tail->next = p;
		tail = p;
		return true;
	}

	bool push_front(const T& data) {
		Node<T>* p = new Node<T>();
		p->data = data;

		p->next = head->next;  
		head->next = p;         

		if (tail == head) {   
			tail = p;
		}
		return true;
	}
	void foreach() {
		Node<T>* curr = head->next;
		while (curr) {
			std::cout << curr->data << std::endl;
			curr = curr->next;
		}
	}
private:
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
struct QNode {
	T* data;
	int rear, head;
};
template <typename T>
class queue {
public:
	queue() {
		node.data = new T[6];
		node.head = node.rear = 0;
	}
	~queue() {
		if (node.data) {
			delete[] node.data;
		}
	}
	int size() {
		return (node.rear - node.head + 6) % 6;
	}
	bool empty() {
		if (size() == 0) return true;
		return false;
	}
	bool push(T data) {
		if ((node.rear + 1) % 6 == node.head) return false;
		node.data[node.rear] = data;
		node.rear = (node.rear + 1) % 6;
	}
	bool pop(T& rs) {
		if (node.head == node.rear) return false;
		rs = node.data[node.head];
		node.head = (node.head + 1) % 6;
		return true;
	}
	T front() {
		return node.data[node.head];
	}

	void foreach() {
		int curr = node.head;
		while (curr != node.rear) {
			std::cout << "±éÀú¶ÓÁÐ£º" << std::endl;
			std::cout << node.data[curr] << std::endl;
			curr = (curr + 1) % 6;
		}
	}
private:
	QNode<T> node;
};


int main() {
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
	return 0;
}