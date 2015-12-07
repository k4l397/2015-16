#include "ring.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *prev;
    struct node *next;
    item x;
};
typedef struct node node;

static void fail(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

struct ring{
    node *sentinel;
    node *current;
};

node *makeSentinel(){
    node *sentinel = malloc(sizeof(node));
    sentinel->prev = sentinel;
    sentinel->next = sentinel;
    return sentinel;
}

ring *newRing(){
    ring *r = malloc(sizeof(ring));
    r->sentinel = makeSentinel();
    r->current = r->sentinel;
    return r;
}

void addItem(ring *r, item x){
    node *new = malloc(sizeof(node));
    new->x = x;
    new->next = r->current->next;
    new->prev = r->current;
    r->current->next = new;
}

void removeItem(ring *r){
    if(r->current == r->sentinel) fail("Cannot delete the sentinel");
    node *newCurrent = r->current->prev;
    node *newNext = r->current->next;
    newCurrent->next = newNext;
    newNext->prev = newCurrent;
    free(r->current);
    r->current = newCurrent;
}

item getItem(node *n){
    return n->x;
}

item get(ring *r){
    if(r->current == r->sentinel) fail("No item in the sentinel");
    return getItem(r->current);
}

void start(ring *r){
    r->current = r->sentinel->next;
}

void next(ring *r){
    r->current = r->current->next;
}

void prev(ring *r){
    r->current = r->current->prev;
}

bool end(ring *r){
    if(r->current == r->sentinel) return true;
    return false;
}
