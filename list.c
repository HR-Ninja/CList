#include "list.h"

List create_list(const size_t element_size, const size_t capacity) {
    return (List) {
        .element_size = element_size,
        .capacity = capacity,
        .size = 0,
        .data = (void*)malloc(element_size * capacity)
    };
}

int list_grow(List* l) {
    l->capacity *= 2;
    l->data = realloc(l->data, l->capacity * l->element_size);
    if (!l->data) {
        fprintf(stderr, "alloc failed\n");
        return 0;
    }

    return 1;
}

int list_push(List* l, const size_t element_size, const void* data) {

    if (l == NULL || data == NULL) {
        return 0;
    }

    if(l->element_size != element_size) {
        fprintf(stderr, "incorrect type\n");
            return 0;
    }

    if (l->size >= l->capacity) {
        if(!list_grow(l)) {
            return 0;
        }
    }

    size_t idx = l->element_size * l->size;
    memcpy((char*)l->data + idx, data, l->element_size);
    l->size++;
    return 1;
}

int list_remove(List* l, const size_t index) {

    if (l == NULL) {
        return 0;
    }

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

void* list_get(List* l, const size_t index) {

    if (l == NULL) {
        return 0;
    }

    if (index >= l->size) {
        fprintf(stderr, "index out of bounds\n");
        return NULL;
    }

    return (char*)l->data + (index * l->element_size);
}

void list_free(List* l) {

    if (l == NULL) {
        return;
    }

    if (l->data != NULL) {
        free(l->data);
        l->data = NULL;
    }
    
    l->size = 0;
    l->capacity = 0;
    l->element_size = 0;
}