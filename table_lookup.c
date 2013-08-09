/*
 * Table Lookup
 * 详见<<C程序设计语言>>(英文版*第二版) P143)
 *
 * This code is typical of what might be found in the symbl table
 * management routines of a macro processor or a compiler.
 * For example, consider the #define statment. When a line like
 * #define IN 1
 * is encountered, the name IN and the replacement text 1 are stored in a table.
 * Later, when the name IN appears in a statement like
 * state  IN;
 * it must be replaced by 1.
 *
 * There are two routines that manipulate the names and replacement texts.
 * install(s, t) records the name s and the replacement text t in a table;
 * s and t are just character strings. lookup(s) searches for s in the table,
 * and return a pointer to a place where it was found,
 * or NULL if it wasn't there.
 *
 * The algorithm is a hash search-the incoming name is converted into a small non-negative integer,
 * which is then used to index into an array of pointers.
 * An array element points to the begining of a linked list of blocks describing names that have that hash value.
 *
 * It is NULL if no names have hashed to that value.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];// pointer table

struct nlist {			//table entry:
    struct nlist *next;		// next entry in chain
    char *name;			// defined name
    char *defn;			// replacement text
};

char *_strdup(char *s) {	 //make a duplicate of a
    char *p;

    p = (char *)malloc(sizeof(strlen(s))+1);
    if (p != NULL)
	strcpy(p, s);
    return p;
}

unsigned hash(char *s) {	//hash: form hash value for string s
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
	hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {	//lookup: look for s in hashtab
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	if (strcmp(s, np->name) == 0)
	    return np;
    return NULL;
}

// install: put (name, defn) in hashtab
struct nlist *install (char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {//not found
	np = (struct nlist *)malloc(sizeof(*np));
	if (np == NULL || (np->name = _strdup(name)) == NULL)
	    return NULL;
	hashval = hash(name);
	np->next = hashtab[hashval];
	hashtab[hashval] = np;
    }
    else
	free((void *) np->defn);	//free previous defn
    if((np->defn = _strdup(defn)) == NULL)
	return NULL;
    return np;
}

int main(int argc, char *argv[]) {
    struct nlist *np;
    
    install("tanhe", "haha");
    install("ni", "haoma");
    np = lookup("tanhe");
    printf("%s %s\n", np->name, np->defn);
    np = lookup("ni");
    printf("%s %s\n", np->name, np->defn);
    
    return 0;
}
