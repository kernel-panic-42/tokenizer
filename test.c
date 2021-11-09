#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int main(void) {
    char* s =
        "Darwin,Harris,Hitch,Dawkins,Einstein,In hell I'll be in good company";
    char t[256];
    size_t len = strlen(s);
    tokenize(s, ',', len);
    while (next_token(t) > 0)
        printf("%s\n", t);
    free_tokenizer();
    return 0;
}