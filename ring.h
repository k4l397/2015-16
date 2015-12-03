#include <stdbool.h>

// Change this to change the type of the item used in the ring. Uncommment and
// adapt the following for doubles, ints, fixed size strings, variable strings
// as pointers, structures, or pointers to structures.
typedef double item;
// typedef int item;
// typedef char *item;
// typedef struct x item;
// typedef struct x *item;

// The type of a ring.
struct ring;
typedef struct ring ring;

// When called, returns a new ring with just a sentinel node.
ring *newRing();

// Adds a node with item x to the ring r.
void addNode(ring *r, item x);

// Gets the item at the current position in the ring.
item get(ring *r);

// Moves the current position to the start of the ring.
void start(ring *r);

// Moves the current position to the next item in the ring.
void next(ring *r);

// Test if the current position is at the end of the ring.
bool end(ring *r);
