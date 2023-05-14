#ifndef BAG
#define BAG

template<typename Item>
class Bag {
public:
	// representation of the node

	int N = 0;

	struct Node
	{
		Item item;
		Node *next;
	};
	Node *first; // first node in the list
	
  public:
	// constructor
	Bag() { first = nullptr; }
	// destructor
	~Bag();

	// add an item to the bag
	void add(Item item);

	int size(){ return N; }

	Node* iter(){	return first;  }
};


template<typename Item>
Bag<Item>::~Bag() {
	while(first!=nullptr){
		Node *oldfirst = first;
		first = first->next;
		delete oldfirst;
	}
}

template<typename Item>
void Bag<Item>::add(Item item) {
	Node *oldfirst = first;
	first = new Node();
	first->item = item;
	first->next = oldfirst;
	N++;
}

#endif