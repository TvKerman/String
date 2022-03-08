//
// Created by Григорий on 08.03.2022.
//

#ifndef PROJECT_ISEACHLETTEROFTHEWORDINCLUDEDINTHESTRING_H
#define PROJECT_ISEACHLETTEROFTHEWORDINCLUDEDINTHESTRING_H

#define COUNT_OF_CODES 256

bool isEachLetterOfTheWordIncludedInTheString(char *s, char *w) {
    int codesLettersInString[COUNT_OF_CODES] = {0};
    int codesLettersInWord[COUNT_OF_CODES] = {0};

    while (*w != '\0') {
        codesLettersInWord[*w] = 1;
        w++;
    }

    while (*s != '\0') {
        codesLettersInString[*s] = 1;
        s++;
    }

    for (int i = 0; i < COUNT_OF_CODES; i++) {
        if (codesLettersInWord[i] && !codesLettersInString[i]) {
            return false;
        }
    }

    return true;
}

#endif //PROJECT_ISEACHLETTEROFTHEWORDINCLUDEDINTHESTRING_H
