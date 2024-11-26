#include "LinkedList.h"

struct Node {
	int value;
	Node* nextPtr;

	Node(int newValue) {
		this->value = newValue;
		this->nextPtr = nullptr;
	}
};

class LinkedList {
public:
	LinkedList() {
		this->head = nullptr;
	}
	~LinkedList() {
		Node* currNode = this->head;

		while (currNode->nextPtr != nullptr)
		{
			Node* tempNode = currNode->nextPtr;
			delete currNode;
			currNode = tempNode;
		}
	}

	void addFront(int newElement) {
		Node* newNode = new Node(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			Node* tempNode = this->head;
			while (tempNode->nextPtr != nullptr) {
				tempNode = tempNode->nextPtr;
			}
			tempNode->nextPtr = newNode;
		}
	}

	void addBack(int newElement) {
		Node* newNode = new Node(newElement);

		if (this->head == nullptr)
		{
			this->head = newNode;
		}
		else
		{
			Node* tempNode = this->head;
			this->head = newNode;

			this->head->nextPtr = tempNode;
		}
	}

	void display() {
		Node* currNode = this->head;

		while (currNode->nextPtr != nullptr)
		{
			std::cout << currNode->value << '\n';
			currNode = currNode->nextPtr;
		}

		std::cout << currNode->value << '\n';
	}
private:
	Node* head;
};

int main()
{
	LinkedList list;

	list.addFront(1);
	list.addFront(2);
	list.addFront(15);

	list.addBack(10);
	list.addBack(2);
	list.addBack(0);

	list.display();

	return 0;
}