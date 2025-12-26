#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Loop {
    char key[50];
    int num;
    struct Loop *next;
};

struct HashMap {
    struct Loop *niz[10];
};
int ahash(char *s) {
    return s[0] % 10;
}

void put(struct HashMap *h, char *k, int v) {
    int index = ahash(k);
    
    struct Loop *new = malloc(sizeof(struct Loop));
    strcpy(new->key, k);
    new->num = v;
    new->next = NULL;

    if (h->niz[index] == NULL) {
        h->niz[index] = new;
    } else {
        new->next = h->niz[index];
        h->niz[index] = new;
    }
}

int find(struct HashMap *h, char *k) {
    int index =ahash(k);
    struct Loop *current = h->niz[index];

    while (current != NULL) {
        if (strcmp(current->key, k) == 0) {
            return current->num;
        }
        current = current->next;
    }
}

int main() {
    struct HashMap m;
    for(int i=0; i<10; i++) m.niz[i] = NULL;

    put(&m, "Dickson Myaz", 25);
    put(&m, "Dill Doe", 20);

    printf("Dickson Myaz: %d\n", find(&m, "Dickson Myaz"));
    printf("Dill Doe: %d\n", find(&m, "Dill Doe"));

    return 0;
}