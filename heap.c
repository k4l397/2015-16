#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

// Allocates space given a gap (current item in ring), and size of gap needed
// It will split the gap accordingly if needed.
void allocSpace(ring *r, int size, int index){
    // item {int index, size; bool used};
    item current = get(r);
    item newUsed = {index, size, true};
    item newGap = {-1, current.size - size, false};
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

// Runs operation to allocate/free space in heap
// operation 0 = allocate space
// operation 1 = free space
// Size only applicable if allocating, set to -1 if freeing
void runOperation(ring *r, int operation, int index, int size){
    if(operation == 0){
        if(searchGap(r, size) == true) allocSpace(r, size, index);
        else printf("Error: Ran out of memory\n" );
    }
    else if(operation == 1){
        //TODO: Define search and freeSpace.
        if(search(r, index) == true) freeSpace(r, index);
    }
}

int main(){
    ring *heap = newRing();
    // newHeap = {first index, size of heap, space not allocated so false}
    item newHeap = {-1 , 128, false};
    addItem(heap, newHeap);
    start(heap);
    allocSpace(heap, 10, 0);
    start(heap);
    printf("%d %d %d\n", get(heap).index, get(heap).size, get(heap).used);
    next(heap);
    printf("%d %d %d\n", get(heap).index, get(heap).size, get(heap).used);
    return 0;
}
