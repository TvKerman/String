//
// Created by Григорий on 26.02.2022.
//
#ifndef STRING_STRING__H
#define STRING_STRING__H

#include <stdlib.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

#endif //STRING_STRING__H
