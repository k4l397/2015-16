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

int main(){

}
