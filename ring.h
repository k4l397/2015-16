#include <stdbool.h>

// Defines what is included in an item.
struct object{
    int index, size;
    bool used;
};
typedef struct object item;

// The type of a ring.
struct ring;
typedef struct ring ring;

// When called, returns a new ring.
ring *newRing();

// Adds an item x to the ring r after the current position.
void addItem(ring *r, item x);

// Remove current item from list. Moves current pointer back to previous item.
void removeItem(ring *r);

// Gets the item at the current position in the ring.
item get(ring *r);

// Moves the current pointer to the start of the ring.
void start(ring *r);

// Moves the current pointer to the next item in the ring.
void next(ring *r);

// Moves the current pointer to the previous item in the ring.
void prev(ring *r);

// Test if the current pointer is pointing to end of the ring.
bool end(ring *r);
