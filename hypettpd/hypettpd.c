//
// Created by Kovács Áron on 2025.05.13.
//

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>

#include "array.h"


int main (int argc, char *argv[])
{

    const uint32_t cpu_core_count = get_nprocs();

    printf("%i", cpu_core_count);

    Array children;

    const Array_Operation_Result children_initialize_result = array_initialize(&children, 8, sizeof pid_t);
    if (!children_initialize_result.success)
    {
        fprintf(stderr,"Failed to initialize array\n");
        exit(1);
    }


    for (uint32_t i = 0; i < cpu_core_count; i++)
    {
        pid_t pid = fork();

        if (pid == 0) listen();
        if (pid > 0) array_push_back(&children, (void*)pid);
    }

    for (int i = 0; i < children.count; ++i)
    {
        int children_finished_status;
        pid_t children_finished = wait(&children_finished);

    }

    return 0;
}

void listen()
{
    printf("I am listening!\n");
    sleep((3));
    exit(0);
}
