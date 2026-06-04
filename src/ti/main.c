#define USE_TI89
#define SAVE_SCREEN

#include <tigcclib.h>
#include "ui.h"
#include "screens.h"

static void show_main_menu(void)
{
    ui_clear();
    ui_title("QUANTUM89");

    ui_line(16, "1. Tarea 1 Luz");
    ui_line(28, "2. Tarea 2 Oper");
    ui_line(40, "3. Tarea 3 Caja");
    ui_line(52, "4. Constantes");
    ui_line(64, "5. Errores");
    ui_line(76, "6. About");

    ui_footer("1-6 elegir | ESC salir");
}

void _main(void)
{
    short key;

    while (1)
    {
        show_main_menu();
        key = ngetchx();

        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                screen_task1_menu();
                break;

            case '2':
                screen_task2_menu();
                break;

            case '3':
                screen_task3_menu();
                break;

            case '4':
                screen_constants();
                break;

            case '5':
                screen_errors();
                break;

            case '6':
                screen_about();
                break;

            default:
                break;
        }
    }
}
