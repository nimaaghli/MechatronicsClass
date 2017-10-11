#include "defines.h"
#include "stm32f4xx.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_hd44780.h"
#include "tm_stm32f4_adc.h"
#include "tm_stm32f4_pwm.h"
#include "stm32f4xx_rtc.h"
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


#define STEP_PORT				GPIOE
#define STEP_PIN1				GPIO_PIN_7
#define STEP_PIN2				GPIO_PIN_8
#define STEP_PIN3				GPIO_PIN_9
#define STEP_PIN4				GPIO_PIN_10


#define SERVO_PORT				GPIOB
#define SERVO_PIN				GPIO_PIN_8

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



	//TM_DELAY_Init();
	//Initialize LCD 20 cols x 4 rows
	TM_HD44780_Init(16, 2);


	Delayms(1000);
	TM_GPIO_Init(LED1_PORT, LED1_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED2_PORT, LED2_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED3_PORT, LED3_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
	TM_GPIO_Init(LED4_PORT, LED4_PIN, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);


	TM_GPIO_Init(STEP_PORT, STEP_PIN1, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	TM_GPIO_Init(STEP_PORT, STEP_PIN2, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	TM_GPIO_Init(STEP_PORT, STEP_PIN3, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);
	TM_GPIO_Init(STEP_PORT, STEP_PIN4, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High);


	Delayms(1000);
    InitializeLEDs();
    InitializeTimer();
    InitializePWMChannel();



    /* Initialize ADC1 on channel 0, this is pin PA0 */
    //TM_ADC_Init(ADC1, ADC_Channel_0);

    /* Initialize ADC1 on channel 3, this is pin PA3 */
    //TM_ADC_Init(ADC1, ADC_Channel_3);

	//Save custom character on location 0 in LCD
	TM_HD44780_CreateChar(0, &customChar[0]);
	TM_HD44780_CreateChar(1, &customChar2[0]);

	//Wait a little
	Delayms(3000);


	//Clear LCD
	//TM_HD44780_Clear();
	menu1();
	//Show cursor
	//TM_HD44780_CursorOn();


	//Wait a little
	Delayms(1000);
	int y;
	int x;
	char array[5];
	//Enable cursor blinking
	//TM_HD44780_BlinkOn();

	while (1) {

		TM_ADC_Init(ADC1, ADC_Channel_0);

		TM_GPIO_Init(GPIOA, GPIO_PIN_3, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		TM_GPIO_SetPinHigh(GPIOA, GPIO_PIN_3);

		TM_GPIO_Init(GPIOC, GPIO_PIN_8, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);
		TM_GPIO_SetPinLow(GPIOC, GPIO_PIN_8);

		TM_GPIO_Init(GPIOC, GPIO_PIN_9, TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);


		Delayms(300);
		x=TM_ADC_Read(ADC1, ADC_Channel_0);
		//printf("x=%d ",x);		/*rtt - semihosting*/
		//TM_HD44780_Clear();
		//sprintf(array, "x=%d", x);
		//TM_HD44780_Puts(7, 0, array);


		TM_ADC_Init(ADC1, ADC_Channel_3);
		Delayms(100);
		TM_GPIO_Init(GPIOC, GPIO_PIN_8, TM_GPIO_Mode_IN, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);

		TM_GPIO_Init(GPIOC, GPIO_PIN_9, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);

		TM_GPIO_SetPinLow(GPIOC, GPIO_PIN_9);

		TM_GPIO_Init(GPIOA, GPIO_PIN_0, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_Low);;
		TM_GPIO_SetPinHigh(GPIOA, GPIO_PIN_0);
		y=TM_ADC_Read(ADC1, ADC_Channel_3);
		//printf("y=%d\n",y);


		//sprintf(array, "y=%d", y);
		//TM_HD44780_Puts(7, 1, array);


		//x=TM_ADC_Read(ADC1, ADC_Channel_3);
//		printf("5");
	    //ITM_SendChar("tesl");
	    //printf('B');   // Works
		//TM_HD44780_Puts(0, 0,str);
		/* Little delay */
		if(!servo_menu_flag && !step_menu_flag ){
			if((y>1700 && x>2500)&&(y<2000 && x<3800)){
				TM_GPIO_TogglePinValue(LED1_PORT,LED1_PIN);
				TM_HD44780_Clear();
				menu2();
				servo_menu_flag=true;
			}
			else if((y>2100 && x>400)&&(y<2500 && x<1100)){
					TM_GPIO_TogglePinValue(LED2_PORT,LED2_PIN);
					TM_HD44780_Clear();
					menu2();
					step_menu_flag=true;
			}

		}
		else{
			if((y>1800 && x>3400)&&(y<2100 && x<3700)){
						TM_GPIO_TogglePinValue(LED3_PORT,LED3_PIN);
						TM_HD44780_Clear();
						menu2();
						if(servo_menu_flag){
							if(degree>-90){degree-=10;}
						}
						else if(step_menu_flag){
							if(degree>-180){degree-=10;}
						}
						setdegree(degree);



			}
			else if((y>1700 && x>2100)&&(y<2000 && x<2600)){
						TM_GPIO_TogglePinValue(LED4_PORT,LED4_PIN);
						TM_HD44780_Clear();
						menu2();
						if(servo_menu_flag){
							if(degree<90){degree+=10;}
						}
						else if(step_menu_flag){
							if(degree<180){degree+=10;}
						}
						setdegree(degree);
			}
			else if((y>1600 && x>400)&&(y<2000 && x<1000)){
						TM_HD44780_Clear();
						TM_HD44780_Puts(0, 0, "Motor Moving...");
						//drive_step_CW(degree);
						if(servo_menu_flag==true){
							drive_servo(degree);
							Delayms(3000);
							degree=0;
							drive_servo(degree);
							Delayms(2000);
						}
						else if(step_menu_flag==true){
							int p=(int)degree*1.41;
							if(p>0){
								drive_step_CW(p);
								Delayms(3000);
								drive_step_CCW(p);
							}
							else if(p<0){
								drive_step_CCW(abs(p));
								Delayms(3000);
								drive_step_CW(abs(p));

							}
							degree=0;


						}

						TM_HD44780_Clear();
						menu1();
					    step_menu_flag=false;
						servo_menu_flag=false;

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
	setdegree(0);
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
		case 10 :TM_HD44780_Puts(2, 0, "+10");
		break;
		case 30 :TM_HD44780_Puts(2, 0, "+30");
		break;
		case 50 :TM_HD44780_Puts(2, 0, "+50");
		break;
		case 70 :TM_HD44780_Puts(2, 0, "+70");
		break;
		case 90 :TM_HD44780_Puts(2, 0, "+90");
		break;
		case 110 :TM_HD44780_Puts(2, 0, "+110");
		break;
		case 130 :TM_HD44780_Puts(2, 0, "+130");
		break;
		case 150 :TM_HD44780_Puts(2, 0, "+150");
		break;
		case 170 :TM_HD44780_Puts(2, 0, "+170");
		break;
		case -10 :TM_HD44780_Puts(2, 0, "-10");
		break;
		case -30 :TM_HD44780_Puts(2, 0, "-30");
		break;
		case -50 :TM_HD44780_Puts(2, 0, "-50");
		break;
		case -70 :TM_HD44780_Puts(2, 0, "-70");
		break;
		case -90 :TM_HD44780_Puts(2, 0, "-90");
		break;
		case -110 :TM_HD44780_Puts(2, 0, "-110");
		break;
		case -130 :TM_HD44780_Puts(2, 0, "-130");
		break;
		case -150 :TM_HD44780_Puts(2, 0, "-150");
		break;
		case -170 :TM_HD44780_Puts(2, 0, "-170");
		break;

	}
}
void drive_step_CCW(int degree){
	int delay=5;
for(int i=0;i<degree;i++){
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);

}
}

void drive_step_CW(int degree){
	int delay=10;
	for(int i=0;i<degree;i++){
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);
	TM_GPIO_SetPinHigh(STEP_PORT, STEP_PIN1);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN2);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN3);
	TM_GPIO_SetPinLow(STEP_PORT, STEP_PIN4);
	Delayms(delay);

}
}




void drive_servo(int degree){

	switch (degree){
		case 0 :setpwm(39);
		break;
		case 10 :setpwm(41);
		break;
		case 20 :setpwm(43);
		break;
		case 30 :setpwm(45);
		break;
		case 40 :setpwm(48);
		break;
		case 50 :setpwm(50);
		break;
		case 60 :setpwm(52);
		break;
		case 70 :setpwm(54);
		break;
		case 80 :setpwm(57);
		break;
		case 90 :setpwm(62);
		break;
		case -10 :setpwm(38);
		break;
		case -20 :setpwm(37);
		break;
		case -30 :setpwm(35);
		break;
		case -40 :setpwm(32);
		break;
		case -50 :setpwm(29);
		break;
		case -60 :setpwm(26);
		break;
		case -70 :setpwm(23);
		break;
		case -80 :setpwm(20);
		break;
		case -90 :setpwm(17);
		break;


			}

}



void InitializeTimer(int period)
{
	period=500;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

    TIM_TimeBaseInitTypeDef timerInitStructure;
    timerInitStructure.TIM_Prescaler = 3270;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = period;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM4, &timerInitStructure);
    TIM_Cmd(TIM4, ENABLE);
}
void InitializePWMChannel()
{
    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = 39;//17-62 39 for mid
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC1Init(TIM4, &outputChannelInit);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);

}

void InitializeLEDs()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef gpioStructure;
    gpioStructure.GPIO_Pin = GPIO_Pin_6;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &gpioStructure);
}

void setpwm(int num){
    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = num;//17-62 39 for mid
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC1Init(TIM4, &outputChannelInit);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);

}

