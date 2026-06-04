#include <tigcclib.h>
#include "ui.h"
#include "screens.h"

static int task2_page_pause(void)
{
    return ui_wait_key() != KEY_ESC;
}

static void task2_operators(void)
{
    ui_clear();
    ui_title("OPERADORES");
    ui_line(14, "A f = g");
    ui_line(24, "Ej: d3/dx3 + x^3");
    ui_line(34, "g = f''' + x^3*f");
    ui_line(48, "operador actua");
    ui_line(60, "sobre la funcion");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("OPERADOR ACTUA");
    ui_line(14, "A no es numero");
    ui_line(26, "necesita una f");
    ui_line(38, "calcula A(f)");
    ui_line(50, "luego simplifica");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("OPERADORES");
    ui_line(14, "LAPLACIANO:");
    ui_line(24, "nabla2 f =");
    ui_line(34, "fxx + fyy + fzz");
    ui_line(50, "derivadas suman");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task2_eigenfunctions(void)
{
    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(14, "A f = lambda f");
    ui_line(24, "misma forma: si");
    ui_line(36, "cambia forma: no");
    ui_line(50, "lambda es valor");
    ui_line(62, "medible si herm");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(24, "PASOS:");
    ui_line(34, "1 aplicar A");
    ui_line(44, "2 simplificar");
    ui_line(54, "3 factorizar f");
    ui_line(64, "4 lambda = factor");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(14, "d2/dx2 cos(wx)");
    ui_line(24, "= -w^2 cos(wx)");
    ui_line(36, "lambda = -w^2");
    ui_line(52, "patron fijo");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(14, "d/dt exp(iwt)");
    ui_line(24, "= iw exp(iwt)");
    ui_line(36, "lambda = iw");
    ui_line(52, "fase compleja");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(14, "(d2+2d+3)exp(ax)");
    ui_line(24, "= (a^2+2a+3)exp(ax)");
    ui_line(38, "lambda = a^2+2a+3");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("AUTOFUNCIONES");
    ui_line(14, "d/dy x^2 exp(6y)");
    ui_line(24, "= 6 x^2 exp(6y)");
    ui_line(36, "lambda = 6");
    ui_line(52, "x^2 solo acompana");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task2_commutators(void)
{
    ui_clear();
    ui_title("CONMUTADORES");
    ui_line(14, "[A,B] = AB - BA");
    ui_line(24, "usar phi:");
    ui_line(34, "[A,B]phi =");
    ui_line(44, "A(Bphi)-B(Aphi)");
    ui_line(58, "comparar orden");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONM METODO");
    ui_line(14, "1 escribe phi");
    ui_line(24, "2 calcula ABphi");
    ui_line(34, "3 calcula BAphi");
    ui_line(44, "4 resta");
    ui_line(56, "0 => compatibles");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONMUTADORES");
    ui_line(14, "A = d2/dx2");
    ui_line(24, "B = x");
    ui_line(36, "A(Bphi)=d2(xphi)/dx2");
    ui_line(48, "B(Aphi)=x phi''");
    ui_line(60, "restar y cancelar");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONMUTADORES");
    ui_line(14, "[A,A] = 0");
    ui_line(24, "si A = B");
    ui_line(40, "mismo orden");
    ui_line(52, "sin cambio");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONMUTADORES");
    ui_line(14, "int[0,x] dphi/dt dx");
    ui_line(26, "vs");
    ui_line(36, "d/dt int[0,x] phi dx");
    ui_line(50, "conmutan si regular");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONMUTADORES");
    ui_line(14, "A = d2/dx2 - x");
    ui_line(24, "B = d/dt + x^2");
    ui_line(36, "expandir con phi");
    ui_line(48, "cancelar terminos");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CONM FISICA");
    ui_line(14, "[x,px]=i*hbar");
    ui_line(26, "[A,A]=0");
    ui_line(38, "[A,B]=0");
    ui_line(50, "medibles juntos");
    ui_line(62, "no cero: orden pesa");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task2_hermitian(void)
{
    ui_clear();
    ui_title("HERMITICOS");
    ui_line(14, "A_dag = A");
    ui_line(26, "dag: conj trans");
    ui_line(38, "valores reales");
    ui_line(50, "observable fisico");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("ADJUNTO");
    ui_line(14, "(AB)_dag =");
    ui_line(26, "B_dag A_dag");
    ui_line(38, "invierte orden");
    ui_line(50, "AB herm si conm");
    ui_line(62, "A,B hermiticos");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("SIMETRICA");
    ui_line(14, "si AB no herm:");
    ui_line(26, "(AB+BA)/2");
    ui_line(38, "es candidato herm");
    ui_line(50, "orden balanceado");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("MATRICES");
    ui_line(14, "A_ji=conj(A_ij)");
    ui_line(26, "real: simetrica");
    ui_line(38, "Av=lambda v");
    ui_line(50, "lambda real");
    if (!task2_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("MATRIZ CONM");
    ui_line(14, "[A,B]=AB-BA");
    ui_line(26, "multiplica ambos");
    ui_line(38, "compara entradas");
    ui_line(50, "cero: base comun");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task2_rules(void)
{
    ui_clear();
    ui_title("REGLAS CLAVE");
    ui_line(14, "1. aplicar A");
    ui_line(24, "2. usar phi");
    ui_line(34, "3. simplificar");
    ui_line(44, "4. factorizar");
    ui_line(56, "5. leer lambda");
    ui_line(68, "orden importa");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

void screen_task2_menu(void)
{
    static const char *items[] = {
        "Operadores",
        "Autofunciones",
        "Conmutadores",
        "Herm/Matrices",
        "Reglas clave"
    };
    short sel;

    while (1)
    {
        sel = ui_menu("TAREA 2", items, 5);

        if (sel == -1)
            break;

        switch (sel)
        {
            case 0: task2_operators(); break;
            case 1: task2_eigenfunctions(); break;
            case 2: task2_commutators(); break;
            case 3: task2_hermitian(); break;
            case 4: task2_rules(); break;
        }
    }
}
