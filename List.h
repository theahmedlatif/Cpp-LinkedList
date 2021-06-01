#ifndef MyLinkedList_H
#define MyLinkedList_H

class List
{
	private:
		class node
		{
			public:
				int key;
				char data;
				node* next;
		};
		
		typedef node * NodePointer;
		
		NodePointer head, cursor, prev, tail;
		//practice
		void fun1(NodePointer);
		void fun2(NodePointer);
		
	public:
		//construct empty list
		List();
		//list destructor
		~List();
		
		//functions prototype
		bool listIsEmpty() const;
		bool curIsEmpty() const;
		void toFirst();
		bool atFirst() const;
		void advance();
		void toEnd();
		bool atEnd();
		int listSize() const;
		void updateData(const char &);
		void retreiveData (char &) const;
		void insertFirst (const int &, const char &);
		void insertAfter (const int &, const char &);
		void insertBefore (const int &, const char &);
		void insertEnd (const int &, const char &);
		void deleteNode();
		void deleteFirst();
		void deleteEnd();
		void makeListEmpty();
		bool search(const int &);
		void orderInsert(const int &, const char &);
		void traverse();
		
		//practice
		void callFun1();
		void callFun2();
};

#endif


