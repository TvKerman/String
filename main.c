#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/convertStringDigitsTheEnd.h"
#include "string/tasks/digitCorrespondingNumberOfSpaces.h"
#include "string/tasks/replace.h"
#include "string/tasks/isWordsLexicographicallyOrdered.h"
#include "string/tasks/wordsReverseOrder.h"
#include "string/tasks/countOfPalindromeWords.h"
#include "string/tasks/mergingStrings.h"
#include "string/tasks/reverseWordOrderInAString.h"
#include "string/tasks/getWordBeforeFirstWordWithA.h"
#include "string/tasks/lastWordInFirstStringInSecondString.h"
#include "string/tasks/isIdenticalWordsInString.h"
#include "string/tasks/isPairOfWordsMadeOfIdenticalLetters.h"

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




void test_removeNonLetters_nullString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_oneSpace() {
    char s[] = " ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_oneWord() {
    char s[] = " Hi123 ";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces_nullString() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_oneSpace() {
    char s[] = " ";
    removeExtraSpaces(s);
    ASSERT_STRING(" ", s);
}

void test_removeExtraSpaces_manySpace() {
    char s[] = " Hi   123 ";
    removeExtraSpaces(s);
    ASSERT_STRING(" Hi 123 ", s);
}

void test_convertStringDigitsTheEnd_nullString() {
    char s[] = "";
    convertStringDigitsTheEnd(s);
    ASSERT_STRING("", s);
}

void test_convertStringDigitsTheEnd_nonDigits() {
    char s[] = "is String";
    convertStringDigitsTheEnd(s);
    ASSERT_STRING("is String", s);
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

void test_digitCorrespondingNumberOfSpaces_nullString() {
    char s[] = "";
    digitCorrespondingNumberOfSpaces(s);
    ASSERT_STRING("", s);
}

void test_digitCorrespondingNumberOfSpaces_onlyDigits() {
    char s[MAX_STRING_SIZE] = "32";
    digitCorrespondingNumberOfSpaces(s);
    ASSERT_STRING("     ", s);
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

void test_replace_noWordInString() {
    char s[MAX_STRING_SIZE] = "Hello  World";
    char w1[] = "Word";
    char w2[] = "<No_name>";
    replace(s, w1, w2);
    ASSERT_STRING("Hello  World", s);
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

void test_wordsReverseOrder_nullString() {
    char s[] = "";
    wordsReverseOrder(s);
    ASSERT_STRING("", s);
}


void test_wordsReverseOrder_twoWords() {
    char s[] = " BD ABC  ";
    wordsReverseOrder(s);
    ASSERT_STRING(" ABC BD  ", s);
}

void test_wordsReverseOrder_manyWords() {
    char s[] = "A B   C    D";
    wordsReverseOrder(s);
    ASSERT_STRING("D C   B    A", s);
}

void test_countOfPalindromeWords_nullString() {
    char s[] = "";
    if (countOfPalindromeWords(s) == 0) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("false", "true");
    }
}

void test_countOfPalindromeWords_oneSymbolInWords() {
    char s[] = "A,B,C,D";
    if (countOfPalindromeWords(s) == 4) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("false", "true");
    }
}

void test_countOfPalindromeWords_commaString() {
    char s[] = ",,,,,,";
    if (countOfPalindromeWords(s) == 0) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("false", "true");
    }
}

void test_countOfPalindromeWords() {
    char s[] = "ABCCBA,ZXYXZ,ABCD";
    if (countOfPalindromeWords(s) == 2) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("false", "true");
    }
}

void test_mergingStrings_nullStrings() {
    char s[] = "";
    char s1[] = "";
    char s2[] = "";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("", s);
}

void test_mergingStrings_nullStringS2() {
    char s[MAX_STRING_SIZE] = "";
    char s1[] = "A BC DEF";
    char s2[] = "";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("A BC DEF", s);
}

void test_mergingStrings_nullStringS1() {
    char s[MAX_STRING_SIZE] = "";
    char s2[] = "A BC DEF";
    char s1[] = "";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("A BC DEF", s);
}

void test_mergingStrings_equalSizeStrings() {
    char s[MAX_STRING_SIZE] = "";
    char s1[] = "A BC DEF";
    char s2[] = "AB CDE F";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("A AB BC CDE DEF F", s);
}

void test_mergingStrings1() {
    char s[MAX_STRING_SIZE] = "";
    char s1[] = "A BC DEF";
    char s2[] = "AB";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("A AB BC DEF", s);
}

void test_mergingStrings2() {
    char s[MAX_STRING_SIZE] = "";
    char s1[] = "A";
    char s2[] = "AB CDE F";
    mergingStrings(s, s1, s2);
    ASSERT_STRING("A AB CDE F", s);
}

void test_reverseWordOrderInAString_nullString() {
    char s[] = "";
    reverseWordOrderInAString(s);
    ASSERT_STRING("", s);
}

void test_reverseWordOrderInAString_noWord() {
    char s[] = "      ";
    reverseWordOrderInAString(s);
    ASSERT_STRING("      ", s);
}

void test_reverseWordOrderInAString_oneWord() {
    char s[] = " ABCD ";
    reverseWordOrderInAString(s);
    ASSERT_STRING("ABCD", s);
}

void test_reverseWordOrderInAString_manyWords() {
    char s[] = "A  B C D";
    reverseWordOrderInAString(s);
    ASSERT_STRING("D C B A", s);
}

