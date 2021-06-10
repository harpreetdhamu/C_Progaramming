#include<stdio.h>

union ADCON
{

	unsigned char value;
	struct 
	{
	unsigned char ADCS : 3;
	unsigned char ACQT : 3;
   	unsigned char	   : 1;
	unsigned char ADFM : 1;

	}ADC;
}Bit;

int main()
{
 Bit.ADC.ADCS = 0x011;
printf("ADCON = %#x\n",Bit.ADC.ADCS);

}
