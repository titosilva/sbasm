#include "./structures/strmap/strmap.h"

#include <stdio.h>

int main() {
    StrMap* map = map_new();

    int x = 2, y = 3;
    map_set(map, "abacaxi", &x);

    int* r = (int*) map_get(map, "abacaxi");
    printf("r: %d\n", *r);

    map_set(map, "abacaxi", &y);

    r = (int*) map_get(map, "abacaxi");
    printf("r: %d\n", *r);

    x = 1;
    map_set(map, "teste", &x);

    r = (int*) map_get(map, "teste");
    printf("r: %d\n", *r);

    r = (int*) map_get(map, "TESTE");

    if (r == NULL) {
        printf("r: NULL\n");
    }

    map_free(map);
    return 0;
}
