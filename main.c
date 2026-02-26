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