//
// Created by Григорий on 26.02.2022.
//

#include "string_.h"
#include <memory.h>


size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }

    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }

    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }

    return begin;
}

char* findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }

    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && !isspace(*rbegin)) {
        rbegin--;
    }

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0') {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    return beginDestination + size;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    size_t size = endSource - beginSource;
    for (size_t i = 0; i < size; i++) {
        if (f(*beginSource)) {
            *(beginDestination++) = *beginSource;
        }

        beginSource++;
    }

    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    size_t size = rbeginSource - rendSource;
    for (size_t i = 0; i < size; i++) {
        if (f(*rbeginSource)) {
            *(beginDestination++) = *rbeginSource;
        }

        rbeginSource--;
    }

    return beginDestination;
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    destination = copy(word.begin, word.end, destination);
    *destination = '\0';
}
