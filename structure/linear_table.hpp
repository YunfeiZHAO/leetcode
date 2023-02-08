// Declaration of linear table data structure

#ifndef __LT_H__
#define __LT_H__

#include <iostream>

using namespace std;

/**************
 * Linked List*
 **************/

// Node class to represent a node of the linked list.
template <class T>
class ListNode {
    public:
        T val;
        ListNode* next;

        // Default constructor
        ListNode() {
            val = nullptr;
            next = nullptr;
        }
    
        // Parameterised Constructor
        ListNode(T val) {
            this->val = val;
            this->next = nullptr;
        }

        // Function to print the linked list.
        friend ostream& operator<<(ostream& os, ListNode<T>* n) {
            while(n != nullptr) {
                os << n->val << ' ';
                n = n->next;
            }
            return os;
        }
    
};
  
// Linked list class to implement a linked list.
template <class T>
class Linkedlist {
    ListNode<T>* head;
    public:
        // Default constructor
        Linkedlist() { head = nullptr; }

        // get the head
        ListNode<T>* get_head();
    
        // Function to insert a node at the end of the linked list.
        void append(T);

        // Function to get the length of the linked list.
        int len();

        //initialise with an array
        void add_array(T a[], int size);
    
        // Function to print the linked list.
        friend ostream& operator<<(ostream& os, Linkedlist<T>& l) {
            ListNode<T> *pointer = l.head;
            while(pointer != nullptr) {
                os << pointer->val << ' ';
                pointer = pointer->next;
            }
            return os;
        }

        // Function to delete the node at given position
        void deleteNode(int);
};

#include "linear_table.tpp"

#endif // !__SINGLELIST_H__