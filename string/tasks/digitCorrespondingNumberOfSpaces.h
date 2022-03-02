//
// Created by Григорий on 27.02.2022.
//

#ifndef PROJECT_DIGITCORRESPONDINGNUMBEROFSPACES_H
#define PROJECT_DIGITCORRESPONDINGNUMBEROFSPACES_H

void digitCorrespondingNumberOfSpaces(char *s) {
    size_t size = strlen_(s);
    char *endStringBuffer = copy(s, s + size + 1, _stringBuffer);

    char *_copyPointerStringBuffer = _stringBuffer;
    while (*_copyPointerStringBuffer != '\0') {
        if (isdigit(*_copyPointerStringBuffer)) {
            int number = *(_copyPointerStringBuffer++) - '0';
            for (int i = 0; i < number; i++) {
                *(s++) = ' ';
            }
        } else {
            *(s++) = *(_copyPointerStringBuffer++);
        }
    }
    *s = '\0';
}

#endif //PROJECT_DIGITCORRESPONDINGNUMBEROFSPACES_H
