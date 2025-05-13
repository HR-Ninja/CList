
# Dynamic List in C

This is a simple dynamic list implementation in C using macros. It allows you to create a list of any type and provides functions to:

- Initialize the list
- Add elements to the list
- Remove elements from the list
- Access elements in the list
- Free the memory used by the list

## How It Works

This code uses a macro `DEFINE_LIST_TYPE(T)` to create a list and functions for a specific type. You can define a list for any type (like `int`, `float`, etc.) by calling the macro.

For example, to create a list of integers, you'd do:

```c
DEFINE_LIST_TYPE(int)
```

This will generate the following functions for `int`:

- `init_int_list`: Initializes the list
- `push_int`: Adds an element to the list
- `remove_int`: Removes an element from the list
- `get_int`: Gets an element from the list
- `free_int_list`: Frees the list's memory

### Example Usage

Here's a quick example of using the dynamic list with integers:

```c
int main() {
    List_int int_list;
    init_int_list(&int_list);

    push_int(&int_list, 1);
    push_int(&int_list, 2);
    push_int(&int_list, 3);
    push_int(&int_list, 4);
    push_int(&int_list, 5);

    // Print the list
    for (int i = 0; i < int_list.size; i++) {
        printf("Int list element: %d
", get_int(&int_list, i));
    }

    printf("List capacity: %d
", int_list.capacity);

    remove_int(&int_list, 4);  // Removes the last element

    // Print the updated list
    for (int i = 0; i < int_list.size; i++) {
        printf("Int list element: %d
", get_int(&int_list, i));
    }

    printf("Updated list capacity: %d
", int_list.capacity);

    free_int_list(&int_list);  // Don't forget to free the memory!
    return 0;
}
```

### Output

```
Int list element: 1
Int list element: 2
Int list element: 3
Int list element: 4
Int list element: 5
List capacity: 8
Int list element: 1
Int list element: 2
Int list element: 3
Int list element: 4
Updated list capacity: 8
```

### Notes

- The list grows automatically if it runs out of space (it doubles its size).
- The implementation checks for valid indices when accessing or removing elements.
- Don't forget to free the list memory when you're done.

## Contributing

Feel free to open issues or submit pull requests if you have suggestions or improvements!

## License

MIT License
