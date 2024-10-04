#include <iostream>
#include <ostream>

using namespace std;

template <typename T>
class myList {	
	struct Node {
		Node(T x, Node *ptr=NULL):data(x), next(ptr) { }
		T data;
		Node *next;
	};

public:
	class iterator {
	public:
		iterator(Node *ptr=NULL):pos(ptr) {  }
		
		iterator &operator++(int)
		{
			if (NULL != pos) {
				pos = pos->next;
			}
			
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

	void insert_head(T data)
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

	template <typename X>
	friend ostream &operator<<(ostream &out, const myList<X> &list);

private:
	Node *head;
};

template <typename X>
ostream &operator<<(ostream &out, const myList<X> &list)
{
	typename myList<X>::Node *tem = list.head;
	
	while (tem) {
		out<< tem->data <<',';
		tem = tem->next;
	}
	out << endl;

	return out;
}

int main(void)
{
	myList<int> list;

	list.insert_head(1);
	list.insert_head(2);
	list.insert_head(4);
	list.insert_head(3);

	cout << list;

	myList<int>::iterator i = list.begin();
	while (i != list.end()) {
		cout << *i <<endl;
		i++;
	}

	return 0;
}
