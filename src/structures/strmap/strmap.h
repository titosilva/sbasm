#pragma once

typedef struct {
    char* key;
    void* value;
} StrMapEntry;

typedef struct {
    StrMapEntry **tables;
    int tables_count;
} StrMap;

StrMap* map_new();
void map_free(StrMap* map);
void* map_get(StrMap* map, const char * key);
void map_set(StrMap* map, const char * key, void* value);
