//
// Created by Григорий on 07.03.2022.
//

#ifndef PROJECT_ISIDENTICALWORDSINSTRING_H
#define PROJECT_ISIDENTICALWORDSINSTRING_H

bool isIdenticalWordsInString(char *s) {
    BagOfWords bag;
    getBagOfWords(&bag, s);

    if (bag.size == 0) {
        return false;
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

#endif //PROJECT_ISIDENTICALWORDSINSTRING_H
