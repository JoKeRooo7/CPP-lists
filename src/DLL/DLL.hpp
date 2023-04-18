#ifndef DLL_HPP
#define DLL_HPP

#include <iostream>

template <typename T>
class DLL {
    public:
        DLL();
        ~DLL();
        void clear_all();
        void print_all();
        void print_all_reverse();
        int push_forward(T new_element);
        int push_back(T new_element);
        int insert_before_element(T new_element);
        int insert_after_element(T new_element);
        int insert_before_index(int index);
        int insert_after_index(int index);
        int find_index(T element);
        T find_by_index(int required_index);
        T remove_first();
        T remove_last();
        T top_first();
        T top_last();
    private:
        typedef struct node
        {
            T data;
            node* next;
            node* last;
        }node;
    node *list;
    node *first_element;
    int index;
};

#endif  // DLL_HPP