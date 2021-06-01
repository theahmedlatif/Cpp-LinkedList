#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	head = NULL;
	cursor = NULL;
	prev = NULL;
	tail = NULL;
}

List::~List()
{
	makeListEmpty();
}

bool List::listIsEmpty() const
{
	return (head == NULL);
}

bool List::curIsEmpty() const
{
	return (cursor == NULL);
}

void List::toFirst()
{
	cursor = head;
	prev = NULL;
}

bool List::atFirst() const
{
	return (cursor == head);
}

void List::advance()
{
	prev = cursor;
	cursor = cursor->next;
}

void List::toEnd()
{
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor->next != NULL)
		{
			advance();
		}
	}
}

bool List::atEnd() //need feedback
{
	return (cursor->next == NULL);
}

int List::listSize() const
{
	NodePointer counter;
	int size = 0;
	if(!listIsEmpty())
	{	
		counter = head;
		while(counter->next != NULL)
		{
			size++;
			counter = counter->next;			
		}
	}
	return size;
}

void List::updateData(const char &d)
{
	cursor->data = d;
}

void List::retreiveData (char &d) const
{
	d = cursor->data;
}
	
void List::insertFirst (const int &k, const char &d)
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data = d;
	pnew->next = head;
	head = pnew;
	cursor = head;
	prev = NULL;
}

void List::insertAfter (const int &k, const char &d)
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data = d;
	pnew->next = cursor->next;
	cursor->next = pnew;
}

void List::insertBefore (const int &k, const char &d) //need feedback
{
	NodePointer pnew;
	pnew = new node;
	pnew->key = k;
	pnew->data = d;
	pnew->next = cursor;
	prev = pnew;	
}

void List::insertEnd (const int &k, const char &d)
{
	if(listIsEmpty())
	{
		insertFirst(k, d);
	}
	else
	{
		toEnd();
		insertAfter(k, d);
	}
//	NodePointer pnew;
//	pnew = new node;
//	pnew->key = k;
//	pnew->data = d;
//	toEnd();
//	cursor->next = pnew;
//	prev = cursor;
//	cursor = pnew;
}

void List::deleteNode()
{
	NodePointer ptemp;

	if (!curIsEmpty())
	{
		if (atFirst())
		{
			ptemp = cursor;
			cursor = cursor->next;
			head = cursor;
			delete ptemp;
		}
		else
		{
			ptemp = cursor;
			cursor = cursor->next;
			prev->next = cursor;
			delete ptemp;
		}
	}
}

void List::deleteFirst()
{
	if(!listIsEmpty())
	{
		toFirst();
		deleteNode();		
	}
}

void List::deleteEnd()
{
	if(!listIsEmpty())
	{
		toEnd();
		deleteNode();		
	}
}

void List::makeListEmpty() //need feedback
{
	while(!listIsEmpty())
	{
		deleteFirst();
	}
	
//	toFirst();
//	while(!listIsEmpty())
//	{
//		deleteNode();
//	}
	
}

bool List::search(const int &k) //need feedback
{	
	if(!listIsEmpty())
	{
		toFirst();
		while(cursor != NULL)
		{
			if(k == cursor->key)
				return true;
			else
				advance();
		}
		return false;
	}
}

void List::orderInsert(const int &k, const char &d) //need feedback
{	
	if(listIsEmpty())
	{
		insertFirst(k, d);
	}
	else
	{
		toFirst();
		while((k > cursor->key) && (cursor->next != NULL))
			advance();
		insertBefore(k, d);	
	}
}

void List::traverse()
{
	toFirst();
	while(!curIsEmpty())
	{
		cout << "key: " << cursor->key << " || " << "data: " << cursor->data << endl;
		advance();
	}
}

//practice
void List::fun1(NodePointer testp)
{
	if (testp == NULL)
		return;
	fun1(testp->next);
	cout << testp->data;
}

void List::fun2(NodePointer testp)
{
	if (testp == NULL)
		return;
	cout << testp->data;
	if (testp->next != NULL)
		fun2(testp->next->next);
	cout << testp->data;
}


void List::callFun1()
{
	cout << "head: " << head->data << endl;
	fun1(head);
}

void List::callFun2()
{
	cout << "head: " << head->data << endl;
	fun2(head);
}


