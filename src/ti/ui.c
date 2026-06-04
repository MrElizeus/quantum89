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

short ui_wait_key(void)
{
    return ngetchx();
}

void ui_line(short y, const char *text)
{
    DrawStr(2, y, text, A_NORMAL);
}

short ui_menu(const char *title, const char **items, short count)
{
    short cursor = 0;
    short key;
    short i;

    while (1)
    {
        ClrScr();
        FontSetSys(F_6x8);
        DrawStr(2, 2, title, A_REVERSE);

        for (i = 0; i < count; i++)
            DrawStr(6, 16 + i * 12, items[i], i == cursor ? A_REVERSE : A_NORMAL);

        DrawStr(2, 92, "Flechas ENTER ESC", A_NORMAL);

        key = ngetchx();

        if (key == KEY_DOWN && cursor < count - 1)
            cursor++;
        else if (key == KEY_UP && cursor > 0)
            cursor--;
        else if (key == KEY_ENTER)
            return cursor;
        else if (key == KEY_ESC)
            return -1;
    }
}
