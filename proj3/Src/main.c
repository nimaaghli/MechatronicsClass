/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "fatfs.h"

//#include "usb_host.h"

/* USER CODE BEGIN Includes */
#include "usb_host.h"
#include "usbh_core.h"
#include "usbh_msc.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
/* USB Host Core handle declaration */
USBH_HandleTypeDef hUsbHostFS;
ApplicationTypeDeff USB_state = USB_IDLE;
void USB_write(char *msg);
static void USBH_UserPro (USBH_HandleTypeDef *phost, uint8_t id);

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;
SPI_HandleTypeDef hspi1;
ADC_HandleTypeDef hadc3;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
#include "fatfs.h"
FATFS USBDISKFatFs;           /* File system object for USB disk logical drive */
FIL MyFile;                   /* File object */
char USBDISKPath[4];          /* USB Host logical drive path */
bool writeflag=false;
char * msg;
USBH_HandleTypeDef hUSB_Host; /* USB Host handle */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_ADC3_Init(void);
void USB_HOST_Process(void);
void USB_HOST_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

;

/**
* -- Insert your external function declaration here --
*/
/* USER CODE BEGIN 1 */


char *ftoa(char *buffer, double d, int precision) {

	long wholePart = (long) d;

	// Deposit the whole part of the number.

	itoa(wholePart,buffer,10);

	// Now work on the faction if we need one.

	if (precision > 0) {

		// We do, so locate the end of the string and insert
		// a decimal point.

		char *endOfString = buffer;
		while (*endOfString != '\0') endOfString++;
		*endOfString++ = '.';

		// Now work on the fraction, be sure to turn any negative
		// values positive.

		if (d < 0) {
			d *= -1;
			wholePart *= -1;
		}

		double fraction = d - wholePart;
		while (precision > 0) {

			// Multipleby ten and pull out the digit.

			fraction *= 10;
			wholePart = (long) fraction;
			*endOfString++ = '0' + wholePart;

			// Update the fraction and move on to the
			// next digit.

			fraction -= wholePart;
			precision--;
		}

		// Terminate the string.

		*endOfString = '\0';
	}

   return buffer;
}


void USB_Error_Handle(void)
{
  /* USER CODE BEGIN USB_Error_Handle */
  /* User can add his own implementation to report the HAL error return state */
 HAL_GPIO_WritePin(LD5_GPIO_Port,LD5_Pin,GPIO_PIN_SET);
  while(1)
  {
  }
  /* USER CODE END USB_Error_Handle */
}

