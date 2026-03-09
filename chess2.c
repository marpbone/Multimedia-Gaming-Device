
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "game.h"

 void draw_chess_board(){ 
	GLCD_SetBackColor(Black);
  GLCD_SetTextColor(White);

	GLCD_DisplayString (0, 4, 1, "   |   |   |   ");
	GLCD_DisplayString (1, 4, 1, "               ");
	GLCD_DisplayString (2, 4, 1, "_ _|_ _|_ _|_ _");
	GLCD_DisplayString (3, 4, 1, "   |   |   |   ");
	GLCD_DisplayString (4, 4, 1, "               ");
  GLCD_DisplayString (5, 4, 1, "_ _|_ _|_ _|_ _");
	GLCD_DisplayString (6, 4, 1, "   |   |   |   ");
	GLCD_DisplayString (7, 4, 1, "               ");
	GLCD_DisplayString (8, 4, 1, "   |   |   |   ");
 }

int chess(void)
{
    int joystick_val = 0;
    int joystick_prev = 0;
	
		int chess_x = 5;        // starting at col 0
		int chess_y = 1;        // starting at row 0

		int chess_max_x = 17;   // last column
		int chess_max_y = 10;   // last row

		int chess_placeholder[20][20] = {0}; // store board state



  
		
		KBD_Init();
    LED_Init ();
		GLCD_Init();
    GLCD_Clear(Black);
    draw_chess_board(); 

		  memset(chess_placeholder, 0, sizeof(chess_placeholder));
    SysTick_Config(SystemCoreClock/100);

    while (1)
    {
        joystick_val = get_button();

        if (joystick_val != joystick_prev)
        {
            if (joystick_val == KBD_DOWN)
            {
                GLCD_DisplayString(chess_y+1, chess_x, 1, " ");
                if (chess_y < chess_max_y) chess_y += 3;
            }
            else if (joystick_val == KBD_UP)
            {
                GLCD_DisplayString(chess_y+1, chess_x, 1, " ");
                if (chess_y > 1) chess_y -= 3;
            }
            else if (joystick_val == KBD_RIGHT)
            {
                GLCD_DisplayString(chess_y+1, chess_x, 1, " ");
                if (chess_x < chess_max_x) chess_x += 4;
            }
            else if (joystick_val == KBD_LEFT)
            {
                GLCD_DisplayString(chess_y+1, chess_x, 1, " ");
                if (chess_x > 5) chess_x -= 4;
            }
            else if (joystick_val == KBD_SELECT)
            {
                if (chess_placeholder[chess_y][chess_x] == 0)
                {
                    GLCD_DisplayChar(chess_y, chess_x, 1, 'N');
                    chess_placeholder[chess_y][chess_x] = 1;
                }
            }

            GLCD_DisplayChar(chess_y+1, chess_x, 1, 0x85);
            joystick_prev = joystick_val;
        }
    }
}
