#ifndef UI_H
#define UI_H

void ui_clear(void);
void ui_title(const char *title);
void ui_footer(const char *text);
void ui_wait(void);
void ui_line(short y, const char *text);

#endif