void USB_read(){

	  FRESULT res;                                          /* FatFs function common result code */
	  uint32_t byteswritten, bytesread;                     /* File write/read counts */
	  uint8_t rtext[100];                                   /* File read buffer */

	  /* Register the file system object to the FatFs module */
	  if(f_mount(&USBDISKFatFs, (TCHAR const*)USBDISKPath, 0) != FR_OK)
	  {
	    /* FatFs Initialization Error */
	    USB_Error_Handle();
	  }
	  else
	  {

	        /* Open the text file object with read access */
	        if(f_open(&MyFile, "bh1.TXT", FA_READ) != FR_OK)
	        {
	          /* 'STM32.TXT' file Open for read Error */
	          USB_Error_Handle();
	        }
	        else
	        {
	          /* Read data from the text file */
	          res = f_read(&MyFile, rtext, sizeof(rtext), (void *)&bytesread);
	          HAL_UART_Transmit(&huart2, (uint8_t *)&rtext, strlen(rtext), 100);
	          if((bytesread == 0) || (res != FR_OK))
	          {
	            /* 'STM32.TXT' file Read or EOF Error */
	            USB_Error_Handle();
	          }
	          else
	          {
	            /* Close the open text file */
	            f_close(&MyFile);

	            /* Compare read data with the expected data */

	          /* Success of the demo: no error occurrence */
	              //BSP_LED_On(LED4);
	              HAL_GPIO_WritePin(LD4_GPIO_Port,LD4_Pin,GPIO_PIN_SET);

	          }
	        }
	      }


	  /* Unlink the USB disk I/O driver */
	  FATFS_UnLinkDriver(USBDISKPath);
}
void USB_write(char *msg)
{

  FRESULT res;                                          /* FatFs function common result code */
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t rtext[100];                                   /* File read buffer */

  /* Register the file system object to the FatFs module */
  if(f_mount(&USBDISKFatFs, (TCHAR const*)USBDISKPath, 0) != FR_OK)
  {
    /* FatFs Initialization Error */
    USB_Error_Handle();
  }
  else
  {

      /* Create and Open a new text file object with write access */
      if(f_open(&MyFile, "bh1.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
      {
        /* 'STM32.TXT' file Open for write Error */
        USB_Error_Handle();
      }
      else
      {
        /* Write data to the text file */
        res = f_write(&MyFile, msg, strlen(msg), (void *)&byteswritten);

        if((byteswritten == 0) || (res != FR_OK))
        {
          /* 'STM32.TXT' file Write or EOF Error */
          USB_Error_Handle();
        }
        else
        {
          /* Close the open text file */
          f_close(&MyFile);

        /* Open the text file object with read access */
        if(f_open(&MyFile, "bh1.TXT", FA_READ) != FR_OK)
        {
          /* 'STM32.TXT' file Open for read Error */
          USB_Error_Handle();
        }
        else
        {
          /* Read data from the text file */
          res = f_read(&MyFile, rtext, sizeof(rtext), (void *)&bytesread);

          if((bytesread == 0) || (res != FR_OK))
          {
            /* 'STM32.TXT' file Read or EOF Error */
            USB_Error_Handle();
          }
          else
          {
            /* Close the open text file */
            f_close(&MyFile);

            /* Compare read data with the expected data */
            if((bytesread != byteswritten))
            {
              /* Read data is different from the expected data */
              USB_Error_Handle();
            }
            else
            {
          /* Success of the demo: no error occurrence */
              //BSP_LED_On(LED4);
              HAL_GPIO_WritePin(LD4_GPIO_Port,LD4_Pin,GPIO_PIN_SET);
            }
          }
        }
      }
    }
  }

  /* Unlink the USB disk I/O driver */
  FATFS_UnLinkDriver(USBDISKPath);
}

void USB_HOST_Init(void)
{
  /* Init Host Library,Add Supported Class and Start the library*/
  USBH_Init(&hUsbHostFS, USBH_UserPro, HOST_FS);

  USBH_RegisterClass(&hUsbHostFS, USBH_MSC_CLASS);

  USBH_Start(&hUsbHostFS);
}

/*
 * Background task
*/
void USB_HOST_Process(void)
{
  /* USB Host Background task */
    USBH_Process(&hUsbHostFS);
}


static void USBH_UserPro (USBH_HandleTypeDef *phost, uint8_t id)
{

  /* USER CODE BEGIN CALL_BACK_1 */
  switch(id)
  {
  case HOST_USER_SELECT_CONFIGURATION:
  break;

  case HOST_USER_DISCONNECTION:
  USB_state = USB_DISCONNECT;
  break;

  case HOST_USER_CLASS_ACTIVE:
  USB_state = USB_READY;
  //USB_write();
  //MSC_Application();
  break;

  case HOST_USER_CONNECTION:
  USB_state = USB_START;
  break;

  default:
  break;
  }
  /* USER CODE END CALL_BACK_1 */
}


//variables need to be declared at the beginning
char Rx_indx, Rx_data[2], Rx_Buffer[100], Transfer_cplt;
//Interrupt callback routine
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

    uint8_t i;
    if (huart->Instance == USART2)  //current UART
        {

        if (Rx_indx==0) {for (i=0;i<100;i++) Rx_Buffer[i]=0;}   //clear Rx_Buffer before receiving new data

        if (Rx_data[0]!=13) //if received data different from ascii 13 (enter)
            {
            Rx_Buffer[Rx_indx++]=Rx_data[0];    //add data to Rx_Buffer

            }
        else            //if received data = 13
            {
            Rx_indx=0;
            Transfer_cplt=1;//transfer complete, data is ready to read

            //len=sprintf(Rx_Buffer,"%s\n",Rx_Buffer); //sprintf will return the length of 'buffer'
            //HAL_UART_Transmit(&huart2, (uint8_t *)&Rx_Buffer, len, 100);
            if(strncmp(Rx_Buffer, "1",strlen(Rx_Buffer)) == 0){
            	HAL_GPIO_WritePin(GPIOD, LD3_Pin, GPIO_PIN_SET);
            	msg="olan safehlama\n";
            	writeflag=true;


            }
            else if(strncmp(Rx_Buffer, "2",strlen(Rx_Buffer)) == 0){
            	HAL_GPIO_WritePin(GPIOD, LD4_Pin, GPIO_PIN_SET);
            }
            else if(strncmp(Rx_Buffer, "3",strlen(Rx_Buffer)) == 0){
            	HAL_GPIO_WritePin(GPIOD, LD5_Pin, GPIO_PIN_SET);
            }

            }

        HAL_UART_Receive_IT(&huart2, Rx_data, 1);   //activate UART receive interrupt every time
        }

}
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
	uint8_t adress,data,x_accel,y_accel,z_accel;
	uint16_t ADC_val;
    double voltage;
	char buffer_x[4];
	char buffer_y[4];
	char buffer_z[4];
	char buffer_adc[20];
	char newline[2] = "\r";
	char clearscreen[7] = "\033[2J";
	char setozerozeo[9] = "\033[0;0H";

	char dash[2] = "-";
	__HAL_SPI_ENABLE(&hspi1);
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
  USB_HOST_Init();
  MX_FATFS_Init();
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  MX_ADC3_Init();

  /* USER CODE BEGIN 2 */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);
    adress=0x20;
    if(!HAL_SPI_Transmit(&hspi1,&adress,1,50)==HAL_OK){
  	  return 0;
    }
    data=0x67;
    HAL_SPI_Transmit(&hspi1,&data,1,50);
    HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
  char name[]="Please enter you command:\n\r";
  x_accel=0;
  HAL_UART_Receive_IT(&huart2, Rx_data, 1);   //Activate receive intrupt
  HAL_UART_Transmit(&huart2, (uint8_t *)&name, strlen(name), 100);
  //HAL_UART_Transmit(&huart2, (uint8_t *)&clearscreen, strlen(clearscreen), 100); //clear console
  //HAL_UART_Transmit(&huart2, (uint8_t *)&setozerozeo, strlen(setozerozeo), 100); //set cursor to 0,0

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
    USB_HOST_Process();

