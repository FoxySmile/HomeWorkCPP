#include <iostream>
#define random(a, b) a + rand() % (b-a+1)


using namespace std;

template <typename T>
struct Node {
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class List {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int count = 0;
public:
	void push(T value) {
		Node<T>* newNode = new Node<T>;               
		newNode->next = nullptr;                  
		newNode->value = value;                        
		if (head != nullptr) {
			newNode->prev = tail;              
			tail->next = newNode;
			tail = newNode;
		}
		else {
			newNode->prev = nullptr;
			head = tail = newNode;
		}
		count++;
	}

	void insert(T el, int index) {
		if (index == 0) {
			push(el);
			return;
		}
		if (index > count || index < 0) {
			return;
		}
		Node<T>* buf = head;
		Node<T>* newNode;
		if (index <= count / 2) {
			for (int i = 0; i < index - 1; i++) {
				buf = buf->next;
			}
			newNode = new Node<T>{ el, buf->next, buf };
			buf->next->prev = newNode;
			buf->next = newNode;
		}
		else {
			buf = tail;
			for (int i = 0; i < count - index - 1; i++) {
				buf = buf->prev;
			}
			newNode = new Node<T>{ el, buf, buf->prev };
			buf->prev->next = newNode;
			buf->prev = newNode;
		}
		count++;
	}

	void removeElementByIndex(int index) {
		Node<T>* buf = head;
		Node<T>* remEl;
		if (index <= count / 2) {
			if (index == 0) {
				dropHead();
				return;
			}
			for (int i = 0; i < index - 1; i++) {
				buf = buf->next;
			}
			remEl = buf->next;
			buf->next = buf->next->next;
			buf->next->prev = buf;
			delete[]remEl;
		}
		else {
			buf = tail;
			if (index == count) {
				dropTail();
				return;
			}
			for (int i = 0; i < count - index - 1; i++) {
				buf = buf->prev;
			}
			remEl = buf->prev;
			buf->prev = buf->prev->prev;
			buf->prev->next = buf;
			delete[]remEl;
		}
		count--;
	}

	void removeElementsByIndex(int index, int num) {
		Node<T>* buf = head;
		Node<T>* remEl;
		if (num > count - 1) {
			return;
		}
		if (index <= count / 2) {
			if (index == 0) {
				for (int i = 0; i < num; i++) {
					dropHead();
				}
				return;
			}
			for (int i = 0; i < index - 1; i++) {
				buf = buf->next;
			}
			for (int i = index; i < index + num + 1; i++) {
				remEl = buf->next;
				buf->next = buf->next->next;
				buf->next->prev = buf;
				delete[]remEl;
				count--;
			}
		}
		else {
			buf = tail;
			if (index == count) {
				for (int i = 0; i < num; i++) {
					dropTail();
				}
				return;
			}
			for (int i = 0; i < index - 1; i++) {
				buf = buf->prev;
			}
			for (int i = index; i < index + num + 1; i++) {
				remEl = buf->prev;
				buf->prev = buf->prev->prev;
				buf->prev = buf;
				delete[]remEl;
				count--;
			}
		}
	}

	void dropHead() {
		if (count == 0) {
			return;
		}
		Node<T>* buf = head;
		head = head->next;
		head->prev = nullptr;
		count--;
		delete[] buf;
	}

	void dropTail() {
		Node<T>* buf = tail;
		tail = tail->prev;
		tail->next = nullptr;
		count--;
		delete[] buf;
	}

	void showHead() {
		Node<T>* buf = head;
		while (buf->next != nullptr) {
			cout << buf->value << "|";
			buf = buf->next;
		}
		cout << buf->value << endl;
	}

	void showTail() {
		Node<T>* buf = tail;
		while (buf->prev != nullptr) {
			cout << buf->value << "|";
			buf = buf->prev;
		}
		cout << buf->value << endl;
	}
};

int main() {
	srand(time(NULL));
	List<int> list;
	for (int i = 0; i < 10; i++) {
		list.push(i);
	}
	list.showHead();
	list.removeElementsByIndex(3, 2);
	list.showHead();
	list.showTail();
}