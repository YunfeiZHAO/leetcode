#include "../structure/linear_table.hpp"


// dummy head
ListNode<int>* mergeTwoLists1(ListNode<int>* list1, ListNode<int>* list2) {
    ListNode<int> *p1 = list1, *p2 =list2, *head=new ListNode<int>(0), *p;
    p = head;
    while(p1 && p2) {
        if(p1->val >= p2->val) {
            p->next = p2;
            p2 = p2->next;
        } else {
            p->next = p1;
            p1 = p1->next;
        }
        p = p->next;
    }
    p->next = (p1? p1:p2);
    return head->next;
}

// recursion
ListNode<int>* mergeTwoLists2(ListNode<int>* list1, ListNode<int>* list2) {
    if(!list1 || !list2) {return list1? list1:list2;}
    if(list1->val <= list2->val) {
        list1->next = mergeTwoLists2(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists2(list1, list2->next);
        return list2;
    }
}






int main() {
    Linkedlist<int> l1 = * new Linkedlist<int>();
    Linkedlist<int> l2 = * new Linkedlist<int>();

    // int value1[] = {0, 2, 3, 4, 5};
    int value1[] = {1,2,4};
    // int value1[] = {};
    l1.add_array(value1, sizeof(value1)/sizeof(int));
    ListNode<int>* head1 = l1.get_head();

    //int value2[] = {1, 3, 9, 15, 23};
    int value2[] = {1,3,4};
    // int value2[] = {0};
    //int value2[] = {};
    l2.add_array(value2, sizeof(value2)/sizeof(int));
    ListNode<int>* head2 = l2.get_head();

    cout << "Content1: " << l1 << endl;
    cout << "Content2: " << l2 << endl;


    ListNode<int>* head3 = mergeTwoLists2(head1, head2);
    cout << "Merged: " << head3 << endl;

    // ListNode<int>* head4 = new ListNode<int>(0);
    // cout << "head4: " << head4 << endl;

}