#include "list.h"

int main() {
    

    List list = LIST(int, 20);

    int value = 1;
    list_push(&list, &value);
    value++;
    list_push(&list, &value);
    value++;
    list_push(&list, &value);
    value++;
    list_push(&list, &value);
    value++;
    list_push(&list, &value);
    value++;
    list_push(&list, &value);
    value++;


    for (int i = 0; i < list.size; i++) {
        printf("Int list elements: %d\n", *LIST_GET(int, &list, i));
    }

    printf("Int list capacity: %d\n", (int)list.capacity);

    list_remove(&list, 4);

     for (int i = 0; i < list.size; i++) {
        printf("Int list elements: %d\n", *(int*)list_get(&list, i));
    }

    printf("Int list capacity: %d\n", (int)list.capacity);

    list_free(&list);

    return 0;
}