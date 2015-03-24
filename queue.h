//queue.h
// simple queue template
#ifndef QUEUE_H
#define QUEUE_H
#define null 0

template<class T>
class queue {
public:
	queue();
	queue(const T item);
	~queue();
	void enqueue(const T item);
	T dequeue();
	T peek();

private:
	class node {
	public:
		node();
		node(const T item);
		node *next;
		T data;
	};
	node *tail;
	node *head;
	unsigned int size;
};

template<class T>
queue<T>::node::node(){
	next = null;
}

template<class T>
queue<T>::node::node(const T item){
	next = null;
	data = item;
}

template<class T>
queue<T>::queue() {
	size = 0;
	head = null;
	tail = null;
}

template<class T>
queue<T>::queue(const T item) {
	size = 1;
	head = new node(item);
	tail = head;
}

template<class T>
void queue<T>::enqueue(const T item) {
	node *temp = new node(item);
	if (head == null) {
		head = temp;
		tail = head;
	} else {
		tail->next = temp;
	}
}

template<class T>
T queue<T>::dequeue() {
	if (head == null) {
		return null; //error
	}
	T item = head->data;
	node *temp = head;
	head = head->next;
	if (head == null) {
		tail = null;
	}
	delete head;
	return item;
}

template<class T>
T queue<T>::peek() {
	if (head == null) {
		return null; //error
	}
	return head->data;
}

#endif