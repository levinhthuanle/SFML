#pragma once
// Creating a stack for dynamic memory.
// Temporarily puting all information in public "mode" for easy code and access.
// Must improve the code for least accessing.
template <class T>   
class Stack{
public:
	class ListNode
	{
	public:	
		T val;
		ListNode* next;
		ListNode(T data = T(), ListNode* node = nullptr)
		{
			val = data;
			next = node;
		}
	};
	ListNode* head;
	Stack()
	{
		head = nullptr;
	}
	void push(T val)
	{
		ListNode* temp = new ListNode(val, head);
		head = temp; 
		return;	
	}
	T front ()
	{
		return head->val; 
	}
	void pop()
	{
		if (!head) return;
		ListNode* temp = head; 
		head = head->next; 
		delete temp; 
		return; 
	}
	void del()
	{
		while (head)
		{
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}
	~Stack()
	{
		this->del(); 
	}
};


// Implement the input linklist from file, input by hand, output into file, output to the window
// the delete linklist function, and other function if needed.