#include <stdint.h>
#include <stdio.h>
#include "string.h"

#include "clock.h"
#include "systick.h"

#include "diskio.h"
#include "sd_card.h"
#include "ff.h"
#include "serial.h"

FATFS fs; //file system
FIL fil; //file
FRESULT fresult; //to store the result
char buffer[1024]; //to store data

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
	SD_SPI_Init();
	Serial_Init();

  /*Mount SD card*/
  fresult = f_mount(&fs, "", 0);
  if (fresult != FR_OK) Serial_Transmit("error in mounting SD card......\n");
  else Serial_Transmit("SD card mounted successfully\n");

  fresult = f_mount(&fs, "", 0);
  /*Card capacity details*/
  f_getfree("", &fre_clust, &pfs);

  total = (uint32_t)((pfs->n_fatent - 2) * pfs->csize * 0.5 );
  sprintf(buffer,"SD card total size: \t%d\n",total);
  Serial_Transmit(buffer);
  bufclear();
  free_space = (uint32_t)(fre_clust * pfs->csize * 0.5);
  sprintf(buffer,"SD card free space: \t%d\n",free_space);
  Serial_Transmit(buffer);

  /*Open file to write or create file if it does not exist*/
  fresult = f_open(&fil, "FILE.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);

  fresult = f_puts("Let's get the job done\n", &fil);

  /*close file*/
  fresult = f_close(&fil);

  /*open file to read*/
  fresult = f_open(&fil, "FILE.txt", FA_READ);

  /*read string from file*/
  f_gets(buffer, 100, &fil);

  Serial_Transmit(buffer);

  /*Close file*/
  f_close(&fil);
 
  while (1)
  {
   
  }
  
}
