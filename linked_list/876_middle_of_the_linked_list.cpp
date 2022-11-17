#include "../structure/linear_table.hpp"

// find middle by lenght
Node<int>* middleNode1(Node<int>* head) {
    int length = 0, middle;
    Node<int> *pointer = head;
    while(pointer != nullptr) {
        length++;
        pointer = pointer->next;
    }
    middle = length/2;
    pointer = head;
    while(middle > 0) {
        pointer = pointer->next;
        middle--;
    }
    return pointer;
}

// slow and fast, 2 time faster
Node<int>* middleNode2(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;
    while(fast!=nullptr && fast->next !=nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Linkedlist<int> l = * new Linkedlist<int>();
    int value[] = {1, 2, 3, 4, 5, 6};
    l.add_array(value, sizeof(value)/sizeof(int));
    // l.append(1);
    // l.append(2);

    Node<int>* head = l.get_head();
    Node<int>* middle = middleNode2(head);

    cout << "Content: " << l << "\n";
    cout << "Middle: " << middle << "\n";

    // cout << "Size: " << sizeof(value)/sizeof(int);
    
 
}

