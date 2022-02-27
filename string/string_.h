//
// Created by Григорий on 26.02.2022.
//
#ifndef STRING_STRING__H
#define STRING_STRING__H

#include <stdio.h>
#include <stdbool.h>
#define MAX_STRING_SIZE 1000

char _stringBuffer[MAX_STRING_SIZE + 1];

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //STRING_STRING__H
