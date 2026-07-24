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
  curs_set(0);
  keypad (stdscr, TRUE);
  scrollok(stdscr, TRUE);

  refresh();

}
void display (int window_id) // window_id : address = 0, hex = 1, etc etc 
{
  WINDOW* window;
  if (window_id == 0) // Window ID = 0:  address window 
  {
  //  window = init_address_window();
  }
  else if (window_id == 1) // Window ID = 1:  hex window
  {
    window = init_hex_window();
  }

  int i = 0;
  while (i < strlen (raw_file_data))
  {
    if (i % 16 != 0) wprintw (window, " "); 
    wprintw (window, "%02X%02X", raw_file_data[i],  raw_file_data[i+1]);
    i+=2;
    
  }
  wrefresh(window);
  getch();
}

WINDOW* init_hex_window()
{
  int text_size = strlen(raw_file_data);
  int each_row_length = 4 * 8 + 7 /*space between chars */ + 2 /* space before each row c_n */ + 2 /*chars needed to draw left-right borders*/;
  int row_count = 2 * ceil(text_size / each_row_length + 8);

  WINDOW* hex_win = create_window (row_count, each_row_length, 2, 2); // create a window at (2,2)
  return hex_win;

}

WINDOW* create_window (int height, int width, int beginy, int beginx)
{
  WINDOW* br_window = newwin(height, width, beginy, beginx); // the borders for the real content window
  WINDOW* content_window = newwin(height - 4, width - 4, beginy + 1, beginx + 2); // the actual window where we'd put our stuff in 
  
  box (br_window, 0, 0);
  wrefresh(br_window);
  wrefresh(content_window);
  return content_window;
}

