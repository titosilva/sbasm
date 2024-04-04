#include "./structures/strmap/strmap.h"

#include <stdio.h>

int main() {
    StrMap* map = map_new();

    int x = 2;
    map_set(map, "abacaxi2", &x);

    int* r = (int*) map_get(map, "abacaxi2");
    printf("r: %d\n", *r);

    map_free(map);
    return 0;
}
