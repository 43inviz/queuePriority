#pragma once
using namespace std;
template <typename T>

class QueuePriority
{
	int size;
	int capacity;
	T* queue;
	int* priority;
public:

	QueuePriority(int capacity);
	~QueuePriority();

	bool isEmpty();
	bool isFull();

	void addWithPriority(T value, int priority);
	T dequeuePriority();

	void removeByPriority();

	void show();
};

template<typename T>
inline QueuePriority<T>::QueuePriority(int capacity)
{
	this->capacity = capacity+5;
	this->priority = new int[capacity];
	this->queue = new T[capacity];
	this->size = 0;
}

template<typename T>
inline QueuePriority<T>::~QueuePriority()
{
	delete[]queue;
	delete[] priority;

}

template<typename T>
inline bool QueuePriority<T>::isEmpty()
{
	if (size == 0) {
		return true;
	}
	return false;
}

template<typename T>
inline bool QueuePriority<T>::isFull()
{
	return this->size == this->capacity;
}



template<typename T>
inline void QueuePriority<T>::addWithPriority(T value, int priority)
{
	if (isFull()) {
		this->capacity *= 2;

		T* queueCopy = new T[this->capacity];
		int* priorityCopy = new int[this->capacity];

		for (int i = 0; i < this->size; i++) {
			queueCopy[i] = this->queue[i];
			priorityCopy[i] = this->priority[i];
		}

		delete[] this->queue;
		delete[] this->priority;

		this->queue = queueCopy;
		this->priority = priorityCopy;
	}

	
	this->queue[this->size] = value;
	this->priority[this->size] = priority;
	this->size++;
}

template<typename T>
inline T QueuePriority<T>::dequeuePriority()
{
	if (!isEmpty()) {

		int maxPriority = this->priority[0];
		int maxPriorityIndex = 0;

		for (int i = 0; i < this->size; i++) {
			if (this->priority[i] > maxPriority) {
				maxPriority = priority[i];
				maxPriorityIndex = i;
			}
		}

		T temp = this->queue[maxPriorityIndex];
	
		return temp;
	}
	
}

template<typename T>
inline void QueuePriority<T>::removeByPriority()
{
	if (!isEmpty()) {
		int maxPriority = this->priority[0];
		int maxPriorityIndex = 0;

		for (int i = 0; i < this->size; i++) {
			if (this->priority[i] > maxPriority) {
				maxPriority = this->priority[i];
				maxPriorityIndex = i;
			}
		}

		for (int i = maxPriorityIndex; i < this->size-1; i++) {
			this->queue[i] = queue[i + 1];
			this->priority[i] = priority[i + 1];
		}
		this->size--;

	}
	
	
}

template<typename T>
inline void QueuePriority<T>::show()
{
	for (int i = 0; i < this->size; i++) {
		cout << queue[i] << " ";
		
	}
	cout << endl;
}
