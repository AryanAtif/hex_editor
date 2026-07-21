#ifndef UI_H 
#define UI_H

void init_ui ();
void display (char* window_name); // window_name: hex, ascii-char, etc etc 
WINDOW* init_hex_window();
WINDOW* create_window (int height, int width, int beginy, int beginx);

#endif
