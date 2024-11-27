#include "LinkedList.h"

template<typename T>
struct Node {
	T value;
	std::shared_ptr<Node> nextPtr;

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
	}

	void addBack(T newElement) {
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			std::shared_ptr<Node<T>> tempNode = this->head;
			while (tempNode->nextPtr != nullptr) {
				tempNode = tempNode->nextPtr;
			}
			tempNode->nextPtr = newNode;
		}
	}

	void addFront(T newElement) {
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			std::shared_ptr<Node<T>> tempNode = this->head;
			this->head = newNode;

			this->head->nextPtr = tempNode;

		}
	}

	void popFront() {
		if (this->head == nullptr)
		{
			return;
		}
		if (this->head->nextPtr == nullptr) {
			this->head = nullptr;
			return;
		}

		std::shared_ptr<Node<T>> tempNode = this->head;
		this->head = tempNode->nextPtr;
	}
	void popBack() {
		if (this->head == nullptr)
		{
			return;
		}
		if (this->head->nextPtr == nullptr) {
			this->head = nullptr;
			return;
		}

		std::shared_ptr<Node<T>> tempNode = this->head;
		while (tempNode->nextPtr->nextPtr != nullptr) {
			tempNode = tempNode->nextPtr;
		}

		tempNode->nextPtr = nullptr;
	}

	void display() {
		if (this->head == nullptr)
		{
			return;
		}

		std::shared_ptr<Node<T>> currNode = this->head;
		while (currNode->nextPtr != nullptr)
		{
			std::cout << currNode->value << ' ';
			currNode = currNode->nextPtr;
		}

		std::cout << currNode->value << '\n';
	}
private:
	std::shared_ptr<Node<T>> head;
};

int main()
{
	LinkedList<int> list;

	list.addBack(1);
	list.addBack(2);
	list.addBack(15);

	list.addFront(10);
	list.addFront(2);
	list.addFront(0);

	list.popFront();
	list.popBack();

	/*
	// Example with another type because our LinkedList is generic.

	list.addBack('u');
	list.addBack('0');
	list.addBack('i');

	list.addFront('c');
	list.addFront('w');
	list.addFront('1');
	*/

	list.display();

	return 0;
}