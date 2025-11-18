#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

typedef enum {
  NEW,
  SIZE,
  COMPARE,
  APPEND,
  INSERT,
  PRINT,
  REMOVE,
  DELETE,
  ERROR
} action_t;

typedef struct SB_Action {
    action_t action;
    int sb_idx;
    void* arg1;
    void* arg2;
} sb_action_t;

struct SB_Action* parse_line(FILE* in);