#include "LinkedList.h"
//#include "RawLinkedList.h"
#include "DynLinkedList.h"

int main()
{

	// LinkedList using smart pointers from C++11
	DynLinkedList<int> list;

	list.addFront(1);
	list.addFront(2);
	list.addFront(15);

	list.addBack(10);
	list.addBack(2);
	list.addBack(0);

	list.popFront();
	list.popBack();

	// LinkedList using raw pointers
	/*
	RawLinkedList<int> list;

	list.addFront(1);
	list.addFront(2);
	list.addFront(15);

	list.addBack(10);
	list.addBack(2);
	list.addBack(0);

	list.popFront();
	list.popBack();*/

	/*
	// Example with another type because our LinkedList is generic.
	list.addFront('c');
	list.addFront('w');
	list.addFront('1');

	list.addBack('u');
	list.addBack('0');
	list.addBack('i');
	*/

	list.display();

	return 0;
}