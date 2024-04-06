#include "./str.h"
#include "../memory.h"

#include <string.h>

str str_new(int len) {
    // One extra space for \0
    return (str)scalloc(len + 1, sizeof(char));
}

str str_clone(const_str src) {
    str s = str_new(strlen(src));
    strcpy((char*)s, (char*)src);
    return s;
}