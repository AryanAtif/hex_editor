#include <stdio.h>


int main(int argc, char** argv)
{
  if (argc == 2)
  {
    FILE *file = fopen(*argv, "rb"); // opening the file only for read for now
    if (!file) {printf ("The file: %s could not be opened.\n", *argv);}
  }
  else printf ("Usage ./<output_filename> <file_to_read>\n");

  return 0;
}
