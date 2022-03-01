//
// Created by Григорий on 01.03.2022.
//

#ifndef PROJECT_ISWORDSLEXICOGRAPHICALLYORDERED_H
#define PROJECT_ISWORDSLEXICOGRAPHICALLYORDERED_H

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin < w1.end && w2.begin < w2.end && *w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    if (w1.begin == w1.end && w2.begin == w2.end) {
        return 0;
    } else {
        return *w1.begin - *w2.begin;
    }
}

bool isWordsLexicographicallyOrdered(char *s) {
    char *beginSearch = s;
    WordDescriptor previousWord;
    WordDescriptor word;

    if (!getWord(beginSearch, &previousWord)) {
        return true;
    }

    beginSearch = previousWord.end;
    while (getWord(beginSearch, &word)) {
        if (areWordsEqual(previousWord, word) > 0) {
            return false;
        }

        previousWord = (WordDescriptor){word.begin, word.end};
        beginSearch = word.end;
    }
    return true;
}

#endif //PROJECT_ISWORDSLEXICOGRAPHICALLYORDERED_H
