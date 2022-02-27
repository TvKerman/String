//
// Created by Григорий on 27.02.2022.
//
#ifndef PROJECT_REPLACE_H
#define PROJECT_REPLACE_H

int isEqualWord(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != (w1.end - 1) && w2.begin != (w2.end - 1) && *w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    return *w1.begin - *w2.begin;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor word;
    while (getWord(readPtr, &word)) {

        if (isEqualWord(word, word1) == 0) {
            recPtr = copy(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy(word.begin, word.end, recPtr);
        }

        readPtr = word.end;
        recPtr = copy(readPtr, findNonSpace(readPtr), recPtr);
    }
    *recPtr ='\0';
}

#endif //PROJECT_REPLACE_H
