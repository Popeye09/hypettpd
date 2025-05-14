//
// Created by Kovács Áron on 2025. 05. 14.
//

#include "array.h"

Array_Operation_Result Array_Operation_Result_create(const bool success,const char* const error_message)
{
    Array_Operation_Result array_operation_result;

    array_operation_result.success = success;
    array_operation_result.error_message = error_message;

    return array_operation_result;
}