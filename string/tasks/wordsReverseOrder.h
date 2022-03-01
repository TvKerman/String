//
// Created by Григорий on 01.03.2022.
//

#ifndef PROJECT_WORDSREVERSEORDER_H
#define PROJECT_WORDSREVERSEORDER_H

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    char *beginSearch = s;
    while (getWord(beginSearch, &bag->words[bag->size])) {
        beginSearch = bag->words[bag->size++].end;
    }
}

void wordsReverseOrder(char *s) {
    char copyString[MAX_STRING_SIZE];
    copy(s, s + strlen_(s), copyString);
    getBagOfWords(&_bag, copyString);
    if (_bag.size < 2) {
        return;
    }

    char *beginDestination = s;
    int size = _bag.size - 1;
    for (int i = size; i > 0; i--) {
        beginDestination = copy(_bag.words[i].begin, _bag.words[i].end, beginDestination);
        beginDestination = copy(_bag.words[size - i].end, _bag.words[size - i + 1].begin, beginDestination);
    }

    copy(_bag.words[0].begin, _bag.words[0].end, beginDestination);
}

#endif //PROJECT_WORDSREVERSEORDER_H
