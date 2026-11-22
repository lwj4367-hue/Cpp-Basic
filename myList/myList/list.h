#pragma once
#include<iostream>
using namespace std;
#include<assert.h>


namespace jiao {
	template<class T>
	struct list_Node {
		T _data;
		list_Node* _next;
		list_Node* _prev;
		
		list_Node(const T& data = T())
			:_data(data)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};
	template<class T>
	struct list_iterator {
		typedef list_Node<T> Node;
		typedef list_iterator<T> self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{ }

		T& operator*()
		{
			return _node->_data;
		}

		self& operator++()
		{
			_node = _node->_next;
				return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator!=(const self& s) const
		{
			return _node != s._node;
		}
		bool operator==(const self& s) const
		{
			return _node == s._node;
		}

	};

	template<class T>
	class list {
		typedef list_Node<T> Node;
	public:
		typedef list_iterator<T> iterator;
		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}
		list()//构造函数
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;

			++_size;
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			Node* newnode = new Node(x);

			// prev newnode cur
			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			++_size;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void erase(iterator pos)
		{
			assert(pos != end());

			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;
			delete pos._node;

			--_size;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}

	private:
		Node* _head;//哨兵位，头节点
		size_t _size;//链表长度
	};


void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
}


