#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

template <typename T>
class BinaryTree {
private:
	Node<T>* root = nullptr;
	int count = 0;

	void showAll(Node<T>* el) {
		cout << el->value << " ";
		if (el->left != nullptr) {
			showAll(el->left);
		}
		if (el->right != nullptr) {
			showAll(el->right);
		}
	}
public:

	void add(T value) {
		Node<T>* newNode = new Node<T>{ value };
		if (root == nullptr) {
			root = newNode;
			count++;
			return;
		}
		Node<T>* buf = root;
		while (true) {
			if (value > buf->value) {
				if (buf->right == nullptr) {
					buf->right = newNode;
					break;
				}
				buf = buf->right;
			}
			else {
				if (buf->left == nullptr) {
					buf->left = newNode;
					break;
				}
				buf = buf->left;
			}
		}
		count++;
	}

	void remove(T value) {
		Node<T>* parent = root;
		Node<T>* val = nullptr;
		Node<T>* buf = nullptr;

		//Удаление корня
		if (value == root->value) {
			val = parent;
			buf = parent->right;
			while (buf->left != nullptr) {
				parent = buf;
				buf = buf->left;
			}
			parent->left = buf->right;
			val->value = buf->value;
			delete[]buf;
			return;
		}

		//Поиск удаляемого числа
		while (value != parent->value) {
			buf = parent;
			if (value >= parent->value) {
				parent = parent->right;
			}
			else if (value <= parent->value) {
				parent = parent->left;
			}
			val = parent;
		}

		//Когда удаляемый узел это лист без потомков
		if (parent->left == nullptr && parent->right == nullptr) {
			//Для левой части дерева
			if (buf->left == parent) {
				buf->left = nullptr;
			}
			//Для правой части дерева
			else if (buf->right == parent) {
				buf->right = nullptr;
			}
		}

		//Когда удаляемого узла есть правый потомок
		else if (parent->left != nullptr && parent->right == nullptr) {
			buf->right = parent->left;
		}

		//Когда у удаляемого узла есть левый потомок
		else if (parent->left == nullptr && parent->right != nullptr) {
			//Определяем число больше корня
			if (value > root->value) {
				buf->right = parent->right;
			}
			//Либо меньше
			else if (value < root->value) {
				buf->left = parent->right;
			}
		}

		//Когда у удаляемого узла есть оба потомка

		// --- Определяем число больше корня
		if (value > root->value) {
			buf = parent->left;
			while (buf->right != nullptr) {
				parent = buf;
				buf = buf->right;
			}
			parent->right = buf->left;
			val->value = buf->value;
			delete[]buf;
		}
		// --- Либо меньше
		else {
			buf = parent->right;
			while (buf->left != nullptr) {
				parent = buf;
				buf = buf->left;
			}
			parent->left = buf->right;
			val->value = buf->value;
			delete[]buf;
		}
	}

	void show() {
		if (root != nullptr) {
			showAll(root);
		}
	}
};

int main() {
	int arr[]{ 12, 8, 11, 7, 10, 45, 24, 67, 32, 46, 86, 43, 48, 57, 55 };
	BinaryTree<int> bt;
	for (int i = 0; i < size(arr); i++) {
		bt.add(arr[i]);
	}
	bt.remove(12);
	bt.show();
}