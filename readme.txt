The heap.c file is meant to demonstrate the heap memory allocation described
on the assignment page. I didn't quite get on to create a function to interpret
a call, but I planned to get one that would return an operation code, index of
variable and size of variable to be stored.

The main functionality of the program can be tested with runOperation:
runOperation(ring, operation code, index of variable, size of variable)
Operation code => 0 = malloc, 1 = free. For free the size of the variable
doesn't matter, as a place holder I used -1.

The output can be checked by printing the heap with printRing(heap).
