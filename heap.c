#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

// Allocates space given a gap (current item in ring), and size of gap needed
// It will split the gap accordingly if needed.
void allocSpace(int size, ring *r){
    // item {int index, size; bool used};
    item current = get(r);
    item newUsed = {current.index, size, true};
    item newGap = {current.index+1, current.size - size, false};
    removeItem(r);
    addItem(r, newUsed);
    next(r);
    if(newGap.size > 0) addItem(r, newGap);
}

// Searches for gap large enough. Returns true if gap found, false otherwise.
// Sets current item in ring to the gap.
bool searchGap(ring *r, int size){
    start(r);
    item current;
    while(end(r) != true){
        current = get(r);
        if(size <= current.size) return true;
    }
    return false;
}

int main(){
    ring *heap = newRing();
    // newHeap = {first index, size of heap, space not allocated so false}
    item newHeap = {0, 128, false};
    addItem(heap, newHeap);
    start(heap);
    allocSpace(10, heap);
    start(heap);
    printf("%d %d %d\n", get(heap).index, get(heap).size, get(heap).used);
    next(heap);
    printf("%d %d %d\n", get(heap).index, get(heap).size, get(heap).used);
    return 0;
}
