//
// Created by Григорий on 05.03.2022.
//

#ifndef PROJECT_REVERSEWORDORDERINASTRING_H
#define PROJECT_REVERSEWORDORDERINASTRING_H

void reverseWordOrderInAString(char *s) {
    char *beginDestination = s;
    size_t size = strlen_(s);


    char *beginSearch = copy(s, s + size + 1, _stringBuffer) - 2;
    char *endSearch = _stringBuffer - 1;

    WordDescriptor word;
    while (getWordReverse(beginSearch, endSearch, &word)) {
        beginDestination = copy(word.begin, word.end, beginDestination);
        *(beginDestination++) = ' ';

        beginSearch = word.begin - 1;
    }

    if (beginDestination > s) {
        *(--beginDestination) = '\0';
    }
}

#endif //PROJECT_REVERSEWORDORDERINASTRING_H
