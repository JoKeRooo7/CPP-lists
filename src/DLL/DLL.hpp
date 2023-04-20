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
        int insert_before_element(T before_element, T new_element);
        int insert_after_element(T after_element, T new_element);
        int insert_before_index(int find_index, T new_element);
        int insert_after_index(int find_index, T new_element);
        int find_index(T element);
        int top_index();
        T find_by_index(int required_index);
        T remove_by_index(int find_index);
        T remove_element(T element);
        T remove_first();
        T remove_last();
        T top_first();
        T top_last();
    private:
        typedef struct node {
            T data;
            node* next;
            node* last;
        } node;
        int insert_elfunctions(T check_element, T new_element , unsigned int mode);
        int insert_infunctions(int find_index, T new_element, unsigned int mode);
        void parcer_find_by_index(node **temp, int temp_index, int required_in0dex);
        void parcer_remove_element(node **temp2, node **temp);
        void insert_mode_0(node **new_temp, node **temp);
        void insert_mode_1(node **new_temp, node **temp);
        node *list;
        node *first_element;
        int index;
};

#endif  // DLL_HPP