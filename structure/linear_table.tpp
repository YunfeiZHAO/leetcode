// get head
template <typename T>
Node<T>* Linkedlist<T>::get_head() {
    return this->head;
}

// append
template <typename T>
void Linkedlist<T>::append(T value) {
    // create new node
    Node<T> *new_node = new Node<T>(value);
    Node<T> *pointer = this->head;
    // Assign to head if there is no element
    if(pointer == nullptr) {
        this->head = new_node;
        return;
    }
    
    while(pointer->next != nullptr) {
        pointer = pointer->next;
    }
    pointer->next = new_node;
    return;
}

//len
template <typename T>
int Linkedlist<T>::len() {
    int len = 0;
    Node<T> *pointer = this->head;
    while(pointer != nullptr) {
        len += 1;
        pointer = pointer->next;
    }
    return len;
}


template <typename T>
void Linkedlist<T>::deleteNode(int index) {
    int length = this->len();
    if(length == 0) {
        cout << "No element!\n";
        return; 
    }

    if(index < 0 || index >= length) {
        cout << "Index out of range\n";
        return;
    }

    if(index == 0) {
        this->head = this->head->next;
        return;
    }

    Node<T> *pointer = this->head;
    Node<T> *prev_pointer = pointer;

    pointer = pointer->next;
    index--;

    while(index != 0) {
        prev_pointer = pointer;
        pointer = pointer->next;
        index--;
    }
    prev_pointer->next = pointer->next;
    return;
}

// add array
template <typename T>
void Linkedlist<T>::add_array(T a[], int size) {
    for(int i=0; i<size; i++) {
        this->append(a[i]);
    }
}