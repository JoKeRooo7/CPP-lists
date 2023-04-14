# **Lists**
I have implemented one of the buzz algorithms **STACK**...

1. ["**STACK**"](#Stack)
2. ["**LIFO**"](#LIFO)


# **Stack **
> **Stack** is an abstract data type, which is a list of elements obeying the rule ["**LIFO**"](#LIFO) (last in - first out). Stack is not a singly linked list, but it can be implemented with its help. The difference is that in the stack, the removal and addition of elements occurs only at the top.An
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
``cpp
        Stack<int> a; // stack declaration
        a.push(123); // Adding element 123 to the top of the stack
        a.top(); // Returning an element from the top of the stack
        a.pop(); // Removing an element from the top of the stack
        a.print_all(); // Output of all stack elements starting from the top
        a.clear_all(); // Clearing the stack of all elements

    ```

# **LIFO**