//	adress=0x28|0x80;
//	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);
//	HAL_SPI_Transmit(&hspi1,&adress,1,50);
//	HAL_SPI_Receive(&hspi1,&x_accel,1,50);
//	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);
//	itoa(x_accel,buffer_x,10);
//	strcat(buffer_x,dash);
//	HAL_UART_Transmit(&huart2,(uint8_t *)&buffer_x, strlen(buffer_x), 100);
//	adress=0x2A|0x80;
//	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);
//	HAL_SPI_Transmit(&hspi1,&adress,1,50);
//	HAL_SPI_Receive(&hspi1,&y_accel,1,50);
//	itoa(y_accel,buffer_y,10);
//	strcat(buffer_y, newline);
//	HAL_UART_Transmit(&huart2,(uint8_t *)&buffer_y, strlen(buffer_y), 100);
//	HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_SET);

	    HAL_ADC_Start(&hadc3);
	    HAL_ADC_PollForConversion(&hadc3, 100);
	    ADC_val = HAL_ADC_GetValue(&hadc3);
	    HAL_ADC_Stop(&hadc3);
	    voltage=ADC_val*3.3/(float)4095;
	    //itoa(voltage,buffer_adc,10);
	    //sprintf(buffer_adc,"a=%1.1f\n",(float)3.3);
        //memcpy(buffer_adc,&voltage,sizeof(voltage));
	    //strcat(buffer_adc, voltage);
	    ftoa(buffer_adc, voltage, 2);
	    strcat(buffer_adc, newline);
	    //HAL_UART_Transmit(&huart2,(uint8_t*)&buffer_adc,strlen(buffer_adc), 100);
	    HAL_Delay(100);
//    if(writeflag==true){
//		switch(USB_state)
//			 {
//			 case USB_READY:
//			   USB_write(msg);
//			   //USB_read();
//
//			   USB_state = USB_IDLE;
//			   writeflag=false;
//			   break;
//
//			 case USB_IDLE:
//			 default:
//			   break;
//			 }
//   }

    //MSC_Application();
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

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

static void MX_ADC3_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
    */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.ScanConvMode = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.DiscontinuousConvMode = ENABLE;
  hadc3.Init.NbrOfDiscConversion = 1;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DMAContinuousRequests = DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
    */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
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
     PC3   ------> I2S2_SD
     PA4   ------> I2S3_WS
     PA5   ------> SPI1_SCK
     PA6   ------> SPI1_MISO
     PA7   ------> SPI1_MOSI
     PB10   ------> I2S2_CK
     PC7   ------> I2S3_MCK
     PC10   ------> I2S3_CK
     PC12   ------> I2S3_SD
     PB6   ------> I2C1_SCL
     PB9   ------> I2C1_SDA
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CS_I2C_SPI_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : I2S3_WS_Pin */
  GPIO_InitStruct.Pin = I2S3_WS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(I2S3_WS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SPI1_SCK_Pin SPI1_MISO_Pin SPI1_MOSI_Pin */
  GPIO_InitStruct.Pin = SPI1_SCK_Pin|SPI1_MISO_Pin|SPI1_MOSI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin 
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : I2S3_MCK_Pin I2S3_SCK_Pin I2S3_SD_Pin */
  GPIO_InitStruct.Pin = I2S3_MCK_Pin|I2S3_SCK_Pin|I2S3_SD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Audio_SCL_Pin Audio_SDA_Pin */
  GPIO_InitStruct.Pin = Audio_SCL_Pin|Audio_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
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
