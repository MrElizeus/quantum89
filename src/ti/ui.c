#include <tigcclib.h>
#include "ui.h"

void ui_clear(void)
{
    ClrScr();
    FontSetSys(F_6x8);
}

void ui_title(const char *title)
{
    DrawStr(2, 2, title, A_REVERSE);
}

void ui_footer(const char *text)
{
    DrawStr(2, 92, text, A_NORMAL);
}

void ui_wait(void)
{
    ngetchx();
}

void ui_line(short y, const char *text)
{
    DrawStr(2, y, text, A_NORMAL);
}
