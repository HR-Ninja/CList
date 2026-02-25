#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define LIST(T, SIZE) (create_list(sizeof(T), SIZE))
#define LIST_GET(T, L, IDX) (T*)(list_get(L, IDX))

typedef struct {
    size_t element_size;
    size_t capacity;
    size_t size;
    void* data;
} List;

List create_list(size_t element_size, size_t capacity) {
    return (List) {
        .element_size = element_size,
        .capacity = capacity,
        .size = 0,
        .data = (void*)malloc(element_size * capacity)
    };
}

int list_push(List* l, const void* data) {
    if (l->size >= l->capacity) {
        l->capacity *= 2;
        l->data = realloc(l->data, l->capacity * l->element_size);
        if (!l->data) {
            fprintf(stderr, "alloc failed\n");
            return 0;
        }
    }

    size_t idx = l->element_size * l->size;
    memcpy((char*)l->data + idx, data, l->element_size);
    l->size++;
    return 1;
}

int list_remove(List* l, size_t index) {
    if (index >= l->size) {
        fprintf(stderr, "index out of bounds\n");
        return 0;
    }

    if (index < l->size - 1) {
        void* dest = (char*)l->data + (index * l->element_size);
        void* src  = (char*)l->data + ((index + 1) * l->element_size);
        size_t bytes = (l->size - index - 1) * l->element_size;

        memmove(dest, src, bytes);
    }

    l->size--;
    return 1;
}

void* list_get(List* l, size_t index) {
    if (index >= l->size) {
        fprintf(stderr, "index out of bounds\n");
        return NULL;
    }

    return (char*)l->data + (index * l->element_size);
}

void list_free(List* l) {
    free(l->data);
    l->data = NULL;
    l->size = 0;
    l->capacity = 0;
    l->element_size = 0;
}

#endif