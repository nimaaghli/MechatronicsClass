#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_hd44780.h"
#include "tm_stm32f4_adc.h"
#include <stdbool.h>
//#include <stdio.h>


extern void initialise_monitor_handles(void);

#define LED1_PORT				GPIOD
#define LED1_PIN				GPIO_PIN_12
#define LED2_PORT				GPIOD
#define LED2_PIN				GPIO_PIN_13
#define LED3_PORT				GPIOD
#define LED3_PIN				GPIO_PIN_14
#define LED4_PORT				GPIOD
#define LED4_PIN				GPIO_PIN_15
uint8_t customChar[] = {
	0x01,	// xxx 11111
	0x03,	// xxx 10001
	0x07,	// xxx 10001
	0x1F,	// xxx 10001
	0x1F,	// xxx 10001
	0x07,	// xxx 10001
	0x03,	// xxx 10001
	0x01	// xxx 11111
};
uint8_t customChar2[] = {
	0x10,	// xxx 11111
	0x18,	// xxx 10001
	0x1C,	// xxx 10001
	0x1F,	// xxx 10001
	0x1F,	// xxx 10001
	0x1C,	// xxx 10001
	0x18,	// xxx 10001
	0x20	// xxx 11111
};

int main(void) {
	bool main_menu_flag=false;
	bool servo_menu_flag=false;
	bool step_menu_flag=false;
	int degree=0;
	//initialise_monitor_handles();	/*rtt - semihosting*/
	//Rectangle for custom character
	//xxx means doesn't care, lower 5 bits are important for LCD

	//Initialize system
	SystemInit();
	//Initialize LCD 20 cols x 4 rows
	TM_HD44780_Init(16, 2);
	Delayms(1000);
	TM_GPIO_Init(LED1_PORT, LED1_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED2_PORT, LED2_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED3_PORT, LED3_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED4_PORT, LED4_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);



    /* Initialize ADC1 on channel 0, this is pin PA0 */
    //TM_ADC_Init(ADC1, ADC_Channel_0);

    /* Initialize ADC1 on channel 3, this is pin PA3 */
    //TM_ADC_Init(ADC1, ADC_Channel_3);

	//Save custom character on location 0 in LCD
	TM_HD44780_CreateChar(0, &customChar[0]);
	TM_HD44780_CreateChar(1, &customChar2[0]);


	//TM_HD44780_Puts(0, 2, "stm32f429-\n\r       discovery.com");

	//Wait a little
	Delayms(3000);

	//Clear LCD
	//TM_HD44780_Clear();
	menu1();
	//Show cursor
	//TM_HD44780_CursorOn();

	//Write new text
	//TM_HD44780_Puts(6, 2, "CLEARED!");

	//Wait a little
	Delayms(1000);
	int y;
	int x;
	//Enable cursor blinking
	//TM_HD44780_BlinkOn();


	//TM_GPIO_Init(GPIOC, GPIO_PIN_8, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	//TM_GPIO_Init(GPIOA, GPIO_PIN_3, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	//TM_GPIO_Init(GPIOC, GPIO_PIN_9, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);

	/* Set pins low */

	while (1) {
		//TM_HD44780_Puts(0, 0, "100");
		//str[0]='2';
		//sprintf(str, "%4d: %4d", TM_ADC_Read(ADC1, ADC_Channel_0), TM_ADC_Read(ADC1, ADC_Channel_3));
//		sprintf(str, sizeof(str), 1);
		//sprintf(str, "%d", 100);
		//a=TM_ADC_Read(ADC1, ADC_Channel_3);

		TM_GPIO_Init(GPIOA, GPIO_PIN_3, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		TM_GPIO_SetPinHigh(GPIOA, GPIO_PIN_3);

		TM_GPIO_Init(GPIOC, GPIO_PIN_8, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		TM_GPIO_SetPinLow(GPIOC, GPIO_PIN_8);

		TM_GPIO_Init(GPIOC, GPIO_PIN_9, TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);


		TM_ADC_Init(ADC1, ADC_Channel_0);
		Delayms(100);


		//TM_GPIO_SetPinLow(GPIOC, GPIO_PIN_9);

		y=TM_ADC_Read(ADC1, ADC_Channel_0);
		Delayms(10);
		//printf("y=%d",y);		/*rtt - semihosting*/


		TM_ADC_Init(ADC1, ADC_Channel_3);
		Delayms(100);
		TM_GPIO_Init(GPIOC, GPIO_PIN_8, TM_GPIO_Mode_IN, TM_GPIO_OType_OD, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		TM_GPIO_Init(GPIOC, GPIO_PIN_9, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		Delayms(10);
		TM_GPIO_SetPinLow(GPIOC, GPIO_PIN_9);
		TM_GPIO_Init(GPIOA, GPIO_PIN_0, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		Delayms(10);
		TM_GPIO_SetPinHigh(GPIOA, GPIO_PIN_0);
		Delayms(10);
		x=TM_ADC_Read(ADC1, ADC_Channel_3);
		Delayms(10);
		//printf("x=%d\n",x);
		//x=TM_ADC_Read(ADC1, ADC_Channel_3);
//		printf("5");
	    //ITM_SendChar("tesl");
	    //printf('B');   // Works
		//TM_HD44780_Puts(0, 0,str);
		/* Little delay */
		if(!servo_menu_flag && !step_menu_flag ){
			if((y>320 && x>780)&&(y<700 && x<1060)){
				TM_GPIO_TogglePinValue(LED1_PORT,LED1_PIN);
				TM_HD44780_Clear();
				menu2();
				servo_menu_flag=true;
			}
			else if((y>500 && x>300)&&(y<830 && x<680)){
					TM_GPIO_TogglePinValue(LED2_PORT,LED2_PIN);
					TM_HD44780_Clear();
					menu2();
					step_menu_flag=true;
			}

		}
		else{
			if((y>300 && x>600)&&(y<500 && x<750)){
						TM_GPIO_TogglePinValue(LED3_PORT,LED3_PIN);
						TM_HD44780_Clear();
						menu2();
						if(degree>-180){degree-=20;}
						setdegree(degree);


			}
			else if((y>700 && x>950)&&(y<910 && x<1065)){
						TM_GPIO_TogglePinValue(LED4_PORT,LED4_PIN);
						TM_HD44780_Clear();
						menu2();
						if(degree<180){degree+=20;}
						setdegree(degree);
			}
			else if((y>500 && x>500)&&(y<630 && x<650)){
						TM_HD44780_Clear();
						menu1();
					    step_menu_flag=false;
						step_menu_flag=false;
			}
		}




	}
}



void menu1(){
	//Put string to LCD
	TM_HD44780_Puts(0, 0, "SERVO");
	TM_HD44780_Puts(12, 1, "STEP");
}

void menu2(){
	//Show custom character at x = 1, y = 2 from RAM location 0
	TM_HD44780_PutCustom(0, 2, 0);
	TM_HD44780_PutCustom(6, 0, 1);
	TM_HD44780_Puts(13, 0, "GO");
}
void setdegree(int degree){

	switch (degree){
		case 0 :TM_HD44780_Puts(2, 0, "+0");
		break;
		case 20 :TM_HD44780_Puts(2, 0, "+20");
		break;
		case 40 :TM_HD44780_Puts(2, 0, "+40");
		break;
		case 60 :TM_HD44780_Puts(2, 0, "+60");
		break;
		case 80 :TM_HD44780_Puts(2, 0, "+80");
		break;
		case 100 :TM_HD44780_Puts(2, 0, "+100");
		break;
		case 120 :TM_HD44780_Puts(2, 0, "+120");
		break;
		case 140 :TM_HD44780_Puts(2, 0, "+140");
		break;
		case 160 :TM_HD44780_Puts(2, 0, "+160");
		break;
		case 180 :TM_HD44780_Puts(2, 0, "+180");
		break;
		case -20 :TM_HD44780_Puts(2, 0, "-20");
		break;
		case -40 :TM_HD44780_Puts(2, 0, "-40");
		break;
		case -60 :TM_HD44780_Puts(2, 0, "-60");
		break;
		case -80 :TM_HD44780_Puts(2, 0, "-80");
		break;
		case -100 :TM_HD44780_Puts(2, 0, "-100");
		break;
		case -120 :TM_HD44780_Puts(2, 0, "-120");
		break;
		case -140 :TM_HD44780_Puts(2, 0, "-140");
		break;
		case -160 :TM_HD44780_Puts(2, 0, "-160");
		break;
		case -180 :TM_HD44780_Puts(2, 0, "-180");
		break;
	}
}
