# **Lists**
I have implemented one of the buzz algorithms **STACK**, **SLL**, ...

1. [**STACK**](#**Stack**)
2. [**SLL**](#**SLL** (Singly linked list))


# **Stack**
> **Stack** is an abstract data type, which is a list of elements obeying the rule **LIFO** (last in - first out). Stack is not a singly linked list, but it can be implemented with its help. The difference is that in the stack, the removal and addition of elements occurs only at the top.An
example of such an implementation can be a stack of plates, a stack of notebooks, etc. 

</br>
In my program, it is implemented using a singly linked list in the <b>Stack</b> class:

```cpp
class Stack {...};
```
When deleting a stack class, it automatically clears the memory allocated inside it.</br>
**Stack** it is presented as a library ***libstack.a libstack.so ***.

## **Building the STACK library**

To build libraries, I use **Makefile**

> ### **Building a static library STACK**:
>___
> To build the code as a static library in ***src***, enter 
> ```sh
> make static_lib_STACK
> ```
> The static library will be placed in the directory ***libs*** with the name ***libstack.a***
> ### **Build the dynamic library STACK**:
>___
> To build the code as a dynamic library in ***src**, enter 
> ```sh
> make dynamic_lib_STACK:
> ```
> The dynamic library will be placed in the ***libs*** directory with the name ***libstack.so***


## **Application:**

1. Link the library in ways that are convenient for you.
2. Connect the library via the header file:
    ```cpp
    #include "stack.hpp"
    ```
3. Declare the stack by specifying the data type:
    ```cpp
    Stack<int> a;
    ...
    Stack<char> a;
    ...
    Stack<float> a;
    ...
    ```
4. Functionality:
```cpp
        Stack<int> a;           // stack declaration
        a.push(123);            // Adding element 123 to the top of the stack. 
        a.top();                // Returning an element from the top of the stack
        a.pop();                // Removing an element from the top of the stack
        a.print_all();          // Output of all stack elements starting from the top
        a.clear_all();          // Clearing the stack of all elements
        if (a.push(123) == 0);  // Memory is allocated
        if (a.push(123) != 0);  // No memory has been allocated, no item has been added
```

# **SLL** (Singly linked list).

> [**Linear single-linked list**](https://en.wikipedia.org/wiki/Linked_list) (*abstract data type (AD)*) is a data structure consisting of elements of the same type connected sequentially by pointers. Each list item has a pointer to the next item. The last item in the list points to ***NULL***. The element to which there is no pointer is the first (*vertex*) element of the list. Here the link in each node points to the next node in the list. In a singly linked list, you can only move towards the end of the list. It is impossible to find out the address of the previous element based on the contents of the current node.

In my program, a singly linked list is implemented using a class (class template) **SSL** (*Singly linked list*):
```cpp
    class SLL {...}
```
Declaration of a variable of type **SLL** containing `float` data:
```cpp
    SSL<float> a;
```
Add `123.33` to the end of the list:
```cpp
    a.push_back(123.33);
```
Add `7.3` to the top of the list:
```cpp
    a.push_forward(7.3);
```

* If memory is not allocated `a.push_back()` `a.push_forward()` will return one:
```cpp
    if (a.push_back(123) != 0) std::cout << "Error";
```

Find the index of the `new_element` element:
```cpp
    float new_element = 123.33;
    int index = a.fint_index(new_element);
```

Print to the standard output stream all elements of *SLL* starting from the top:
```cpp
    a.prind_all();
```

Clear all elements (calling the clear automatic function when deleting a class):
```cpp
    a.clear_all();
```

Find an element by index:
```cpp
    float b = 0;
    int index = 3;
    b = a.find_by_index(index);
```

Delete an item from the very beginning of the list:
```cpp
    a.remove_first();
```

Remove an element from the top (last) element:
```cpp
    a.remove_last();
```

Return an item (without deleting it) from the beginning of the list and from the end of the list:
```cpp
    a.top_firts();
    a.top_last();
```

## **Building the SLL Library**

> ### **Building a static SLL library**:
>___
> To build the code as a static library in ***src***, enter 
> ```sh
> make static_lib_SLL
> ```
> The static library will be placed in the directory ***libs*** with the name ***libSLL.a***
> ### **Assembly of the dynamic library SLL**:
>___
> To build the code as a dynamic library in ***src**, enter 
> ```sh
> make dynamic_lib_SLL:
> ```
> The dynamic library will be placed in the ***libs*** directory with the name ***libSLL.so***