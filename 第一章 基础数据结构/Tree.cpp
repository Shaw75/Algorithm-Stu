#include <iostream>
#include <queue>

template <typename T>
class Tree {
private:
	struct TreeNode {
		T data;
		TreeNode* left;
		TreeNode* right;
		explicit TreeNode(T data) : data{ data }, left{ nullptr }, right{ nullptr } {}
	};

public:
	Tree() = default;
	Tree(const Tree&) = delete;
	Tree& operator=(const Tree&) = delete;
	void insert(int key) { root = insert(root, key); }
	void erase(int key) { root = erase(root, key); }
	int height() { return height(root); }
	void foreach() { foreach(root); }
	int weight() {
		if (!root) return 0;
		std::queue<TreeNode*> q;
		q.push(root);
		int res = 0;
		while (!q.empty()) {
			int levelSize = static_cast<int>(q.size());
			res = std::max(res, levelSize);
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* curr = q.front();
				q.pop();
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		}
		return res;
	}
	~Tree() {
		destroy(root);
		root = nullptr;
	}
private:
	static TreeNode* insert(TreeNode* node, T key) {
		if (!node) return new TreeNode(key);
		if (key < node->data) node->left = insert(node->left, key);
		else if (key > node->data) node->right = insert(node->right, key);
		return node;
	}
	static void foreach(TreeNode* node) {
		if (!node) return;
		std::cout << node->data << " ";
		foreach(node->left);
		foreach(node->right);
	}
	static int height(TreeNode* node) {
		if (!node) return 0;
		return 1 + std::max(height(node->left), height(node->right));
	}
	static TreeNode* minNode(TreeNode* node) {
		if (!node) return nullptr;
		while (node->left) {
			node = node->left;
		}
		return node;
	}
	static TreeNode* erase(TreeNode* node, T key) {
		if (!node) return nullptr;
		if (key < node->data) node->left = erase(node->left, key);
		else if (key > node->data) node->right = erase(node->right, key);
		else {
			if (!node->left && !node->right) {
				delete node;
				return nullptr;
			}
			else if (!node->left) {
				TreeNode* curr = node->right;
				delete node;
				return curr;
			}
			else if (!node->right) {
				TreeNode* curr = node->left;
				delete node;
				return curr;
			}
			else {
				TreeNode* curr = minNode(node->right);
				node->data = curr->data;
				node->right = erase(node->right, curr->data);
				
			}
		}
		return node;
	}

	static void destroy(TreeNode* node) {
		if (!node) return;
		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	TreeNode* root{ nullptr };
};