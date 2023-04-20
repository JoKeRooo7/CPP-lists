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
    first_element = nullptr;
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
    if (new_node != nullptr) {
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
    if (new_node != nullptr) {
        new_node -> next = list;
        new_node -> last = nullptr;
        new_node -> data = new_element;
        if (list != nullptr) list-> last = new_node; 
        list = new_node;
        index++;
        if (index == 1) first_element = list;
    } else {
        fail = 1;
    }

    return fail;
}

template <typename T>
int DLL<T>::insert_before_element(T before_element, T new_element) {
    return insert_elfunctions(before_element, new_element, 0);
}

template <typename T>
int DLL<T>::insert_after_element(T after_element, T new_element) {
    return insert_elfunctions(after_element, new_element, 1);
}

template <typename T>
int DLL<T>::insert_before_index(int find_index, T new_element) {
    return insert_infunctions(find_index, new_element, 0);
} 

template <typename T>
int DLL<T>::insert_after_index(int find_index, T new_element) {
    return insert_infunctions(find_index, new_element, 1);
}

template <typename T>
int DLL<T>::find_index(T element) {
    int temp_index = index;
    node *temp = list;
    while (temp != nullptr && index > 0) {
        if (temp -> data == element) break;
        temp = temp -> next;
        temp_index--;
    }

    return temp_index;
}


template <typename T>
T DLL<T>::find_by_index(int required_index) {
    T var = 0;
    if (required_index < index && required_index > 0 && index != 0) {
        int temp_index = 0;
        node *temp = nullptr;
        parcer_find_by_index(&temp, temp_index, required_index);
        var = temp -> data;
    }

    return var;
}

template <typename T>
T DLL<T>::remove_by_index(int find_index) {
    T var = 0;
    if (find_index < index && find_index > 0 && index != 0) {
        int temp_index = 0;
        node *temp = nullptr;
        parcer_find_by_index(&temp, temp_index, find_index);
        var = temp -> data;
        node *temp2 = temp;
        parcer_remove_element(&temp2, &temp);
        delete temp2;
        index--;
    }

    return var;
}

template <typename T>
T DLL<T>::remove_element(T element) {
    T var = 0;
    node *temp = list;
    while (temp != nullptr && temp -> data != element) temp = temp -> next;
    if (temp != nullptr) {
        node *temp2 = temp;
        var = temp -> data;
        parcer_remove_element(&temp2, &temp);
        delete temp2;
        index--;
    }
    return var;
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
    if (index == 0) list = nullptr;

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
        if (list != nullptr) list -> last = nullptr;
    }
    if (index == 0) first_element = nullptr;

    return var;
}

template <typename T>
T DLL<T>::top_first() {
    if (first_element != nullptr) return first_element -> data;
    return 0;
}

template <typename T>
T DLL<T>::top_last() {
    if (list != nullptr) return list -> data;
    return 0;
}

template <typename T>
int DLL<T>::top_index() {
    return index;
}

template <typename T>
int DLL<T>::insert_elfunctions(T check_element, T new_element , unsigned int mode) {
    int fail = 0;
    node *temp = list;
    if (first_element != nullptr && first_element -> data == check_element) {
        temp = first_element;
    } else {
        while (temp != nullptr && temp -> data != check_element) temp = temp -> next;
    }
    if (temp != nullptr) {
        node *new_temp = nullptr;
        new_temp = new node;
        if (new_temp != nullptr) {
            new_temp -> data = new_element;
            if (mode == 0) {
                insert_mode_0(&new_temp, &temp);
            } else if (mode == 1) {
                insert_mode_1(&new_temp, &temp);
            }
            index++;
        } else {
            fail = 1;
        }
    } else {
        fail = 2;
    }
    return fail;
}

template <typename T>
int DLL<T>::insert_infunctions(int find_index, T new_element, unsigned int mode) {
    int fail = 0;
    if (find_index <= 0) {
        fail = 2;
    } else if (find_index > index) {
        fail = 2;
    } else if  (index == 0) {
        fail = 2;
    } else {
        int temp_index = 0;
        node *temp = nullptr;
        node *new_temp = nullptr;
        new_temp = new node;
        if (new_temp != nullptr) {
            new_temp -> data = new_element;
                parcer_find_by_index(&temp, temp_index, find_index);
            if (mode == 0) {
                insert_mode_0(&new_temp, &temp);
            } else if (mode == 1) {
                insert_mode_1(&new_temp, &temp);
            }
            index++;
        } else {
            fail = 1;
        }
    }
    return fail;
}

template <typename T>
void DLL<T>::parcer_find_by_index(node **temp, int temp_index, int required_index) {
    if (required_index > index/2) {
        *temp = list;
        temp_index = index;
        while (temp_index != required_index) {
            temp_index--;
            *temp = (*temp) -> next;
        }
    } else {
        *temp = first_element;
        temp_index = 1;
        while (temp_index != required_index) {
            temp_index++;
            *temp = (*temp) -> last;
        }
    }
}

template <typename T>
void DLL<T>::parcer_remove_element(DLL<T>::node **temp2, DLL<T>::node **temp) {
    if ((*temp) -> next != nullptr) { 
        *temp = (*temp) -> next;
        (*temp) -> last = (*temp2) -> last;
        if ((*temp) -> next == nullptr) first_element = *temp;
    } else {
        first_element = *temp2;
    }
    if ((*temp) -> last != nullptr) {
        *temp = (*temp) -> last;
        (*temp) -> next = (*temp2) -> next;
        if ((*temp) -> last == nullptr) list = *temp;
    } else {
        list = *temp2;
    }
}

template <typename T>
void DLL<T>::insert_mode_0(DLL<T>::node **new_temp, DLL<T>::node **temp) {
    (*new_temp) -> next = (*temp);
    if ((*temp) -> last != nullptr) {
        *temp = (*temp) -> last;
        (*temp) -> next = (*new_temp);
        (*new_temp) -> last = *temp;
    } else {
        (*new_temp) -> last = nullptr;
        list = *new_temp;
    }
    if ((*new_temp) -> next != nullptr)  {
        *temp = (*new_temp) -> next;
        (*temp) -> last = (*new_temp);
    } else {
        first_element = (*new_temp);
    }
}

template <typename T>
void DLL<T>::insert_mode_1(DLL<T>::node **new_temp, DLL<T>::node **temp) {
    (*new_temp) -> last = (*temp);
    if ((*temp) -> next != nullptr) {
        *temp = (*temp) -> next;
        (*temp) -> last = (*new_temp);
        (*new_temp) -> next = (*temp);
    } else {
        (*new_temp) -> next = nullptr;
        first_element = (*new_temp);
    }
    if ((*new_temp) -> last != nullptr)  {
        *temp = (*new_temp) -> last;
        (*temp) -> next = (*new_temp);
    } else {
        list = (*new_temp);
    }
}
