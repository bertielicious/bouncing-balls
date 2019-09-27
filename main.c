/*                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
 *Player select  2 |RA5      | 19
 * Paddle up  L  3 |RA4      | 18
 *    MCLR/ RST  4 |         | 17
 *    GREEN LED  5 |RC5      | 16
 *           CE  6 |RC4      | 15
 *RST op to 5110 7 |         | 14  RC2 Paddle down L
 *           SS  8 |         | 13 
 *           SDO 9 |         | 12
 *           TX 10 |         | 11  SCK
 *                  ---------
 
 */



#include "config.h"
#include <stdio.h>
#include "main.h"
#include "config_osc.h"
#include "setup_ports.h"
#include "init_spi.h"
#include "set_usart.h"
#include "putch.h"
#include "lcd_setup.h"
#include "TMR0_setup.h"
#include "TMR1_setup.h"
#include "interrupt isr.h"
#include "lcdWrite.h"
#include "set_address.h"
#include "set_game_area.h"
#include "paddleMove.h"
#include "animate.h"
#include "posnBall.h"
#include "render.h"
#include "clearScreen.h"


void main(void) 
{
config_osc();       // internal clock frequency = 8MHz
setup_ports();      
init_spi();
set_usart();
lcd_setup();        // configures the LCD
set_game_area();
TMR0_setup();
TMR1_setup();
clearScreen();
#include "update.h"
printf("Pong !\n");

float row = 0 ;
float col = 3 ;

float colSpeed = 0.2;
float rowSpeed = 0.3;
 

        while(1)
        {
            if(col > WIDTH)
            {
                colSpeed = -0.2;
            }
            else if(col <=0)
            {
                colSpeed = 0.2;
            }
            col = col + colSpeed;       // horizontal ball bouncing
            animate(col, row,0);
            
            if(row > DEPTH)
            {
                rowSpeed = -0.1;
            }
            
            if (row <= 0)
            {
                rowSpeed = 0.1;
            }
            row = row + rowSpeed;       // vertical ball bouncing
            animate(col, row, 0); 
        }
        
        
              
}
                            

