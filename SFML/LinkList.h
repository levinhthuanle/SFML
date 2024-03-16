#pragma once

template <class T>   
class List{
	class Node
	{
		T val;
		Node* next;
	public:
		Node(T data = T(), Node* node = nullptr)
		{
			val = data;
			next = node;
		}
	};
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	~List()
	{
		while (head)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
//TODO:create function for linked list

// Implement the input linklist from file, input by hand, output into file, output to the window
// the delete linklist function, and other function if needed.