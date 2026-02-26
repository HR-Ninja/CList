# Dynamic Generic List in C

A simple **generic dynamic array (list)** implementation in C.

This version uses a single `List` struct with a raw memory buffer (`void*`) and helper macros for type-safe creation and access. It allows you to store **any type** (`int`, `float`, structs, etc.) in a dynamically resizing list.

---

## Features

- Create a list for any type
- Push elements
- Remove elements
- Access elements
- Automatic resizing (capacity doubles when full)
- Bounds checking
- Manual memory cleanup

---

## How It Works

This code uses a macro `LIST(T, SIZE)` to create a list.

For example, to create a list of integers, you'd do:

```c
List list = LIST(int, 20);
```

Adding/Removing Elements:

```c
// LIST_GET() returns a pointer
int value = *LIST_GET(&list, int, 0);

// LIST_REMOVE
LIST_REMOVE(&list, 0);
```

### Example Usage

Here's a quick example of using the dynamic list with integers:

```c
#include "list.h"

int main() {
    

    List list = LIST(int, 20);

    int value = 0;
    for (int i = 0; i < 6; i++) {
        value++;
        LIST_PUSH(&list, int, &value);
    }

    for (int i = 0; i < list.size; i++) {
        printf("Int list elements: %d\n", *LIST_GET(&list, int, i));
    }

    printf("Int list capacity: %d\n", (int)list.capacity);

    LIST_REMOVE(&list, 4);

    for (int i = 0; i < list.size; i++) {
        printf("Int list elements: %d\n", *LIST_GET(&list, int, i));
    }

    printf("Int list capacity: %d\n", (int)list.capacity);

    LIST_FREE(&list);

    return 0;
}
```

### Output

```
Int list elements: 1
Int list elements: 2
Int list elements: 3
Int list elements: 4
Int list elements: 5
Int list elements: 6
Int list capacity: 20

After removal:
Int list elements: 1
Int list elements: 2
Int list elements: 3
Int list elements: 4
Int list elements: 6
Int list capacity: 20
```

### Notes

- The list grows automatically if it runs out of space (it doubles its size).
- The implementation checks for valid indices when accessing or removing elements.
- Don't forget to free the list memory when you're done.

## Contributing

Feel free to open issues or submit pull requests if you have suggestions or improvements!

## License

MIT License
