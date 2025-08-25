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
	
	while (1){
		if ((GPIO_PORTF_DATA_R & 0x11) = 0x01) //SW1
		{
			GPIO_PORTF_DATA_R = 0x2; } //Red
			
		else if ((GPIO_PORTF_DATA_R & 0×11) = 0×10) //SW2
		{
			GPIO_PORTF_DATA_R = 0x4; } //Blue
			
		else if ((GPIO_PORTF_DATA_R & 0x11)= 0x00) // Both
		{
			GPIO_PORTF_DATA_R = 0x6; } //Magenta (Red + Blue)
			
		else
		{
			GPIO_PORTF_DATA_R = 0x0; } //all lights off
	}
}
//just repeating the code of part1 for showing branching
