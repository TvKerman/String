//
// Created by Григорий on 27.02.2022.
//

#ifndef PROJECT_REMOVEEXTRASPACES_H
#define PROJECT_REMOVEEXTRASPACES_H

void removeExtraSpaces(char *s) {
    if (*s == '\0') {
        return;
    }

    char previous = *(s++);
    char *pWrite = s;
    while (*s != '\0') {
        if (*s != ' ' || (*s == ' ' && previous != ' ')) {
            previous = *s;
            *(pWrite++) = *(s++);
        } else {
            previous = *s;
            s++;
        }
    }
    *pWrite = '\0';
}

#endif //PROJECT_REMOVEEXTRASPACES_H
