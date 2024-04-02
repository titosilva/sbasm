#include "./strmap.h"

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

StrMapEntry* add_table(StrMap* map);
uint16_t hash(const char * key);

StrMap* map_new() {
    StrMap* map = (StrMap*) malloc(sizeof(StrMap));
    map->tables = NULL;
    map->tables_count = 0;

    return map;
}

void map_free(StrMap* map) {
    for (int i = 0; i < map->tables_count; i++) {
        for (int j = 0; j < 0xFFFF; j++) {
            if (map->tables[i]->key != NULL) free(map->tables[i]->key);
        }
        free(map->tables[i]);
    }

    free(map->tables);
    free(map);
}

void* map_get(StrMap* map, const char * key) {
    uint16_t idx = hash(key);

    for (int i = 0; i < map->tables_count; i++) {
        StrMapEntry* table = map->tables[i];

        StrMapEntry entry = table[idx];
        if (entry.key == NULL) {
            break;
        }

        // When this condition is not satisfied,
        // then we have a collision in this index
        // and must proceed to retry in the next table
        if (strcmp(entry.key, key) == 0) {
            return entry.value;
        }
    }

    return NULL;
}

void map_set(StrMap* map, const char * key, void* value) {
    uint16_t idx = hash(key);

    for (int i = 0; i < map->tables_count; i++) {
        StrMapEntry* table = map->tables[i];

        if (table[idx].key == NULL) {
            char* new_key = malloc(strlen(key));
            table[idx].key = strcpy(new_key, key);
            table[idx].value = value;
            return;
        } else if (strcmp(table[idx].key, key) == 0) {
            table[idx].value = value;
            return;
        }
    }

    // In this point, no available table space was found
    // We must then allocate a new table
    StrMapEntry* table = add_table(map);
    char* new_key = malloc(strlen(key));
    table[idx].key = strcpy(new_key, key);
    table[idx].value = value;
}

StrMapEntry* add_table(StrMap* map) {
    if (map->tables == NULL) {
        map->tables = (StrMapEntry**) malloc(sizeof(StrMapEntry*));
    } else {
        map->tables = (StrMapEntry**) realloc(map->tables, map->tables_count * sizeof(StrMapEntry*));
    }

    StrMapEntry* table = (StrMapEntry*) calloc(0xFFFF, sizeof(StrMapEntry));
    map->tables[map->tables_count] = table;
    map->tables_count++;

    return table;
}

uint16_t hash(const char * key) {
    uint16_t idx = 0;

    for (int i = 0; i < strlen(key); i++) {
        idx ^= (key[i] << (i % 2));
    }

    return idx;
}
