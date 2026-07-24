#ifndef UI_H 
#define UI_H

void init_ui ();
void display (int window_id); // window_name: hex, ascii-char, etc etc 
WINDOW* init_hex_window();
WINDOW* create_window (int height, int width, int beginy, int beginx);

// Print Data of the Window
void print_hex (WINDOW* window);

#endif
