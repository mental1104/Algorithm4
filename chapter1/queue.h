//ALGORITHM 1.3 FIFO queue
#ifndef QUEUE
#define QUEUE

template<typename Item>
class Queue {
  private:
	// representation of node	
	struct Node{
		Item item;
		Node *next;
	};
	Node *first; // first node (least recently added)
	Node *last; // last node (most recently added)
	int N; // number of items

  public:
	// constructor
	Queue() { first = nullptr; last = nullptr; N=0; }
	// destructor
	~Queue();

	// return whethe the queue is empty
	bool isEmpty() { return N == 0; }
	// return size of the queue
	int size() { return N; }
	// add an item to the end of the queue
	void enqueue(Item item);
	// delete an item at the beginning of the queue
	Item dequeue();
    //traverse
    void traverse(std::ostream& os);
};


template<typename Item>
Queue<Item>::~Queue() {
	while(first!=nullptr){
		Node *oldfirst = first;
		first = first->next;
		delete oldfirst;
		N--;
	}
}

template<typename Item>
void Queue<Item>::enqueue(Item item) {
	Node *oldlast = last;
	last = new Node();
	last->item = item;
	last->next = nullptr;
	if(isEmpty())
		first = last;
	else
		oldlast->next = last;
	N++;
}

template<typename Item>
Item Queue<Item>::dequeue() {
	// process exception
	if(isEmpty())
		throw "Quene is empty, cannot dequene any more!";

	Item item = first->item;
	Node *oldfirst = first;
	first = first->next;
	delete oldfirst;
	N--;
	if(isEmpty())
		last = nullptr;//if first == last
	return item;
}

template<typename Item>
void Queue<Item>::traverse(std::ostream& os){
    Node* temp = first;
    while(temp!= last){
        os << temp->item << "   ";
        temp = temp->next;
    }
    os << temp->item << std::endl;
}
#endif