#include <stdio.h>
#include "string/string_.h"

int main() {
    char s[] = "   ";
    char s1[] = " 1 1";
    printf("%d %d", *findNonSpace(s), *findNonSpace(s1));

    return 0;
}
