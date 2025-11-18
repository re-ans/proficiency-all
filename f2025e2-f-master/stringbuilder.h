#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

struct StringBuilder {
    size_t capacity;
    size_t size;
    char* content;
};

struct StringBuilder* sb_new(const char* string);
size_t sb_size(struct StringBuilder* sb);
int sb_compare(struct StringBuilder* s1, struct StringBuilder* s2);
void sb_append(struct StringBuilder* sb, char* str);
void sb_insert(struct StringBuilder* sb, char* str, size_t idx);
char* sb_toString(struct StringBuilder* sb);
void sb_remove(struct StringBuilder* sb, size_t start, size_t end);
void sb_delete(struct StringBuilder* sb);
#endif
