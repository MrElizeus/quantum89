#define USE_TI89
#define SAVE_SCREEN

#include <tigcclib.h>
#include "ui.h"
#include "screens.h"

static void show_main_menu(void)
{
    ui_clear();
    ui_title("QUANTUM89");

    ui_line(16, "1. Constantes");
    ui_line(28, "2. Foton");
    ui_line(40, "3. Caja 1D");
    ui_line(52, "4. About");

    ui_footer("1-4 elegir | ESC salir");
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
                screen_constants();
                break;

            case '2':
                screen_photon_demo();
                break;

            case '3':
                screen_box1d_demo();
                break;

            case '4':
                screen_about();
                break;

            default:
                break;
        }
    }
}
