#pragma once

// string with \0 at the end
typedef char* str;
typedef const char* const_str;

str str_new(int len);
str str_clone(const_str src);
