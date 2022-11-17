#include "linear_table.hpp"


int main() {
    Linkedlist<char> l = * new Linkedlist<char>();
    char value[] = "toaot";
    l.add_array(value, sizeof(value));
    

    // l.append(1);
    // l.append(2);
    // l.append(3);
    // l.deleteNode(10);
    cout << "Content: " << l << '\n';
    // cout << "Len: " << l.len() << '\n';
}