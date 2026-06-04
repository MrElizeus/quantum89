#define USE_TI89
#define SAVE_SCREEN

#include <tigcclib.h>
#include "ui.h"
#include "screens.h"

static const char *main_items[] = {
    "Tarea 1 Luz",
    "Tarea 2 Oper",
    "Tarea 3 Caja",
    "Constantes",
    "Errores",
    "About"
};

void _main(void)
{
    short sel;

    while (1)
    {
        sel = ui_menu("QUANTUM89", main_items, 6);

        if (sel == -1)
            break;

        switch (sel)
        {
            case 0: screen_task1_menu(); break;
            case 1: screen_task2_menu(); break;
            case 2: screen_task3_menu(); break;
            case 3: screen_constants(); break;
            case 4: screen_errors(); break;
            case 5: screen_about(); break;
        }
    }
}
