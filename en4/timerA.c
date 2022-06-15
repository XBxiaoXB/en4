#include "iodefine.h"
#include "timerA.h"
#include "led.h"
#include <machine.h>

void iniTimerA(void)
{
	TA.TMA.BYTE = 0x10;     // 8192
	IRR1.BIT.IRRTA = 0;   //zhongduanqingqiu
	IENR1.BIT.IENTA = 1;  //yunxvzhongduan
}

#pragma section IntPRG
__interrupt(vect=19) void INT_TimerA(void) 
{
    IRR1.BIT.IRRTA = 0;
    IO.PDR8.BIT.B1 = 0;
	IO.PDR8.BIT.B2 = 1;

}	