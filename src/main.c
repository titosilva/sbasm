#include "./structures/strmap/strmap.h"
#include "./structures/memory.h"

#include <stdio.h>

int main() {
    init_alloc_table();
    StrMap* map = map_new();

    int x = 2;
    map_set(map, "abacaxi2", &x);

    int* r = (int*) map_get(map, "abacaxi2");
    printf("r: %d\n", *r);

    int y = 3;
    map_set(map, "acabaxi2", &y);

    r = (int*) map_get(map, "acabaxi2");
    printf("r: %d\n", *r);

    end_alloc_table();
    return 0;
}
