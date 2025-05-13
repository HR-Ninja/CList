#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define DEFINE_LIST_TYPE(T)                                              \
typedef struct {                                                         \
    T *data;                                                             \
    size_t size, capacity;                                               \
} List_##T;                                                              \
                                                                         \
void init_##T##_list(List_##T *l) {                                      \
    l->size = 0;                                                         \
    l->capacity = 4;                                                     \
    l->data = malloc(l->capacity * sizeof(T));                           \
    if (!l->data) { fprintf(stderr, "alloc failed\n"); exit(1); }        \
}                                                                        \
                                                                         \
void push_##T(List_##T *l, T v) {                                        \
    if (l->size == l->capacity) {                                        \
        l->capacity *= 2;                                                \
        l->data = realloc(l->data, l->capacity * sizeof(T));             \
        if (!l->data) { fprintf(stderr, "realloc failed\n"); exit(1); }  \
    }                                                                    \
    l->data[l->size++] = v;                                              \
}                                                                        \
void remove_##T(List_##T *l, size_t index) {                             \
    if (index >= l->size) { fprintf(stderr, "index out of bounds\n"); exit(1); } \
    for (size_t i = index; i < l->size - 1; i++) {                       \
        l->data[i] = l->data[i + 1];                                     \
    }                                                                    \
    l->size--;                                                           \
}                                                                        \
                                                                         \
T get_##T(const List_##T *l, size_t i) {                                 \
    if (i >= l->size) { fprintf(stderr, "index out of bounds\n"); exit(1); } \
    return l->data[i];                                                   \
}                                                                        \
                                                                         \
void free_##T##_list(List_##T *l) {                                      \
    free(l->data);                                                       \
    l->data = NULL;                                                      \
    l->size = l->capacity = 0;                                           \
}


// Use the macro to create the struct and functions
DEFINE_LIST_TYPE(int)

int main() {
    
    List_int int_list;
    init_int_list(&int_list);

    push_int(&int_list, 1);
    push_int(&int_list, 2);
    push_int(&int_list, 3);
    push_int(&int_list, 4);
    push_int(&int_list, 5);


    for (int i = 0; i < int_list.size; i++) {
        printf("Int list elements: %d\n", get_int(&int_list, i));
    }

    printf("Int list capacity: %d\n", int_list.capacity);

    remove_int(&int_list, 4);

     for (int i = 0; i < int_list.size; i++) {
        printf("Int list elements: %d\n", get_int(&int_list, i));
    }

    printf("Int list capacity: %d\n", int_list.capacity);


    free_int_list(&int_list);

    return 0;
}