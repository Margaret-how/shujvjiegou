#include<iostream>
using namespace std;
template<typename E>
class Node
{
public:
	E data;
	Node*next;
	Node() { next = NULL; }
};
template<typename E>
class Llist :Node<E>
{
private:
	Node<E>*head;
	Node<E>*tail;
public:
	Llist()
	{
		head =tail= NULL;
	}
	void insert0(E i)
	{
		if (head == NULL)
		{
			head = new Node<E>;
			head->data = i;
			tail = head;
		}
		else { 
			Node<E>*temp=new Node<E>;
			temp->data = i;
			tail->next = temp;
			tail = temp;
		}
		
	}
	int size0()
	{
		int size=0;
		Node<E>*temp = new Node<E>;
		temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			size++;
		}
		return size;
	}

};
template<typename E>
class Hash:Llist<E>
{
private:
	Llist<E> *hash;
	int length;
public:
	Hash(int size=0)
	{
		length = size;
		hash = new Llist<E>[size];
	}
	void insert(E i)
	{
		int pos = i % length;

		hash[pos].insert0(i);

		
	}
	int size(int k)
	{
		Llist<E>list0 = hash[k];
		return list0.size0();
	}
};
int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int n, m, k,t;
		cin >> n >> m >> k;
		Hash<int>hash(m);
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			hash.insert(t);
		}
		cout << hash.size(k) << endl;
	}
	
}