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

void addNode(ring *r, item x){
    node *new = malloc(sizeof(node));
    new->x = x;
    new->next = r->current;
    new->prev = r->current->prev;
    r->current->prev = new;
}

void addItem(ring *r, item x){
    addNode(r, x);
}

void removeNode(ring *r){
    node *newCurrent;
    node *newNext;
    newCurrent = r->current->prev;
    newNext = r->current->next;
    newCurrent->next = newNext;
    newNext->prev = newCurrent;
    free(r->current);
    r->current = newCurrent;
}

void removeItem(ring *r){
    removeNode(r);
}

item get(ring *r){
    return r->current->x;
}

void start(ring *r){
    r->current = r->sentinel->next;
}

void next(ring *r){
    r->current = r->current->next;
}

bool end(ring *r){
    if(r->current->next == r->sentinel) return true;
    return false;
}
