#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>

#include "file_io.h"
#include "ui.h"

uint8_t *raw_file_data; 

int main(int argc, char** argv)
{ 
  FILE *file;
  if (argc == 2)
  {
    file = fopen(argv[1], "r"); // opening the file only for read for now
    if (!file) {printf ("The file: %s could not be opened.\n", argv[1]); return 1;}
  }
  else {printf ("Usage: ./<output_filename> <file_to_read>\n"); return 1;}

  init_ui();

  read_file (file);
//  display (0); // print the address window
  display (1); // print the hex window
  

  fclose(file);
  endwin();
  return 0;
}
