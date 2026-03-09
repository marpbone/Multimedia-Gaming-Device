
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "game.h"


#include <LPC17xx.H>
#include "GLCD.h"
#include "KBD.h"
#include "LED.h"
#include <string.h>

    int x_chess = 5;
    int y_chess = 1;

    int joystick_val = 0;
    int joystick_prev = 0;


    // Knight start position
    int kx = 5;
    int ky = 1;

    int moves_chess = 0;

void print_error() {
    GLCD_SetBackColor(Red);
    GLCD_DisplayString(9, 0, 1, " Invalid Knight Move ");
    GLCD_SetBackColor(Black);
}



int one_five(void)//
	{
				int dy = y_chess;
				int dx = x_chess;
      if (dy == 4 && dx == 13) {
                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');
                    } 
			else if (dy == 7 && dx == 9)
			{                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');}
										else {
                        print_error();
                    }
	}
	
	int one_thirteen(void)//
	{
				int dy = y_chess;
				int dx = x_chess;
      if (dy == 7 && dx == 9) {
                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');
                    } 
			else if (dy == 4 && dx == 5)
			{                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');}
										else {
                        print_error();
                    }
	}
		int one_nine(void)//
	{
				int dy = y_chess;
				int dx = x_chess;
      if (dy == 7 && dx == 5) {
                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');
                    } 
			else if (dy == 7 && dx == 13)
			{                        moves_chess++;
                        GLCD_DisplayChar(ky, kx, 1, ' ');
                        ky = dy;  kx = dx;
                        GLCD_DisplayChar(ky, kx, 1, 'N');}
										else {
                        print_error();
                    }
	}
int four_five(void)//
{
    int dy = y_chess;
    int dx = x_chess;

    if (dy == 1 && dx == 13) {                    // ? (1,13)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else if (dy == 7 && dx == 13) {                // ? (7,13)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else {
        print_error();
    }
}

	int four_thirteen(void)//
{
    int dy = y_chess;
    int dx = x_chess;

    if (dy == 7 && dx == 5) {                     // ? (7,5)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else if (dy == 1 && dx == 5) {                // ? (1,5)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else {
        print_error();
    }
}

int seven_five(void)//
{
    int dy = y_chess;
    int dx = x_chess;

    if (dy == 4 && dx == 13) {                    // ? (4,13)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
		
		
    if (dy == 1 && dx == 9) {                    // ? (1,9)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else {
        print_error();
    }
}


int seven_nine(void)//
{
    int dy = y_chess;
    int dx = x_chess;

    if (dy == 1 && dx == 5) {                     // ? (1,5)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else if (dy == 1 && dx == 13) {               // ? (4,13)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else {
        print_error();
    }
}


int seven_thirteen(void)//
{
    int dy = y_chess;
    int dx = x_chess;

    if (dy == 4 && dx == 5) {                     // ? (4,5)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
		    if (dy == 1 && dx == 9) {                     // ? (4,5)
        moves_chess++;
        GLCD_DisplayChar(ky, kx, 1, ' ');
        ky = dy;  kx = dx;
        GLCD_DisplayChar(ky, kx, 1, 'N');
    }
    else {
        print_error();
    }
}


int chess(void) {



    KBD_Init();
    GLCD_Clear(Black);
    GLCD_DisplayChar(ky, kx, 1, 'N'); // Draw knight on screen

    // Cursor indicator under knight
    GLCD_DisplayChar(ky+1, kx, 1, 0x85);

    SysTick_Config(SystemCoreClock/100);

    while (1)
    {
        joystick_val = get_button();

        if (joystick_val != joystick_prev)
        {
            // ----------------------------
            // CURSOR MOVEMENT (same as TTC)
            // ----------------------------
            if (joystick_val == KBD_DOWN) {
                GLCD_DisplayString(y_chess+1, x_chess, 1, " ");
                if (y_chess < 7) y_chess += 3;
            }
            else if (joystick_val == KBD_UP) {
                GLCD_DisplayString(y_chess+1, x_chess, 1, " ");
                if (y_chess > 1) y_chess -= 3;
            }
            else if (joystick_val == KBD_RIGHT) {
                GLCD_DisplayString(y_chess+1, x_chess, 1, " ");
                if (x_chess < 13) x_chess += 4;
            }
            else if (joystick_val == KBD_LEFT) {
                GLCD_DisplayString(y_chess+1, x_chess, 1, " ");
                if (x_chess > 5) x_chess -= 4;
            }

            // ----------------------------
            //    KBD SELECT = attempt move
            // ----------------------------
            else if (joystick_val == KBD_SELECT)
            {

                if (moves_chess == 6) {
                    GLCD_Clear(Black);
                    GLCD_SetBackColor(Blue);
                    GLCD_DisplayString(4, 0, 1, " Puzzle Complete! ");
                    return 0;
								}
                // ----------------------------
                // ALL KNIGHT LOGIC COMBINED
                // ----------------------------

                // (1,5) 
                if (ky == 1 && kx == 5) {
										one_five();
                }

                // (1,13) ? (4,5)
                else if (ky == 1 && kx == 13) {
									one_thirteen();
                }

                // (4,5) ? (1,13) or (7,9)
                else if (ky == 4 && kx == 5) {
								four_five();
                }

                // (4,13) ? (1,5) or (7,9)
                else if (ky == 4 && kx == 13) {
                    four_thirteen();
                }

                // (7,5) ? (4,13)
                else if (ky == 7 && kx == 5) {
                    seven_five();
								}
                // (7,9) ? (1,5) or (4,13)
                else if (ky == 7 && kx == 9) {
										seven_nine();
                }

                // (7,13) ? (4,5)
                else if (ky == 7 && kx == 13) {
                    seven_thirteen();
                }
								else if (ky == 1 && kx == 9)
								{	one_nine();
								}

                // ----------------------------
                // End of game
                // ----------------------------

                }
            }

            // draw cursor
            GLCD_DisplayChar(y_chess+1, x_chess, 1, 0x85);

            joystick_prev = joystick_val;
        }
    }


