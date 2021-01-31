#include "stm32f4xx.h"
#include "fatfs.h"
#include "fatfs_sd.h"
#include "string.h"
#include <stdio.h>
#include "clock.h"
#include "gpio.h"
#include "spi2.h"
#include "usart2.h"
#include "systick.h"

FATFS fs; //file system
FIL fil; //file
FRESULT fresult; //to store the result
char buffer[1024]; //to store data

UINT br, bw;  //file read/write count

/*capacity related variables*/
FATFS *pfs;
DWORD fre_clust;
uint32_t total, free_space;

//clear buffer
void bufclear(void)
{
	for (int i = 0; i < 1024; i++)
	{
		buffer[i] = '\0';
	}
}

int main(void)
{
  
  Clocks_Init();
  SysTick_Init();
  GPIO_Init();
  SPI2_Init();
  USART2_Init(BAUD_115200);
  MX_FATFS_Init();

  /*Mount SD card*/
  fresult = f_mount(&fs, "", 0);
  if (fresult != FR_OK) USART2_TransmitString("error in mounting SD card......\n");
  else USART2_TransmitString("SD card mounted successfully\n");

  fresult = f_mount(&fs, "", 0);
  /*Card capacity details*/
  f_getfree("", &fre_clust, &pfs);

  total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5 );
  sprintf(buffer,"SD card total size: \t%d\n",total);
  USART2_TransmitString(buffer);//send_uart(buffer);
  bufclear();
  free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
  sprintf(buffer,"SD card free space: \t%d\n",free_space);
  USART2_TransmitString(buffer);

  /*Open file to write or create file if it does not exist*/
  fresult = f_open(&fil, "Autocroft1.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);

  fresult = f_puts("IoTeam is winning the next competition by God's grace\n\n", &fil);

  /*close file*/
  fresult = f_close(&fil);

  USART2_TransmitString("Autocroft1.txt created and data has been written to it\n");

  /*open file to read*/
  fresult = f_open(&fil, "Autocroft1.txt", FA_READ);

  /*read string from file*/
  f_gets(buffer, 100, &fil); //There's no fil.fsize, it'll give an error

  USART2_TransmitString(buffer);

  /*Close file*/
  f_close(&fil);
 
  while (1)
  {
   
  }
  
}
