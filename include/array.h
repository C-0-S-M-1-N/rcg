#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
  int size;
  int counter;
  int range;
  int count;
  unsigned int length;
  unsigned short int type, flags;
  char *genChar;
  char *genArray;
  char *chars;
  char choice;
} Array;

// creates a array and get the selected range of characters 
void arrayCreation(Array *ptr);

// get the size of the array
void arraySize(Array *ptr);

// get the elements for the array 
void arrayType(Array *ptr);

// prints the output of the generated characters
void arrayOutput(Array *ptr);

// repeat all or some process of other functions
void arrayRepeat(Array *ptr);

// get a seed for srand() according to Unix Time in nanoseconds
void arrayRandom(Array *ptr);

// free the allocatted memory from the used arrays
void arrayFree(Array *ptr);

#endif // ARRAY_H
