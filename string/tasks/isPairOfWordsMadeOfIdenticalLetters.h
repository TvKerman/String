//
// Created by Григорий on 07.03.2022.
//

#ifndef PROJECT_ISPAIROFWORDSMADEOFIDENTICALLETTERS_H
#define PROJECT_ISPAIROFWORDSMADEOFIDENTICALLETTERS_H

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char*) a;
    char arg2 = *(const char*) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool isPairOfWordsMadeOfIdenticalLetters(char *s) {
    copy(s, s + strlen_(s) + 1, _stringBuffer);

    BagOfWords bag;
    getBagOfWords(&bag, _stringBuffer);

    if (bag.size == 0) {
        return false;
    }

    for (size_t i = 0; i < bag.size; i++) {
        qsort(bag.words[i].begin, bag.words[i].end - bag.words[i].begin, sizeof(char), compare_char);
    }

    for (size_t i = 0; i < bag.size - 1; i++) {
        for (size_t j = i + 1; j < bag.size; j++) {
            if (areWordsEqual(bag.words[i], bag.words[j]) == 0) {
                return true;
            }
        }
    }

    return false;
}

#endif //PROJECT_ISPAIROFWORDSMADEOFIDENTICALLETTERS_H
