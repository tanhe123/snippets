/*
 * Our version of getint returns EOF for end of file, zeo if the next input is not a number, and a positive value
 * if the input contains a valid number.
 * As written, getint treats a + or - not followed by a digit as a valid representation of zero.


int getint(int *pn) {
    int c, sign;

    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
