#include <ncurses.h>
#include <array.h>

void arraySize(Array *ptr) {
  initscr();
  do {
    clear();
    printw("- Random Character Generator -\n"
    "Enter the length desired [unsigned integers only]: ");
    refresh();
    scanw("%i", &(ptr->length));

    if(ptr->length > 0) break;
    printw("Value unknown.\n");
    refresh();
    napms(500);
  } while(ptr->length < 1);
}

void arrayType(Array *ptr) {
	unsigned int short n;
  do {
    clear();
    printw("Select the option specified below to generate:\n"
    "1 - lower [a-z]\n"
    "2 - upper [A-Z]\n"
    "3 - numbers [0-9]\n"
    "4 - symbols ['!@#$...]\n");
    refresh();
    scanw("%hi", &(n));
	if(n%10 < 5 && (n/10) % 10 < 5 && (n/100) % 10 < 5 && (n/1000) % 10 < 5) break;

    printw("Option unknown!\n");
    refresh();
    napms(500);
  } while("false");
  while(n){
	ptr->flags |= 1<<(n%10);
	n /= 10;
  }
  arrayCreation(ptr);
}

void arrayOutput(Array *ptr) {
  do{
  clear();
  printw("Selected characters: %s\n"
  "%i characters has been generated: %s\n"
  "Size in bits: %i\n\n"
  "Press \"s\" to start over\n"
  "Press \"r\" to recreate\n"
  "Press any other key to exit...",
  ptr->genArray, ptr->count, ptr->genChar, ptr->count * 8);
  refresh();
  ptr->choice = getch();
  arrayFree(ptr);
  if(ptr->choice == 's'){
	ptr->length = ptr->type = 0;
    ptr->length = 0;
    ptr->type = 0;
    arraySize(ptr);
    arrayType(ptr);
  }
  else if(ptr->choice == 'r'){
	arrayCreation(ptr);
  }
  } while (ptr->choice == 's' || ptr->choice == 'r');

  endwin();
}

