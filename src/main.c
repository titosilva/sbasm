#include "./structures/str/str.h"
#include "./structures/memory.h"

#include <stdio.h>

void match(str x, str pattern);

int main(int argc, char *argv[]) {
    init_alloc_table();

    printf("argc: %d\n", argc);
    // str pattern = "^[[:blank:]]*\\([[:alnum:]_]\\{1,\\}:\\)*[[:blank:]]*\\([[:alnum:]]\\{1,\\}\\)*[[:blank:]]*\\([[:alnum:]]\\{1,\\}\\)*[[:blank:]]*$";

    // str x = "\tlabel: \t\t\tAND N1";
    // match(x, pattern);

    // x = "\t\t   AND\t\t\t N1";
    // match(x, pattern);

    // x = "\t\t   STOP             ";
    // match(x, pattern);

    // x = "\t\t \t  N1: const\t\t\t 0\t\t    ";
    // match(x, pattern);

    end_alloc_table();
    return 0;
}

void match(str x, str pattern) {
    int ctr = 0;
    str* matches = str_posix_regex_match(x, pattern, &ctr);

    printf("%s with %d matches\n", x, ctr);
    for (int i = 1; i < ctr; i++) {
        printf("%s\n", matches[i]);
    }
}
