#include <reg51.h>
#include "i2c.h"
#include "delay.h"
#include "types.h"
#include "RTC.h"
#include "serial.h"
#include "stdlib.h"
sbit led = P2^2;

void main()
{
	
	u8 addr = 0x66;
	u8 data_c = 0;
	u8 byte_data = 45;
	u8 bcd_data  ;
	u8 name[10];
	u8 Date_1[3];
	u8 Time_1[3];
	 init_UART();
	RTC_Set_Time(16,35,55);
	RTC_Set_Date(14,06,20);
	send_string("Time = \0");
	while(1)
	{
		led =0;
	RTC_Read_Time(Time_1);
	RTC_Read_Date(Date_1);
	  send_string("Time = \0");
		Tx_int(Time_1[0]);
		Tx_CHAR(':');
		Tx_int(Time_1[1]);
		Tx_CHAR(':');
		Tx_int(Time_1[2]);
		Tx_CHAR(' ');
		send_string("Date = \0");
		Tx_int(Date_1[0]);
		Tx_CHAR('-');
		Tx_int(Date_1[1]);
		Tx_CHAR('-');
		Tx_int(Date_1[2]);
		Tx_CHAR('\r');
		Tx_CHAR('\n');
		delay_ms(400);
		led =1;
		delay_ms(400);
	}
}