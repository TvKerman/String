#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"

int f(int a) {
    return '0' <= a && a <= '9';
}

#define ASSERT_STRING(expected, got) assertString( expected, got, __FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf (stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters_oneWord() {
    char s[] = " Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces_manySpace() {
    char s[] = "Hi   123";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi 123", s);
}


void tests() {
    test_removeNonLetters_oneWord();
    test_removeExtraSpaces_manySpace();
}

int main() {
    tests();
    return 0;
}
