#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "file_io.h"

int get_file_size (FILE *file)
{
  fseek (file, 0, SEEK_END);
  int file_size = ftell (file);
  fseek (file, 0, SEEK_SET);

  return file_size;
}

void read_file (FILE *file)
{
  int file_size = get_file_size(file);
  
  raw_file_data = (uint8_t *) malloc (file_size * sizeof (uint8_t));
  fread (raw_file_data, sizeof (uint8_t), file_size, file);
}
