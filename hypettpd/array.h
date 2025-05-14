//
// Created by Kovács Áron on 2025.05.14.
//

#ifndef ARRAY_H
#define ARRAY_H
#include <stdint.h>

typedef struct
{
    void* array;
    size_t size_element;
    uint64_t count;
} Array;

typedef struct
{
    bool success;
    const char* error_message;
    const void* element;
} Array_Operation_Result;


Array_Operation_Result array_initialize(Array* array, uint64_t count, size_t element_size);

Array_Operation_Result array_push_back(Array* array, void* element);

Array_Operation_Result* array_get(Array* array, uint64_t index);

Array_Operation_Result* array_search(Array* array, void* value);

Array_Operation_Result* array_pop_back(Array* array);

Array_Operation_Result* array_pop_at(Array* array, uint64_t index);


Array_Operation_Result Array_Operation_Result_create();

#endif //ARRAY_H
