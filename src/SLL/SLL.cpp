#include "SLL.hpp"

template <typename T>
SLL<T>::SLL() {
    first_element = nullptr;
    list = nullptr;
    index = 0;
}

template <typename T>
SLL<T>::~SLL() {
    clear_all();
}

template <typename T>
int SLL<T>::push_forward(T new_element) {
    int fail = 0;
    node *new_list = nullptr;
    new_list = new node;
    if (new_list != nullptr) {
        node *temp = list;
        if (temp != nullptr) {
            while (temp -> next != nullptr) {
                temp = temp -> next;
            } 
            temp -> next = new_list;
            new_list -> data = new_element;
            new_list -> next = nullptr;
            first_element = new_list;
            index++;
        } else {
            list = new_list;
            list -> next = nullptr;
            list -> data = new_element;
            index++;
        }
    } else {
        fail = 1;
    }

    return fail;
}

template <typename T>
int SLL<T>::push_back(T new_element) {
    int fail = 0;
    node *new_list = nullptr;
    new_list = new node;
    if (new_list != nullptr) {
        new_list -> data = new_element;
        new_list -> next = list;
        list = new_list;
        index++;
        if (index == 1) {
            first_element = list;
        }
    } else {
        fail = 1;
    }

    return fail;
}

template <typename T>
int SLL<T>::find_index(T element) {
    int temp_index = index;
    node *temp = list;
    while (temp_index != 0) {
        if (temp -> data == element) break;
        temp = temp -> next; 
        temp_index--;
    }
    
    return temp_index;
}

template <typename T>
void SLL<T>::print_all() {
    node *temp = list;
    while (temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

template <typename T>
void SLL<T>::clear_all() {
    while (list != nullptr) {
        node *temp = nullptr;
        temp = list;
        list = list -> next;
        delete temp;
        temp = nullptr;
    }
    first_element = nullptr;
    index = 0;
}

template <typename T>
T SLL<T>::find_by_index(int required_index) {
    T output_data = 0;
    int temp_index = index;
    node *temp = list;
    while (temp_index != required_index && temp_index > 0) {
        temp = temp -> next;
        temp_index--;
    }
    if (temp != nullptr) output_data = temp -> data;

    return output_data;
}

template <typename T>
T SLL<T>::remove_first() { // if index 1
    T var = 0;
    node *temp = list;
    int temp_index = index;
    while (temp_index > 1) {
        if (temp_index == 2) first_element = temp;
        temp = temp -> next;
        temp_index--;
    }
    if (temp != nullptr) {
        var = temp -> data;
        delete temp;
        if (index > 0) index--;
        if (index == 0) {
            first_element = nullptr;
            list = nullptr;
        } else {
            first_element -> next = nullptr;
        }
    }
    return var;
}

template <typename T>
T SLL<T>::remove_last() {
    node *temp = nullptr;
    T output_data = 0;
    if (list != nullptr) {
        temp = list;
        output_data = temp -> data;
        list = list -> next;
        delete temp;
        if (index > 0) index--;
    }
    if (index == 0) first_element = nullptr;

    return output_data;
}
template <typename T>
T SLL<T>::top_first() {
    if (first_element != nullptr) return first_element -> data;
    return 0;
}
template <typename T>
T SLL<T>::top_last() {
    if (list != nullptr) return list -> data;
    return  0;
}

// int main () {
//     SLL<float> a;
//     a.push_back(123.3);
//     a.push_back(7.3);
//     a.push_forward(-32.2);
//     a.print_all();
//     std::cout << a.top_first() << " " << a.top_last() << std::endl;
//     a.remove_last();
//     a.push_back(123.4);
//     a.remove_first();
//     a.print_all();
//     a.remove_first();
//     a.print_all();
//     a.push_back(98);
//     a.print_all();
//     a.push_forward(89);
//     a.print_all();
//     a.remove_first();
//     a.print_all();
//     a.remove_first();
//     a.print_all();
//     a.remove_first();
//     a.print_all();
//     a.remove_first();
//     a.print_all();
//     std::cout << a.find_index(89) << std::endl;
//     std::cout << a.find_by_index(2) << std::endl;
//     std::cout << a.top_first() << " " << a.top_last() << std::endl;
// }
 