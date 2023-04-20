# **Lists**
I have implemented some of the buzz algorithms **STACK**, **SLL** (sigly linked list), **DLL** (double linked list). 

1. [**STACK**](#Stack)
2. [**SLL**](#SLL)
3. [**DLL**](#DLL)


# **Stack** (stack)
> **Stack** (English stack — stack) is an abstract data type, which is a list of elements obeying the **LIFO** rule (last in - first out, last in - first out). Stack is not a singly linked list, but it can be implemented with its help. The difference is that in the stack, the removal and addition of elements occurs only at the top.</br>
> An example of such an implementation can be a stack of plates, a stack of notebooks, etc. 

</br>
In my program, it is implemented using a singly linked list in the <b>Stack</b> class:

```cpp
class Stack {...};
```

### **Building the STACK library**

Build via **Makefile**
**Stack** is going to the library ***libstack.a libstack.so*** to the ***libs*** directory.

> To build the code as a static library in the terminal (project directory ***src***), enter 
> ```sh
> make static_lib_STACK          # build a static library
> make dynamic_lib_STACK:        # build a dynamic library
> ```

### **Usage example:**

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
        Stack<int> a;            // stack declaration
        a.push(123);             // Adding element 123 to the top of the stack. 
        a.top();                 // Returning an element from the top of the stack
        a.pop();                 // Removing an element from the top of the stack
        a.print_all();           // Output of all stack elements starting from the top
        a.clear_all();           // Clearing the stack of all elements
        if (a.push(123) == 0);   // Memory is allocated
        if (a.push(123) != 0);   // No memory was allocated, no element was added
```

When deleting a stack class, it automatically clears the memory allocated inside it.</br>

# **SLL** (Singly linked list).

> [***Linear single - branched список***](https://en.wikipedia.org/wiki/Linked_list) (*abstract data type (AD)*) is a data structure consisting of elements of the same type connected sequentially by pointers. Each list item has a pointer to the next item. The last item in the list points to ***NULL***. The element to which there is no pointer is the first (*vertex*) element of the list. Here the link in each node points to the next node in the list. In a singly linked list, you can only move towards the end of the list. It is impossible to find out the address of the previous element based on the contents of the current node.

> On the basis of a singly linked list, you can implement a queue (**FIFO**), (**stack**).

In my program, a singly linked list is implemented using a class (class template) **SSL** (*Singly linked list*): `class SLL {...}`

```cpp
    #include "SLL.hpp"       // Connecting the library
...
SLL<float> a;                // Declaration of an SLL type variable containing float data
    a.push_back(123.33);     // Add to the end of the list 123.33
    a.push_forward(7.3);     // Add to the top of the list 7.3
    a.print_all();           // Output to stdout the entire list starting from the top
    a.clear_all();           // Clearing the entire list
    a.remove_first();        // Remove an item from the very beginning of the list
    a.remove_last();         // Remove an element from the top (last) element
    a.top_firts();           // Return (without deleting) the element at the beginning of the list
    a.top_last();            // Return (without removing) the element from the end (vertex) list

    // If no memory is allocated, a.push_back() or a.push_forward() will return one
    if (a.push_back(123) != 0) std::cout << "Error"; //

    // Search for the index of the new_element element in the list
    float new_element = 123.33;
    int index = a.fint_index(new_element);
    
    // Searching for an item by index:
    float b = 0;
    int index = 3;
    b = a.find_by_index(index);

```
When deleting an object of the SLL class, it is automatically cleared.</br>

### **Building the SLL Library**

Build via **Makefile**
**SLL** is going to the library ***libSLL.a libSLL.so*** to the ***libs*** directory.
> To build the code as a static library in the terminal (project directory ***src***), enter 
> ```sh
> make static_lib_SLL # build a static library
> make dynamic_lib_SLL: # build a dynamic library
> ```


# DLL (A doubly linked list).

> ***A doubly linked list*** is a structure consisting of elements of the same type, interconnected by pointers, where pointers. Where the element has a pointer to both the next element and the previous one (Two links).

On the basis of a doubly linked list, you can implement a flexible queue (**FIFO**), (**stack**).

In my program, it is represented as a class: `class DLL {...}'.

```cpp
    #include "Dll.hpp"                 // Connecting the library
...
    DLL<char> a;                       // Declaring a DLL type variable containing char elements
    a.clear_all();                     // Clearing the entire list
    a.print_all();                     // Print the entire list from the top(end)
    a.print_all_reverse();             // Print the entire list from the beginning
    
    // Adding items to the list
    a.push_forward('A');               // Add the A character to the beginning
    a.push_back('Z');                  // Add the Z character to the end
    a.insert_before_element('A', 'B'); // Add the character B before A
    a.insert_after_element('Z', 'Y');  // Add the Y character after Z
    a.insert_before_index(1, 'a');     // Add the symbol a before the first element
    a.insert_after_index(5, 'y');      // Add the y character after the 5th element

    // All these functions will return a digit other than zero if memory is not allocated
    if (a.push_back('E') != 0) std::cout << "Memory was not allocated\n";

    // Removing items from the list
    a.remove_by_index(1);              // Will remove the first element
    a.remove_element("A");             // Removes the last occurrence of element A
    a.remove_first();                  // Removes the first element(initial) from the list
    a.remove_last();                   // Removes the last item from the list

    // All these functions will return the item being deleted from the list or 0
    std::cout << a.remove_first() << std::endl;

    // Index search
    a.find_index('C');                 // Returns the index of the last occurrence of the element C
    a.find_by_index(1);                // Returns an element with index 1
    a.top_index();                     // Returns the index of the last element
    a.top_first();                     // Returns the first element
    a.top_last();                      // Returns the last element (at the top of the stack);
```
When deleting an object of the DLL class, it is automatically cleared.</br>

### **Building a DLL**

Build via **Makefile**
**DLL** is going to the library ***libDLL.a libDLL.so *** to the ***libs*** directory.
> To build the code as a static library in the terminal (project directory ***src***), enter 
> ```sh
> make static_lib_DLL                  # build a static library
> make dynamic_lib_DLL:                # build a dynamic library
> ```