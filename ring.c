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
    node *free;
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
    r->free = NULL;
    return r;
}

void addNode(ring *r, item x){
    node *new;
    if (r->free != NULL){
        new = r->free;
        r->free = new->next;
    }
    else new = malloc(sizeof(node));
    new->x = x;
    new->next = r->current;
    new->prev = r->current->prev;
    r->current->prev = new;
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
