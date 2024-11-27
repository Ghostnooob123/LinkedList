#ifndef RAW_LINKED_LIST_H
#define RAW_LINKED_LIST_H

#include <iostream>

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
class RawLinkedList {
public:
	RawLinkedList() {
		this->head = nullptr;
	}
	~RawLinkedList() {
		if (this->head == nullptr)
		{
			delete this->head;
			this->head = nullptr;
			return;
		}

		Node<T>* currNode = this->head;
		while (currNode->nextPtr != nullptr)
		{
			Node<T>* tempNode = currNode->nextPtr;
			delete currNode;
			currNode = tempNode;
		}
		currNode = nullptr;
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

	void popFront() {
		if (this->head == nullptr)
		{
			return;
		}
		if (this->head->nextPtr == nullptr) {
			delete this->head;
			this->head = nullptr;
			return;
		}

		Node<T>* tempNode = this->head;
		this->head = tempNode->nextPtr;
	}
	void popBack() {
		if (this->head == nullptr)
		{
			return;
		}
		if (this->head->nextPtr == nullptr) {
			delete this->head;
			this->head = nullptr;
			return;
		}

		Node<T>* tempNode = this->head;
		while (tempNode->nextPtr->nextPtr != nullptr) {
			tempNode = tempNode->nextPtr;
		}

		delete tempNode->nextPtr;
		tempNode->nextPtr = nullptr;
	}

	void display() {
		if (this->head == nullptr)
		{
			return;
		}

		Node<T>* currNode = this->head;
		while (currNode->nextPtr != nullptr)
		{
			std::cout << currNode->value << ' ';
			currNode = currNode->nextPtr;
		}

		std::cout << currNode->value << '\n';
	}
private:
	Node<T>* head;
};
#endif // !RAW_LINKED_LIST_H