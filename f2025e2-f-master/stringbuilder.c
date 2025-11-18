#include "stringbuilder.h"

struct StringBuilder* sb_new(const char* string) {
    struct StringBuilder* sb = malloc(sizeof(struct StringBuilder));
    if (!sb) return NULL;
    if (!string) string = "";
    sb->size = strlen(string);
    sb->capacity = sb->size + 1;
    char* cpy = malloc(sb->size + 1);
    strcpy(cpy, string);
    sb->content = cpy;
    return sb;
}

size_t sb_size(struct StringBuilder* sb) {
    return sb->size;
}

int sb_compare(struct StringBuilder* s1, struct StringBuilder* s2) {
    char* it1 = s1->content;
    char* it2 = s2->content;
    while (*it1 && *it2) {
        if (*it1 != *it2) {
            return *it1 - *it2;
        }
        it1++;
        it2++;
    }
    return *it1 - *it2;
}

void sb_append(struct StringBuilder* sb, char* str) {
    size_t str_size = strlen(str);
    size_t capNeeded = sb->size + str_size + 1;
    if (sb->capacity < capNeeded) {
        char* newContent = malloc(capNeeded);
        strcpy(newContent, sb->content);
        free(sb->content);
        sb->content = newContent;
        sb->capacity = capNeeded;
    }
    strcpy(sb->content + sb->size, str);
    sb->size += str_size;
}

void sb_insert(struct StringBuilder* sb, char* str, size_t idx) {
    if (idx > sb->size) return;
    size_t str_size = strlen(str);
    size_t capNeeded = sb->size + str_size + 1;
    if (sb->capacity < capNeeded) {
        char* newContent = malloc(capNeeded);
        strcpy(newContent, sb->content);
        free(sb->content);
        sb->content = newContent;
        sb->capacity = capNeeded;
    }
    char* buffer = malloc(sb->size - idx + 1);
    strcpy(buffer, sb->content + idx);
    strcpy(sb->content + idx, str);
    strcpy(sb->content + idx + str_size, buffer);
    free(buffer);
    sb->size += str_size;
}

char* sb_toString(struct StringBuilder* sb) {
    char* res = malloc(sb->size);
    strcpy(res, sb->content);
    return res;
}

void sb_remove(struct StringBuilder* sb, size_t start, size_t end) {
    if (start > end || end > sb->size) return;
    size_t newSize = sb->size - (end - start);
    for (size_t i = end; i <= sb->size; i++) {
        sb->content[start + (i - end)] = sb->content[i];
    }
    sb->size = newSize;
}

void sb_delete(struct StringBuilder* sb) {
    free(sb->content);
    free(sb);
}
