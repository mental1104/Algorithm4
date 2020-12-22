template<typename Item>
class Bag {
  private:
	// representation of the node
	struct Node
	{
		Item item;
		Node *next;
	};
	Node *first; // first node in the list
	
  public:
	// constructor
	Bag() { first = new Node(); }
	// destructor
	~Bag();

	// add an item to the bag
	void add(Item item);
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
}