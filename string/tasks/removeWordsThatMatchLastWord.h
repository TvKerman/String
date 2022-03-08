//
// Created by Григорий on 08.03.2022.
//

#ifndef PROJECT_REMOVEWORDSTHATMATCHLASTWORD_H
#define PROJECT_REMOVEWORDSTHATMATCHLASTWORD_H

void removeWordsThatMatchLastWord(char *s) {
    WordDescriptor lastWord;
    if (!getWordReverse(s + strlen_(s) - 1, s - 1, &lastWord)) {
        return;
    }

    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word) && areWordsEqual(word, lastWord) != 0) {
        beginSearch = word.end;
    }

    char *beginDestination = word.begin;
    while (getWord(beginSearch, &word)) {
        beginSearch = findNonSpace(word.end);
        if (areWordsEqual(word, lastWord) != 0) {
            beginDestination = copy(word.begin, word.end, beginDestination);
            beginDestination = copy(word.end, beginSearch, beginDestination);
        }
    }
    *beginDestination = '\0';
}

#endif //PROJECT_REMOVEWORDSTHATMATCHLASTWORD_H
