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
	for (int i = 0; i < 2; i++) {
		list.push(i);
	}
	list.showHead();
	list.showTail();
}