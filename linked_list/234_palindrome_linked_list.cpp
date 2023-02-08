#include "../structure/linear_table.hpp"


bool isPalindrome1(Node<int>* head) {
    int length = 0;
    int middle;
    int verify_length;
    Node<int> *pointer = head;
    Node<int> *mp = head;
    // get the length of the linked list
    while(pointer != nullptr) {
        length++;
        pointer = pointer->next;
    }
    if(length == 1) {return true;}

    // get a pointer point to the right side of middle of the linked list
    middle = (length+1)/2;
    for(int i=0; i<middle; i++) {
        mp = mp->next;
    }
    // reverse the list from the middle pointer to the end
    Node<int> *mp_next = mp->next, *mp_next_next;
    mp->next = nullptr;

    while(mp_next != nullptr) {
        mp_next_next = mp_next->next;
        mp_next->next = mp;
        mp = mp_next;
        mp_next = mp_next_next;
    }

    // compare two sub linked list
    pointer = head;
    for(int i=0; i<length/2; i++) {
        if(pointer->val != mp->val) {
            return false;
        }
        pointer = pointer->next;
        mp = mp->next;
    }
    return true;
}


void pal(Node<int>*& head, Node<int>* tail, int& c){
    if(!tail->next){
        return;
    }
    tail=tail->next;
    pal(head,tail,c);
    if(head->val!=tail->val){
        c++;
    }
    head=head->next;
}

bool isPalindrome2(Node<int>* head) {
    Node<int>* tail=head;
    int c=0;
    pal(head,tail,c);
    return !c;
}



int main() {
    Linkedlist<int> l = * new Linkedlist<int>();
    int value[] = {1, 2, 3, 4, 5, 3, 2, 1};
    // int value[] = {1};
    l.add_array(value, sizeof(value)/sizeof(int));
    Node<int>* head = l.get_head();
    cout << "Content: " << l << "\n";

    bool r = isPalindrome2(head);
    cout << "Is Palindrome: " << r << "\n";
 
}