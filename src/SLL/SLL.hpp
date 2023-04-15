#ifndef SLL_HPP
#define SLL_HPP

#include <iostream>

template <typename T>
class SLL {
    public:
        SLL();
        ~SLL();
        int push_forward(T new_element);
        int push_back(T new_element);
        int find_index(T element);
        void print_all();
        void clear_all();  
        T find_by_index(int required_index);
        T remove_first();
        T remove_last();
        T top_first();
        T top_last();
    private:
        typedef struct node {
            T data;
            node* next;
        } node;
        node *list;
        node *first_element;
        int index;
};

#endif  // SLL_HPP
