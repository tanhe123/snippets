/*
 * pattern-finding program
 *
 * optional arguments:
 * -x (for "except") to signal the inversion, and -n ("number") to request line numbering, then the command
 * find -x -n pattern
 * will print each line that doesn't match the pattern, preceded by its line number.
 *
 * optional arguments should be permitted in any order.
 * Furthermore, it is convenient for users if option arguments can be combined, as in find -nx pattern
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')   //如果合法最后argc肯定会为1
        while ((c = *++argv[0]))
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }

    if(argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (fgets(line, MAXLINE, stdin) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }

    return found;
}
