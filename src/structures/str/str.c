#include "./str.h"
#include "../memory.h"

#include <string.h>
#include <regex.h>

#define MAX_MATCHES 20

str str_new(int len) {
    // One extra space for \0
    return (str)scalloc(len + 1, sizeof(char));
}

str str_clone(const_str src) {
    str s = str_new(strlen(src));
    strcpy((char*)s, (char*)src);
    return s;
}

str str_skip(const_str s, int len_to_skip) {
    return str_clone(s + len_to_skip);
}

str str_cut(const_str s, int len_to_keep) {
    str r = str_new(len_to_keep);
    strncpy(r, s, len_to_keep);
    return r;
}

str str_sub(const_str s, int start, int end) {
    str r = str_new(end-start);
    strncpy(r, s + start, end-start);
    return r;
}

str* str_posix_regex_match(const_str to_match, const_str expr, int* out_counter) {
    regex_t comp;
    if (regcomp(&comp, expr, 0)) {
        return NULL;
    }

    regmatch_t matches[MAX_MATCHES];
    for (int i = 0; i < MAX_MATCHES; i++) {
        matches[i].rm_so = -1;
        matches[i].rm_eo = -1;
    }

    if (regexec(&comp, to_match, MAX_MATCHES, matches, 0)) {
        regfree(&comp);
        return NULL;
    }
    regfree(&comp);

    *out_counter = 0;
    for (int i = 0; i < MAX_MATCHES; i++) {
        if (matches[i].rm_eo != -1) (*out_counter)++;
    }

    str* result = (str*)scalloc(*out_counter, sizeof(str));

    int aux = 0;
    for (int i = 0; i < MAX_MATCHES; i++) {
        if (matches[i].rm_eo == -1) continue;

        result[aux++] = str_sub(to_match, matches[i].rm_so, matches[i].rm_eo);
    }

    return result;
}
