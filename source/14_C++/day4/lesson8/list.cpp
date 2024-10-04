#include <iostream>
#include <ostream>

using namespace std;

class myList {	
	struct Node{
		Node(int x, Node *ptr=NULL):data(x), next(ptr) { }
		int data;
		Node *next;
	};

public:
	myList():head(NULL) { }
	
	~myList() {
		while (head) {
			Node *tem = head;
			head = head->next;
			delete tem;
		}
	}

	void insert_head(int data)
	{
		Node *node = new Node(data);
		node->next = head;
		head = node;
	}

	friend ostream &operator<<(ostream &out, const myList &list);

private:
	Node *head;
};

ostream &operator<<(ostream &out, const myList &list)
{
	myList::Node *tem = list.head;
	
	while (tem) {
		out<< tem->data <<',';
		tem = tem->next;
	}
	out << endl;

	return out;
}

int main(void)
{
	myList list;

	list.insert_head(1);
	list.insert_head(2);
	list.insert_head(4);
	list.insert_head(3);

	cout << list;
	
	return 0;
}
