//
// Created by Kovács Áron on 2025.05.14.
//

#include "array.h"

#include <stddef.h>

Array_Operation_Result array_initialize(Array* array, uint64_t count, size_t size_element)
{
    if (count < 0)
    {
        return Array_Operation_Result_create(false, "Count must be greater than 0");
    }
    if (size_element < 0)
    {
        return Array_Operation_Result_create(false, "Element size must be greater than 0");
    }
    array->count = count;
    array->size_element = size_element;

    return Array_Operation_Result_create(true, nullptr);
}

void* array_get(Array*, uint64_t index)
{

}

void* array_search(Array* array, void* value);


Array_Operation_Result array_push_back(Array* array, void* element);