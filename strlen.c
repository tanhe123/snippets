/* 
 * computes the length of a string
 */
 
int strlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

/* 
 * another version of strlen
 */
 
int strlen(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;
    return p-s;
}
