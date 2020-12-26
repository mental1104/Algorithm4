//ALGORITHM 1.1 Pushdown (LIFO) stack (resizing array implementation)
#ifndef STACK_ARRAY
#define STACK_ARRAY

// Stack ADT implemented by resizing array
#include<iostream>
using std::ostream;

template<typename Item>
class Stack {
  private:
	Item *a; // stack items
	int len; // maxlength of the array
	int N; // number of items
	// resize the array to fulfill the need or reduce space cost
	void resize(int max);

  public:
	// constructor
	Stack() { a = new Item[1]; len=1; N = 0; }
	// destructor
	~Stack() { delete[] a; }

	// return whether the stack is empty
	bool isEmpty() { return N == 0; }
	// return size of the stack
	int size() { return N; }
	// push an item at the beginning of the stack
	void push(Item item);
	// pop an item at the beginning of the stack
	Item pop();
	// Traverse
	void traverse(std::ostream& os);
};


template<typename Item>
void Stack<Item>::resize(int max) {
	Item *temp = new Item[max];
	for (int i = 0; i < N; i++)
		temp[i] = a[i];
	delete[] a;
	a = temp;
	len = max;
}

template<typename Item>
void Stack<Item>::push(Item item) {
	if(N==len)
		resize(2 * len);
	a[N++] = item;
}

template<typename Item>
Item Stack<Item>::pop() {
	// process exception
	if(isEmpty())
		throw "Stack is empty, cannot pop any more!";
    
	Item item = a[--N];
	// a[N] = null; // avoid loitering
	if(N>0 && N/4==len)
		resize(len / 2);
	return item;
}

template<typename Item>
void Stack<Item>::traverse(std::ostream& os){
		for(int i = 0; i < N; i++)
			os << a[i] << "   ";
		os << std::endl;
}

#endif

