#include "LinkedList.h"

template<typename T>
struct Node {
	T value;
	Node* nextPtr;

	Node(T newValue) {
		this->value = newValue;
		this->nextPtr = nullptr;
	}
};

template<typename T>
class LinkedList {
public:
	LinkedList() {
		this->head = nullptr;
	}
	~LinkedList() {
		Node<T>* currNode = this->head;

		while (currNode->nextPtr != nullptr)
		{
			Node<T>* tempNode = currNode->nextPtr;
			delete currNode;
			currNode = tempNode;
		}
	}

	void addFront(T newElement) {
		Node<T>* newNode = new Node<T>(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			Node<T>* tempNode = this->head;
			while (tempNode->nextPtr != nullptr) {
				tempNode = tempNode->nextPtr;
			}
			tempNode->nextPtr = newNode;
		}
	}

	void addBack(T newElement) {
		Node<T>* newNode = new Node<T>(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			Node<T>* tempNode = this->head;
			this->head = newNode;

			this->head->nextPtr = tempNode;
		}
	}

	void display() {
		Node<T>* currNode = this->head;

		while (currNode->nextPtr != nullptr)
		{
			std::cout << currNode->value << '\n';
			currNode = currNode->nextPtr;
		}

		std::cout << currNode->value << '\n';
	}
private:
	Node<T>* head;
};

int main()
{
	LinkedList<int> list;

	list.addFront(1);
	list.addFront(2);
	list.addFront(15);

	list.addBack(10);
	list.addBack(2);
	list.addBack(0);

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