#ifndef LIST_H
#define LIST_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define LIST(T, SIZE) (create_list(sizeof(T), SIZE))
#define LIST_PUSH(L, T, V) (list_push(L, sizeof(T), V))
#define LIST_GET(L, T, IDX) (T*)(list_get(L, IDX))
#define LIST_REMOVE(L, IDX) (list_remove(L, IDX))
#define LIST_FREE(L) (list_free(L))

typedef struct {
    size_t element_size;
    size_t capacity;
    size_t size;
    void* data;
} List;

extern List create_list(const size_t element_size, const size_t capacity);
extern int list_grow(List* l);
extern int list_push(List* l, const size_t element_size, const void* data);
extern int list_remove(List* l, const size_t index);
extern void* list_get(List* l, const size_t index);
extern void list_free(List* l);

#endif