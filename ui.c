/*
 * Configure the ncurses UI 
 */
#include <ncurses.h>
#include <string.h>
#include <math.h>

#include "ui.h"
#include "file_io.h"

void init_ui ()
{
  initscr();
  raw();
  curs_set(0); keypad (stdscr, TRUE);
}
void display (char* window_name) // window_name: hex, ascii-char, etc etc 
{
  WINDOW* window;
  if (window_name = "hex") // if we're supposed to display the data from the hex window
  {
    window = init_hex_window();
  }

  int i = 0;
  while (i < strlen (raw_file_data))
  {
    wprintw (window, "%02X%02X ", raw_file_data[i],  raw_file_data[i+1]);
    i+=2;
  }
  wrefresh(window);
  getch();
}

WINDOW* init_hex_window()
{
  int rows, columns;
  getmaxyx (stdscr, rows, columns);
  refresh();
  
  int text_size = strlen(raw_file_data);
  int each_row_length = 4 * 8 + 7 /*space between chars */ + 1 /* space before each row c_n */ + 2 /*chars needed to draw left-right borders*/;
  int row_count = 2 * ceil(text_size / each_row_length + (7 /*+ 1 + 2*/));

  WINDOW* hex_win = create_window (row_count, each_row_length, (rows-row_count)/2, (columns-each_row_length)/2);
  return hex_win;

}

WINDOW* create_window (int height, int width, int beginy, int beginx)
{
  WINDOW* br_window = newwin(height, width, beginy, beginx); // the borders for the real content window
  WINDOW* content_window = newwin(height - 4, width - 4, beginy + 2, beginx + 2); // the actual window where we'd put our stuff in 
  
  box (br_window, 0, 0);
  wrefresh(br_window);
  box (content_window, 0, 0);
  wrefresh(content_window);
  return content_window;
}
