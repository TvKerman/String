#include <stdio.h>
#include "string/string_.h"

int f(int a) {
    return '0' <= a && a <= '9';
}

int main() {
    char s[] = "000000000";
    char s1[] = "1234";

    printf("%c\n", *copyIfReverse(&s1[3], s1, s, f));
    printf("%s\n%s", s, s1);

    return 0;
}
