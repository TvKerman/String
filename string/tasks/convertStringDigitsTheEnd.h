//
// Created by Григорий on 27.02.2022.
//

#ifndef PROJECT_CONVERTSTRINGDIGITSTHEEND_H
#define PROJECT_CONVERTSTRINGDIGITSTHEEND_H


int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy( word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin , isdigit);

    copyIf (_stringBuffer, endStringBuffer, recPosition, isalpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend) {
        return false;
    }

    word->begin = findSpaceReverse(word->end, rend);
    return true;
}

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);

    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void convertStringDigitsTheEnd(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToEnd(word);

        beginSearch = word.end;
    }
}

#endif //PROJECT_CONVERTSTRINGDIGITSTHEEND_H
