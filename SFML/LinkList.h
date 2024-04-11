#pragma once
#include "Requirement.h"
// Creating a stack for dynamic memory.
// Temporarily puting all information in public "mode" for easy code and access.
// Must improve the code for least accessing.
template <typename T>
class Stack {
public:
    class ListNode {
    public:
        T val;
        ListNode* next;
        ListNode(T data = T(), ListNode* node = nullptr) : val(data), next(node) {}
    };

    ListNode* head;

    Stack() : head(nullptr) {}

    void push(const T& val) {
        ListNode* temp = new ListNode(val, head);
        head = temp;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T* top() const {
        if (head)
            return &(head->val);
        else
            return nullptr;
    }


    void pop() {
        if (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    void del() {

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