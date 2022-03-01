#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/convertStringDigitsTheEnd.h"
#include "string/tasks/digitCorrespondingNumberOfSpaces.h"
#include "string/tasks/replace.h"
#include "string/tasks/isWordsLexicographicallyOrdered.h"
#include "string/tasks/wordsReverseOrder.h"

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
    char s[] = " Hi   123 ";
    removeExtraSpaces(s);
    ASSERT_STRING(" Hi 123 ", s);
}

void test_convertStringDigitsTheEnd_oneWord1() {
    char s[] = " H12i3 ";
    convertStringDigitsTheEnd(s);
    ASSERT_STRING(" Hi123 ", s);
}

void test_convertStringDigitsTheEnd_oneWord2() {
    char s[] = "H12i3";
    convertStringDigitsTheEnd(s);
    ASSERT_STRING("Hi123", s);
}

void test_convertStringDigitsTheEnd_severalWord() {
    char s[] = "H1e2ll3o W4or5ld";
    convertStringDigitsTheEnd(s);
    ASSERT_STRING("Hello123 World45", s);
}

void test_digitCorrespondingNumberOfSpaces_noNumbers() {
    char s[] = "Hello World";
    digitCorrespondingNumberOfSpaces(s);
    ASSERT_STRING("Hello World", s);
}

void test_digitCorrespondingNumberOfSpaces_thereAreNumbers() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    digitCorrespondingNumberOfSpaces(s);
    ASSERT_STRING("A   BC ", s);
}

void test_replace_w1SizeLessW2Size() {
    char s[MAX_STRING_SIZE] = "Hello  World";
    char w1[] = "World";
    char w2[] = "<No_name>";
    replace(s, w1, w2);
    ASSERT_STRING("Hello  <No_name>", s);
}

void test_replace_w2SizeLessW1Size() {
    char s[MAX_STRING_SIZE] = "Hello  World";
    char w1[] = "World";
    char w2[] = "You";
    replace(s, w1, w2);
    ASSERT_STRING("Hello  You", s);
}

void test_isWordsLexicographicallyOrdered_orderedString1() {
    char s[MAX_STRING_SIZE] = "A AA AAA";
    if (isWordsLexicographicallyOrdered(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isWordsLexicographicallyOrdered_orderedString2() {
    char s[MAX_STRING_SIZE] = "AA AB BB";
    if (isWordsLexicographicallyOrdered(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isWordsLexicographicallyOrdered_NULLSymbols() {
    char s[MAX_STRING_SIZE] = "";
    if (isWordsLexicographicallyOrdered(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isWordsLexicographicallyOrdered_equalWords() {
    char s[MAX_STRING_SIZE] = "A A A A";
    if (isWordsLexicographicallyOrdered(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isWordsLexicographicallyOrdered_unorderedString() {
    char s[MAX_STRING_SIZE] = "B A B C";
    if (isWordsLexicographicallyOrdered(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void test_wordsReverseOrder_twoWords() {
    char s[] = "BD ABC";
    wordsReverseOrder(s);
    ASSERT_STRING("ABC BD", s);
}

void tests() {
    test_removeNonLetters_oneWord();
    test_removeExtraSpaces_manySpace();
    test_convertStringDigitsTheEnd_oneWord1();
    test_convertStringDigitsTheEnd_oneWord2();
    test_convertStringDigitsTheEnd_severalWord();
    test_digitCorrespondingNumberOfSpaces_noNumbers();
    test_digitCorrespondingNumberOfSpaces_thereAreNumbers();
    test_replace_w1SizeLessW2Size();
    test_replace_w2SizeLessW1Size();
    test_isWordsLexicographicallyOrdered_orderedString1();
    test_isWordsLexicographicallyOrdered_orderedString2();
    test_isWordsLexicographicallyOrdered_NULLSymbols();
    test_isWordsLexicographicallyOrdered_equalWords();
    test_isWordsLexicographicallyOrdered_unorderedString();
    test_wordsReverseOrder_twoWords();
}

int main() {
    tests();

    //char s[] = "H1I23";
    //convertStringDigitsTheEnd(s);
    //printf("%s\n", s);

    return 0;
}
