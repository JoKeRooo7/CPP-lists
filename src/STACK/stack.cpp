#include "stack.hpp"

template <typename T>
Stack<T>::Stack() {
    a = nullptr;
}

template <typename T>
Stack<T>::~Stack() {
    clear_all();
}

template <typename T>
void Stack<T>::clear_all() {
    while (a != nullptr) {
        LIFO *temp = nullptr;
        temp = a;
        a = a -> next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::print_all() {
    LIFO *temp = a; 
    while (a != nullptr) {
        std::cout << "|" << std::endl;
        std::cout << " -> "<< a -> data << std::endl;
        a = a -> next; 
    }
    a = temp;
}

template <typename T>
int Stack<T>::push(T new_element) {
    int fail = 0;
    LIFO *new_lifo = new LIFO;
    if (new_lifo == nullptr) fail = 1;
    else {
        new_lifo -> data = new_element;
        new_lifo -> next = a;
        a = new_lifo;
    }

    return fail;
}

template <typename T>
T Stack<T>::pop() {
    LIFO *temp = nullptr;
    T output_data = 0;
    if (a != nullptr) {
        temp = a;
        output_data = temp -> data;
        a = a -> next;
        delete temp;
    }

    return output_data;
}

template <typename T>
T Stack<T>::top() {
    if (a != nullptr) return a -> data;
    return 0;
}

// int main() {
//     Stack<int> a;
//     for (int i = 0; i < 7 && a.push(i) == 0; i++);
//     a.print_all();
//     for (int i = 0; i < 3; i++) {
//         std::cout << a.pop() << std::endl; 
//     }
// }