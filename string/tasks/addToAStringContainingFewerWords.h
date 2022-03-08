//
// Created by Григорий on 08.03.2022.
//

#ifndef PROJECT_ADDTOASTRINGCONTAININGFEWERWORDS_H
#define PROJECT_ADDTOASTRINGCONTAININGFEWERWORDS_H

void addToAStringContainingFewerWords(char *s1, char *s2) {
    BagOfWords bag1;
    getBagOfWords(&bag1, s1);
    BagOfWords bag2;
    getBagOfWords(&bag2, s2);

    if (bag1.size == bag2.size) {
        return;
    }

    char *beginDestination;
    char *beginSearch;
    if (bag1.size < bag2.size) {
        beginDestination = s1 + strlen_(s1);
        beginSearch = bag2.words[bag1.size].begin;
    } else {
        beginDestination = s2 + strlen_(s2);
        beginSearch = bag1.words[bag2.size].begin;
    }

    if (bag1.size != 0 && bag2.size != 0) {
        *(beginDestination++) = ' ';
    }

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        beginDestination = copy(word.begin, word.end, beginDestination);
        *(beginDestination++) = ' ';

        beginSearch = word.end;
    }

    *(--beginDestination) = '\0';
}

#endif //PROJECT_ADDTOASTRINGCONTAININGFEWERWORDS_H
