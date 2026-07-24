#ifndef FILE_IO_H
#define FILE_IO_H

extern uint8_t *raw_file_data; 

int get_file_size (FILE *file);
void read_file (FILE *file);

#endif
