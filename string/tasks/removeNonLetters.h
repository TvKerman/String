//
// Created by Григорий on 26.02.2022.
//

#ifndef STRING_REMOVENONLETTERS_H
#define STRING_REMOVENONLETTERS_H



int isgraph(int a) {
    return a != ' ';
}

char* getEndOfString(char *s) {
    return s + strlen_(s);
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif //STRING_REMOVENONLETTERS_H
