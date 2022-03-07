//
// Created by Григорий on 07.03.2022.
//

#ifndef PROJECT_GETSTRINGFROMTHEWORDSOFDIFFERENTFROMTHELASTWORD_H
#define PROJECT_GETSTRINGFROMTHEWORDSOFDIFFERENTFROMTHELASTWORD_H

void getStringFromTheWordsOfDifferentFromTheLastWord (char *s, char *newString) {
    WordDescriptor lastWord;
    if (!getWordReverse(s + strlen_(s) - 1, s - 1, &lastWord)) {
        return;
    }

    char *beginSearch = s;
    char *beginDestination = newString;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        if (areWordsEqual(word, lastWord) != 0) {
            beginDestination = copy(word.begin, word.end, beginDestination);
            *(beginDestination++) = ' ';
        }
        beginSearch = word.end;
    }

    *(--beginDestination) = '\0';
}

#endif //PROJECT_GETSTRINGFROMTHEWORDSOFDIFFERENTFROMTHELASTWORD_H
