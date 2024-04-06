#pragma once

// string with \0 at the end
typedef char* str;
typedef const char* const_str;

str str_new(int len);
str str_clone(const_str src);
str str_skip(const_str s, int len_to_skip);
str str_cut(const_str s, int len_to_keep);
str str_sub(const_str s, int start, int end);
str* str_posix_regex_match(const_str to_match, const_str expr, int* out_counter);
