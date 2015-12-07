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

// Joins together the gaps of current gap and next or previous gap
// if nextOrPrev == 0 then next, if nextOrPrev == 1 then previous
void joinGaps(ring *r, int nextOrPrev){
    int totalSize = get(r).size;
    if(nextOrPrev == 0) {
        next(r);
        totalSize = totalSize + get(r).size;
        removeItem(r);
        removeItem(r);
    }
    else {
        prev(r);
        totalSize = totalSize + get(r).size;
        removeItem(r);
        next(r);
        removeItem(r);
    }
    item newGap = {-1, totalSize, false};
    addItem(r, newGap);
    next(r);
}

// Free's space at the current position in the ring
// Joins gap together if necessery
void freeSpace(ring *r){
    item current = get(r);
    current.used = false;
    addItem(r, current);
    removeItem(r);
    if(get(r).used == false){
        next(r);
        joinGaps(r, 1);
    }
    else{
        next(r);
    }
    next(r);
    if(get(r).used == false){
        prev(r);
        joinGaps(r, 0);
    }
}

// Searches for gap large enough. Returns true if gap found, false otherwise.
// Sets current item in ring to the gap.
bool searchGap(ring *r, int size){
    start(r);
    item current;
    while(end(r) != true){
        current = get(r);
        if(size <= current.size && current.used == false) return true;
        next(r);
    }
    return false;
}

// Searches for a given index of a variable in the heap
bool searchIndex(ring *r, int index){
    start(r);
    item current;
    while(end(r) != true){
        current = get(r);
        if(current.index == index && current.used == true) return true;
        next(r);
    }
    return false;
}

// Runs operation to allocate/free space in heap
// operation 0 = allocate space
// operation 1 = free space
// Size doesn't matter if freeing space - can be set to -1
void runOperation(ring *r, int operation, int index, int size){
    if(operation == 0){
        if(searchGap(r, size) == true) allocSpace(r, size, index);
        else printf("Error: Ran out of memory\n" );
    }
    else if(operation == 1){
        if(searchIndex(r, index) == true) freeSpace(r);
    }
}

void printRing(ring *r){
    start(r);
    item x;
    while(end(r) != true){
        x = get(r);
        printf("%d %d %s\n", x.index, x.size, x.used ? "true" : "false");
        next(r);
    }
}

//TODO:
// - Interpret call function that will return operation code 0 or 1
// args of index and size.

int main(int argc, char *argv[]){
    ring *heap = newRing();
    // newHeap = {first index, size of heap, space not allocated so false}
    item newHeap = {-1 , 1024, false};
    addItem(heap, newHeap);
    // Example test below, still need function that will interprets a call
    // runOperation(ring, operation code, index of variable, size of variable)
    runOperation(heap, 0, 0, 128);
    runOperation(heap, 0, 1, 256);
    runOperation(heap, 0, 2, 64);
    printRing(heap);
    printf("----\n");
    runOperation(heap, 1, 1, -1);
    runOperation(heap, 1, 2, -1);
    printRing(heap);
    return 0;
}
