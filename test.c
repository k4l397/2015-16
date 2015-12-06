#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

void printList(ring *r){
    start(r);
    while(end(r) != true){
        printf("%d\n", get(r));
        next(r);
    }
}

void addNumbers(ring *r, int x){
    for(int i = 0; i < x; i++){
        addItem(r, i);
    }
}

int main(){
    ring *r = newRing();
    addNumbers(r, 10);
    printList(r);
}
