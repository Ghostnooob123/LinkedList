#ifndef DYN_LINKED_LIST_H
#define DYN_LINKED_LIST_H

#include <iostream>

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
class DynLinkedList {
public:
	DynLinkedList() {
		this->head = nullptr;
	}
	~DynLinkedList() {
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
#endif //DYN_LINKED_LIST_H