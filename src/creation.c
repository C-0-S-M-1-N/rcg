#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array.h>
#include <stdbool.h>
#include <string.h>

void arrayCreation(Array *ptr){
	const char lower_case[]	= "abcdefghijklmnopqrstuvwxyz",
			   upper_case[]	= "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			   digits[] 	= "0123456789",
			   schars[] 	= "!@#$%&*()-_=+`{}[]^~<>,./?;:";
	arrayRandom(ptr);
	char full[200];
	int max_range = 0;
	if(ptr->flags & (1 << 1)){
		printw("f1 ");
		max_range += snprintf(full+max_range, 200, "%s", lower_case);
	}
	if(ptr->flags & (1 << 2)){
		printw("f2 ");
		max_range += snprintf(full+max_range, 200, "%s", upper_case);
	}

	if(ptr->flags & (1 << 3)){
		printw("f3 ");
		max_range += snprintf(full+max_range, 200, "%s", digits);
	}
	if(ptr->flags & (1 << 4)){
		printw("f4 ");
		max_range += snprintf(full+max_range, 200, "%s", schars);
	}
	ptr->genChar = malloc(ptr->length);
	for(ptr->count = 0; ptr->count < ptr->length; ++ptr->count){
		ptr->genChar[ptr->count] = full[rand() % max_range];	
	}
	ptr->genChar[ptr->length] = 0;
}

void arrayRandom(Array *ptr) {
  struct timespec ts;
  timespec_get(&ts, TIME_UTC);
  ptr->size = (ts.tv_nsec * ptr->count) - ptr->count;
  srand(ptr->size);
}

void arrayFree(Array *ptr) {
  free(ptr->genArray);
  free(ptr->genChar);
}
