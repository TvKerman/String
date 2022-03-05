//
// Created by Григорий on 05.03.2022.
//

#ifndef PROJECT_MERGINGSTRINGS_H
#define PROJECT_MERGINGSTRINGS_H

void mergingStrings(char *s, char *s1, char *s2) {
    char *beginDestination = s;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    char *beginSearch1 = s1;
    char *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            beginDestination = copy(word1.begin, word1.end, beginDestination);
            *(beginDestination++) = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            beginDestination = copy(word2.begin, word2.end, beginDestination);
            *(beginDestination++) = ' ';
            beginSearch2 = word2.end;
        }
    }
    *(--beginDestination) = '\0';
}

#endif //PROJECT_MERGINGSTRINGS_H
