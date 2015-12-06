#include "ring.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *prev;
    struct node *next;
    item x;
};
typedef struct node node;

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
    new->next = r->current;
    new->prev = r->current->prev;
    r->current->prev->next = new;
    r->current->prev = new;
}

void removeItem(ring *r){
    if(r->current != r->sentinel){
        node *newCurrent;
        node *newNext;
        newCurrent = r->current->prev;
        newNext = r->current->next;
        newCurrent->next = newNext;
        newNext->prev = newCurrent;
        free(r->current);
        r->current = newCurrent;
    }
}

item getItem(node *n){
    return n->x;
}

item get(ring *r){
    return getItem(r->current);
}

void start(ring *r){
    r->current = r->sentinel->next;
}

void next(ring *r){
    r->current = r->current->next;
}

bool end(ring *r){
    if(r->current == r->sentinel) return true;
    return false;
}
