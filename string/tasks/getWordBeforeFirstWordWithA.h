//
// Created by Григорий on 06.03.2022.
//

#ifndef PROJECT_GETWORDBEFOREFIRSTWORDWITHA_H
#define PROJECT_GETWORDBEFOREFIRSTWORDWITHA_H

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

char *min2(char *a, char *b) {
    return a < b ? a: b;
}

// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, char **beginWordBefore, char **endWordBefore) {
    size_t size = strlen_(s);
    char *end = s + size + 1;
    WordDescriptor previousWord;

    if (!getWord(s, &previousWord)) {
        return EMPTY_STRING;
    }

    char *posSymbolA = min2(find(s, end, 'A'), find(s, end, 'a'));
    if (posSymbolA == end) {
        return NOT_FOUND_A_WORD_WITH_A;
    }
    if (posSymbolA < previousWord.end) {
        return FIRST_WORD_WITH_A;
    }

    char *beginSearch = previousWord.end;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        if (posSymbolA < word.end) {
            *beginWordBefore = previousWord.begin;
            *endWordBefore = previousWord.end;
            return WORD_FOUND;
        }

        previousWord = (WordDescriptor){word.begin, word.end};
        beginSearch = word.end;
    }
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor word;
    if (getWordBeforeFirstWordWithA(s, &word.begin, &word.end) != WORD_FOUND) {
        return;
    }

    while (word.begin < word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }
}


#endif //PROJECT_GETWORDBEFOREFIRSTWORDWITHA_H
