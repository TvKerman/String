//
// Created by Григорий on 26.02.2022.
//
#ifndef STRING_STRING__H
#define STRING_STRING__H

#include <stdlib.h>

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

#endif //STRING_STRING__H