void testAll_getWordBeforeFirstWordWithA () {
    char * beginWord , * endWord ;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

void test_lastWordInFirstStringInSecondString_nullStrings() {
    char s1[] = "";
    char s2[] = "";
    char string[MAX_STRING_SIZE];

    WordDescriptor word = lastWordInFirstStringInSecondString (s1, s2);
    wordDescriptorToString(word, string);
    ASSERT_STRING("", string);
}

void test_lastWordInFirstStringInSecondString_noIdenticalWords() {
    char s1[] = "ABC a b";
    char s2[] = "abc A B";
    char string[MAX_STRING_SIZE];

    WordDescriptor word = lastWordInFirstStringInSecondString (s1, s2);
    wordDescriptorToString(word, string);
    ASSERT_STRING("", string);
}

void test_lastWordInFirstStringInSecondString_haveIdenticalWords() {
    char s1[] = "ABC A B";
    char s2[] = "A B ABC";
    char string[MAX_STRING_SIZE];
    WordDescriptor word = lastWordInFirstStringInSecondString (s1, s2);
    wordDescriptorToString(word, string);
    ASSERT_STRING("B", string);
}

void test_isIdenticalWordsInString_nullString() {
    char s[] = "";
    if (isIdenticalWordsInString(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void test_isIdenticalWordsInString_noIdenticalWords() {
    char s[] = "A AB BC C";
    if (isIdenticalWordsInString(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void test_isIdenticalWordsInString_haveIdenticalWords() {
    char s[] = "A AB BC AB";
    if (isIdenticalWordsInString(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isPairOfWordsMadeOfIdenticalLetters_nullString() {
    char s[] = "";
    if (isPairOfWordsMadeOfIdenticalLetters(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void test_isPairOfWordsMadeOfIdenticalLetters_noIdenticalWords() {
    char s[] = "A AB BC C";
    if (isPairOfWordsMadeOfIdenticalLetters(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void test_isPairOfWordsMadeOfIdenticalLetters_haveIdenticalWords() {
    char s[] = "A AB BC AB";
    if (isPairOfWordsMadeOfIdenticalLetters(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isPairOfWordsMadeOfIdenticalLetters_haveIdenticalLetters() {
    char s[] = "A AB BC BA";
    if (isPairOfWordsMadeOfIdenticalLetters(s)) {
        ASSERT_STRING("true", "true");
    } else {
        ASSERT_STRING("true", "false");
    }
}

void test_isPairOfWordsMadeOfIdenticalLetters_noIdenticalLetters() {
    char s[] = "A ABB AB C";
    if (isPairOfWordsMadeOfIdenticalLetters(s)) {
        ASSERT_STRING("false", "true");
    } else {
        ASSERT_STRING("false", "false");
    }
}

void tests() {
    test_removeNonLetters_nullString();
    test_removeNonLetters_oneSpace();
    test_removeNonLetters_oneWord();
    test_removeExtraSpaces_nullString();
    test_removeExtraSpaces_oneSpace();
    test_removeExtraSpaces_manySpace();
    test_convertStringDigitsTheEnd_nullString();
    test_convertStringDigitsTheEnd_nonDigits();
    test_convertStringDigitsTheEnd_oneWord1();
    test_convertStringDigitsTheEnd_oneWord2();
    test_convertStringDigitsTheEnd_severalWord();
    test_digitCorrespondingNumberOfSpaces_nullString();
    test_digitCorrespondingNumberOfSpaces_onlyDigits();
    test_digitCorrespondingNumberOfSpaces_noNumbers();
    test_digitCorrespondingNumberOfSpaces_thereAreNumbers();
    test_replace_noWordInString();
    test_replace_w1SizeLessW2Size();
    test_replace_w2SizeLessW1Size();
    test_isWordsLexicographicallyOrdered_orderedString1();
    test_isWordsLexicographicallyOrdered_orderedString2();
    test_isWordsLexicographicallyOrdered_NULLSymbols();
    test_isWordsLexicographicallyOrdered_equalWords();
    test_isWordsLexicographicallyOrdered_unorderedString();
    test_wordsReverseOrder_nullString();
    test_wordsReverseOrder_twoWords();
    test_wordsReverseOrder_manyWords();
    test_countOfPalindromeWords_nullString();
    test_countOfPalindromeWords_oneSymbolInWords();
    test_countOfPalindromeWords_commaString();
    test_countOfPalindromeWords();
    test_mergingStrings_nullStrings();
    test_mergingStrings_nullStringS2();
    test_mergingStrings_nullStringS1();
    test_mergingStrings_equalSizeStrings();
    test_mergingStrings1();
    test_mergingStrings2();
    test_reverseWordOrderInAString_nullString();
    test_reverseWordOrderInAString_noWord();
    test_reverseWordOrderInAString_oneWord();
    test_reverseWordOrderInAString_manyWords();
    testAll_getWordBeforeFirstWordWithA();
    test_lastWordInFirstStringInSecondString_nullStrings();
    test_lastWordInFirstStringInSecondString_noIdenticalWords();
    test_lastWordInFirstStringInSecondString_haveIdenticalWords();
    test_isIdenticalWordsInString_nullString();
    test_isIdenticalWordsInString_noIdenticalWords();
    test_isIdenticalWordsInString_haveIdenticalWords();
    test_isPairOfWordsMadeOfIdenticalLetters_nullString();
    test_isPairOfWordsMadeOfIdenticalLetters_noIdenticalWords();
    test_isPairOfWordsMadeOfIdenticalLetters_haveIdenticalWords();
    test_isPairOfWordsMadeOfIdenticalLetters_haveIdenticalLetters();
    test_isPairOfWordsMadeOfIdenticalLetters_noIdenticalLetters();
}

int main() {
    tests();

    //char s[] = "H1I23";
    //convertStringDigitsTheEnd(s);
    //printf("%s\n", s);

    return 0;
}
