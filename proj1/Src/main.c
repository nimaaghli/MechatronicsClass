/**
  ******************************************************************************
  ******************************************************************************
  * Project Name       : 4 Digit 7Segment Stopwatch
  * Author  		   : Nima Aghli
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l4xx_hal.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim7;
TIM_HandleTypeDef htim16;
uint32_t getUs(void);
/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM7_Init(void);
static void MX_TIM16_Init(void);
int time=0;
int m=0;
int mm=0;
int mmm=0;
int mmmm=0;

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if(htim->Instance==TIM7){

		m=time;
		if(time==10){
			time=0;
			m=0;
			mm++;
		}
		if(mm==10){
			mm=0;
			mmm++;
		}
		if(mmm==10){

			mmm=0;
			mmmm++;

		}
		if(mmmm==10){
			mmmm=0;
			NVIC_DisableIRQ(TIM7_IRQn);



		}
		time++;

	}
}

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM7_Init();
 // MX_TIM16_Init();

  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim7);
  NVIC_DisableIRQ(TIM7_IRQn);
  //HAL_TIM_Base_Start_IT(&htim16);
  //SetSeg(0);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	/*  if (HAL_GPIO_ReadPin(PushButton_GPIO_Port, PushButton_Pin)) {
		  if(stop==false){

			  NVIC_DisableIRQ(TIM7_IRQn);
			  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
			  stop=true;


		  }else{

			  NVIC_EnableIRQ(TIM7_IRQn);
			  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			  stop=false;
		  }
	  }*/



	  	    HAL_GPIO_WritePin(SEG_D2_Port, SEG_D2_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(SEG_D3_Port, SEG_D3_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(SEG_D4_Port, SEG_D4_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);


	  		SetSeg(mmmm);
	  		HAL_GPIO_WritePin(SEG_D1_Port, SEG_D1_Pin, GPIO_PIN_RESET);

	  		delayUs(1);


	  		HAL_GPIO_WritePin(SEG_D1_Port, SEG_D1_Pin, GPIO_PIN_SET);

	  		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	  		SetSeg(mmm);

	  		HAL_GPIO_WritePin(SEG_D2_Port, SEG_D2_Pin, GPIO_PIN_RESET);

	  		delayUs(1);


	  		HAL_GPIO_WritePin(SEG_D2_Port, SEG_D2_Pin, GPIO_PIN_SET);
	  		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

	  		SetSeg(mm);

	  		HAL_GPIO_WritePin(SEG_D3_Port, SEG_D3_Pin, GPIO_PIN_RESET);


	  		delayUs(1);


	  		HAL_GPIO_WritePin(SEG_D3_Port, SEG_D3_Pin, GPIO_PIN_SET);

	  		SetSeg(m);
	  		HAL_GPIO_WritePin(SEG_D4_Port, SEG_D4_Pin, GPIO_PIN_RESET);

	  		delayUs(1);



	  //if(time==9){time=0;}
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the main internal regulator output voltage 
    */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* TIM7 init function */
static void MX_TIM7_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;

  htim7.Instance = TIM7;
  htim7.Init.Prescaler = 8000;
  htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim7.Init.Period = 40;
  if (HAL_TIM_Base_Init(&htim7) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}


/* TIM16 init function */
static void MX_TIM16_Init(void)
{

  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 48000;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 5;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
     PA2   ------> USART2_TX
     PA15 (JTDI)   ------> USART2_RX
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : VCP_TX_Pin */
  GPIO_InitStruct.Pin = VCP_TX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(VCP_TX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : VCP_RX_Pin */
  GPIO_InitStruct.Pin = VCP_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF3_USART2;
  HAL_GPIO_Init(VCP_RX_GPIO_Port, &GPIO_InitStruct);





  /*Configure GPIO pin : LD3_Pin */
  GPIO_InitStruct.Pin = LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD3_GPIO_Port, &GPIO_InitStruct);



  /*Configure GPIO pin : SEG_D1_Pin */
   GPIO_InitStruct.Pin = SEG_D1_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(SEG_D1_Port, &GPIO_InitStruct);
   HAL_GPIO_WritePin(SEG_D1_Port, SEG_D1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SEG_D2_Pin */
   GPIO_InitStruct.Pin = SEG_D2_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(SEG_D2_Port, &GPIO_InitStruct);
   HAL_GPIO_WritePin(SEG_D2_Port, SEG_D2_Pin, GPIO_PIN_RESET);

   /*Configure GPIO pin : SEG_D3_Pin */
    GPIO_InitStruct.Pin = SEG_D3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SEG_D3_Port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SEG_D3_Port, SEG_D3_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : SEG_D4_Pin */
     GPIO_InitStruct.Pin = SEG_D4_Pin;
     GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(SEG_D4_Port, &GPIO_InitStruct);
     HAL_GPIO_WritePin(SEG_D4_Port, SEG_D4_Pin, GPIO_PIN_RESET);







  /*Configure GPIO pin : SEG_A_Pin */
   GPIO_InitStruct.Pin = SEG_A_Pin;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(SEG_A_Port, &GPIO_InitStruct);


   /*Configure GPIO pin : SEG_B_Pin */
    GPIO_InitStruct.Pin = SEG_B_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(SEG_B_Port, &GPIO_InitStruct);


    /*Configure GPIO pin : SEG_F_Pin */
     GPIO_InitStruct.Pin = SEG_F_Pin;
     GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(SEG_F_Port, &GPIO_InitStruct);


     /*Configure GPIO pin : SEG_E_Pin */
      GPIO_InitStruct.Pin = SEG_E_Pin;
      GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(SEG_E_Port, &GPIO_InitStruct);


      /*Configure GPIO pin : SEG_D_Pin */
       GPIO_InitStruct.Pin = SEG_D_Pin;
       GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
       GPIO_InitStruct.Pull = GPIO_NOPULL;
       GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
       HAL_GPIO_Init(SEG_D_Port, &GPIO_InitStruct);


       /*Configure GPIO pin : SEG_C_Pin */
        GPIO_InitStruct.Pin = SEG_C_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(SEG_C_Port, &GPIO_InitStruct);


        /*Configure GPIO pin : SEG_G_Pin */
         GPIO_InitStruct.Pin = SEG_G_Pin;
         GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
         GPIO_InitStruct.Pull = GPIO_NOPULL;
         GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
         HAL_GPIO_Init(SEG_G_Port, &GPIO_InitStruct);


         /*Configure GPIO pin : PushButton_Pin */
         GPIO_InitStruct.Pin = PushButton_Pin;
         GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
         GPIO_InitStruct.Pull = GPIO_NOPULL;
         HAL_GPIO_Init(PushButton_GPIO_Port, &GPIO_InitStruct);
         /* EXTI interrupt init*/
         HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
         HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);





}

void SetSeg(int n){
	switch(n){
		case 0:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);//
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_RESET);//

			break;
		case 8:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG_A_Port, SEG_A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_B_Port, SEG_B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_C_Port, SEG_C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_D_Port, SEG_D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_E_Port, SEG_E_Pin, GPIO_PIN_RESET);//
			HAL_GPIO_WritePin(SEG_F_Port, SEG_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG_G_Port, SEG_G_Pin, GPIO_PIN_SET);
			break;



	}
}


uint32_t getUs(void) {

	uint32_t usTicks = HAL_RCC_GetSysClockFreq() / 1000000;
	register uint32_t ms, cycle_cnt;
	do {
		ms = HAL_GetTick();
		cycle_cnt = SysTick->VAL;
	} while (ms != HAL_GetTick());
	return (ms * 1000) + (usTicks * 1000 - cycle_cnt) / usTicks;
}



void delayUs(uint16_t micros) {
	uint32_t start = getUs();
	while (getUs()-start < (uint32_t) micros) {
	asm("nop");
	}
}




/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
