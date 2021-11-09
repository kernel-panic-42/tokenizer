
#include <stdlib.h>
#include <string.h>

static char* string = NULL;
static char* sp = NULL;
static char delim;
static size_t len;

/* allocate memory for tokenizable string */
int tokenize(const char* s, char d, size_t l) {
    delim = d;
    len = l;
    string = malloc(len + 1);
    if (string == NULL)
        return -1;
    sp = string;
    strcpy(string, s);
    return (int)len;
}

/* return the next token string evaluating the delimiter */
int next_token(char* token) {
    size_t i;
    if (*sp == '\0' || sp == NULL)
        return -1;
    for (i = 0; *sp != delim && *sp != '\0' && (*token++ = *sp++); i++)
        ;
    *token = '\0';
    if (*sp == delim)
        sp++;
    return i;
}

/* house keeping   */
void free_tokenizer(void) {
    if (string != NULL) {
        free(string);
        string = NULL;
        sp = NULL;
    }
}