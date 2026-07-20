#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t *raw_file_data; 

void read_file (FILE *file);
int get_file_size (FILE *file);
void print_hex (FILE *file);

int main(int argc, char** argv)
{ 
  FILE *file;
  if (argc == 2)
  {
    file = fopen(argv[1], "r"); // opening the file only for read for now
    if (!file) {printf ("The file: %s could not be opened.\n", *argv); return 1;}
  }
  else {printf ("Usage ./<output_filename> <file_to_read>\n"); return 1;}

  read_file (file);
  print_hex (file);
  
  fclose(file);
  return 0;
}

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

void print_hex (FILE *file)
{
  int i = 0;
  while (i < get_file_size(file))
  {
    printf ("%02X%02X ", raw_file_data[i],  raw_file_data[i+1]);
    i += 2;
  }
}
