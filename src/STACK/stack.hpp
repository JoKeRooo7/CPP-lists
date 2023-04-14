#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class Stack {
    public:
        Stack();
        ~Stack();
        void clear_all();
        void print_all();
        int push(T new_element);
        T pop();
        T top();
    private:
        class LIFO {
            public:
                T data;
                LIFO * next;
        };
        LIFO *a;
};

#endif  // STACK_HPP