#include <iostream>
#include <ostream>

using namespace std;

class myList{	
	struct Node {
		Node(int x, Node *ptr=NULL):data(x), next(ptr) { }
		int data;
		Node *next;
	};

public:
	class iterator {
	public:
		iterator(Node *ptr=NULL):pos(ptr) {  }
		
		iterator &operator++(int)
		{
			if(NULL != pos)
				pos = pos->next;
			return *this;
		}

		int &operator*()
		{
			return pos->data;
		}

		bool operator!=(iterator x)
		{
			return pos != x.pos;
		}
	
	private:
		Node *pos;
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

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return iterator(NULL);
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

	myList::iterator i = list.begin();
	while (i != list.end()) {
		cout << *i <<endl;
		i++;
	}
	
	return 0;
}
