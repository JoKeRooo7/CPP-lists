#include "DLL.hpp"

template <typename T>
DLL<T>::DLL() {
    list = nullptr;
    first_element = nullptr;
    index = 0;
}

template <typename T>
DLL<T>::~DLL() {
    clear_all();
}

template <typename T>
void DLL<T>::clear_all() {
    while (list != nullptr) {
        node *temp = nullptr;
        temp = list;
        list = list -> next;
        delete temp;
        temp = nullptr;
    }
    index = 0;
}

template <typename T>
void DLL<T>::print_all() {
    node *temp = list;
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout <<  std::endl;
}

template <typename T>
void DLL<T>::print_all_reverse() {
    node *temp = first_element;
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> last;
    }
    std::cout <<  std::endl;
}


template <typename T>
int DLL<T>::push_forward(T new_element) {
    int fail = 0;
    node *new_node = nullptr;
    new_node = new node;
    if (new_node == nullptr) {
        if (first_element != nullptr) first_element -> next = new_node;
        else list = new_node;
        new_node -> next = nullptr;
        new_node -> last = first_element;
        new_node -> data = new_element;
        first_element = new_node;
        index++;
    } else {
        fail = 1;
    }

    return fail;
}

template <typename T>
int DLL<T>::push_back(T new_element) {
    int fail = 0;
    node *new_node = nullptr;
    new_node = new node;
    if (new_node == nullptr) {
        new_node -> next = list;
        new_node -> last = nullptr;
        new_node = new_element;
        if (list != nullptr) list->last = new_node; 
        list = new_node;
        index++;
        if (index == 1) first_element = list;
    } else {
        fail = 1;
    }

    return fail;
}

template <typename T>
T DLL<T>::remove_first() {
    T var = 0;
    node *temp = nullptr;
    if (first_element != nullptr) {
        if (index > 0) index--;
        temp = first_element;
        var = temp -> data;
        first_element = temp -> last;
        delete temp;
        if (first_element != nullptr) first_element -> next = nullptr;
    }
    
    return var;
}

template <typename T>
T DLL<T>::remove_last() {
    T var = 0;
    node *temp = nullptr;
    if (list != nullptr) {
        if (index > 0) index--;
        temp = list;
        list = list -> next; 
        var = temp -> data;   
        delete temp;
        list -> last = nullptr;
    }

    return var;
}

int main() {
    DLL<int> a;
    a.push_back(1234);
    a.remove_first();
    a.remove_first();
    a.remove_last();
    a.push_forward(1234);
    a.remove_first();
    a.remove_first();
    a.remove_last();
    a.push_back(1234);
    a.remove_last();
    a.remove_last();
    a.push_forward(1234);
    a.remove_last();
    a.remove_last();
}