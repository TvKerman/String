//
// Created by Григорий on 06.03.2022.
//

#ifndef PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
#define PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag1;
    getBagOfWords(&bag1, s1);

    BagOfWords bag2;
    getBagOfWords(&bag2, s2);

    WordDescriptor saveWord;
    if (bag1.size == 0 || bag2.size == 0) {
        saveWord = (WordDescriptor){s1, s1};
        return saveWord;
    }

    bool noIdenticalWords = true;
    for (size_t i = 0; i < bag1.size; i++) {
        for (size_t j = 0; j < bag2.size; j++) {
            if (areWordsEqual(bag1.words[i], bag2.words[j]) == 0) {
                noIdenticalWords = false;
                saveWord = bag1.words[i];
            }
        }
    }

    if (noIdenticalWords) {
        saveWord = (WordDescriptor){s1, s1};
    }

    return saveWord;
}

#endif //PROJECT_LASTWORDINFIRSTSTRINGINSECONDSTRING_H
