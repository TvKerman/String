//
// Created by Григорий on 05.03.2022.
//
#ifndef PROJECT_COUNTOFPALINDROMEWORDS_H
#define PROJECT_COUNTOFPALINDROMEWORDS_H

char* findNonComma(char *begin) {
    while (*begin == ',' && *begin != '\0') {
        begin++;
    }

    return begin;
}

char* findComma(char *begin) {
    while (*begin != ',' && *begin != '\0') {
        begin++;
    }

    return begin;
}

int getWordComma(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonComma(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findComma(word->begin);
    return 1;
}


bool isPalindromeWords(WordDescriptor w) {
    w.end--;
    while (w.begin < w.end && *w.begin == *w.end) {
        w.begin++;
        w.end--;
    }

    return (w.begin >= w.end);
}

int countOfPalindromeWords(char *s) {
    WordDescriptor word;
    char *beginSearch = s;

    int count = 0;
    while (getWordComma(beginSearch, &word)) {
        beginSearch = word.end;

        count += isPalindromeWords(word);
    }

    return count;
}

#endif //PROJECT_COUNTOFPALINDROMEWORDS_H
