#include <stdint.h> 
#include <stdbool.h>
#include "tm4c123gh6pm.h"
void main()
{
	SYSCTL_RCGC2_R = 0x00000020;
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0x1F;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_DEN_R = 0x1F;
	GPIO_PORTF_PUR_R = 0x11;
	
	int counter;
	counter = 0;
	int arr[8] = {0x0,0x2,0x6,0x4,0xC,0xE,0xA,0x8};

	while (1){
		if ((GPIO_PORTF_DATA_R & 0x11) = 0x01) //SW1
		{
			counter %= 8;
			GPIO_PORTF_DATA_R = arr[counter];
			counter++;
			while((GPIO_PORTF_DATA_R & 0x11) == 0x01);
		}
	}
}
