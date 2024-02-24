#include <iostream>

using namespace std;

template<typename T>
class Deque {
private:
	T* deque = nullptr;
	int count = 0;
	int capacity;
public:
	Deque(int capacity) {
		deque = new T[capacity];
		this->capacity = capacity;
	}
	Deque(Deque& dq) {
		this->count = dq.count;
		this->capacity = dq.capacity;
		if (deque != nullptr) {
			delete[]deque;
		}
		deque = new T[count];
		for (int i = 0; i < count; i++) {
			deque[i] = dq.deque[i];
		}
	}

	~Deque() {
		if (deque != nullptr) {
			delete[]deque;
		}
	}

	T at(int index) {
		if (index < 0 || index > capacity - 1) {
			return;
		}
		deque[index];
	}

	void operator=(Deque& dq) {
		this->count = dq.count;
		this->capacity = dq.capacity;
		if (deque != nullptr) {
			delete[]deque;
		}
		deque = new T[count];
		for (int i = 0; i < count; i++) {
			deque[i] = dq.deque[i];
		}
	}

	T operator[](int index) {
		return deque[index];
	}

	T front() {
		return deque[0];
	}

	T back() {
		return deque[count - 1];
	}

	bool empty() {
		return !count;
	}

	int size() {
		return count;
	}

	int max_size() {
		return capacity;
	}

	void clear() {
		delete[] deque;
		count = 0;
	}

	void insert(int index, T el) {
		if (count + 1 > capacity) {
			return;
		}
		if (index < 0 || index >= count) {
			return;
		}
		for (int i = count; i > index; i--) {
			deque[i] = deque[i - 1];
		}
		deque[index] = el;
		count++;
	}

	void push_front(T el) {
		if (count == capacity) {
			return;
		}
		for (int i = count; i >= 0; i--) {
			deque[i] = deque[i - 1];
		}
		deque[0] = el;
		count++;
	}

	void push_back(T el) {
		if (count == capacity) {
			return;
		}
		deque[count++] = el;
	}

	T pop_front() {
		if (count == 0) {
			return NULL;
		}
		for (int i = 0; i < count - 1; i++) {
			deque[i] = deque[i + 1];
		}
		count--;
		return deque[0];
	}

	T pop_back() {
		if (count == 0) {
			return NULL;
		}
		return deque[count];
	}

	void erase(int index) {
		if (index < 0 || index >= count) return;
		for (int i = index; i < count-1; i++) {
			deque[i] = deque[i + 1];
		}
		count--;
	}
};

int main() {
	Deque<int> dq(5);
}


/*Реализовать класс Deque (двунаправленная очередь)
может все, что могут queue и stack*/