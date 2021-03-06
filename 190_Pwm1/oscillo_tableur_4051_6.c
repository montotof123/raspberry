/*oscillo tableur.c*/

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <time.h>
#include <linux/spi/spidev.h>

#include "mcp3208.h"

const int PinMax = 22;
const int PinMid = 27;
const int PinMin = 17;

int main (void)
{

	// Entete
	printf("temps;valeur\n");
	
	// Initialisation wiringPi
	if(wiringPiSetupGpio() < 0) {
		printf("erreur initialisation wiringPi\n");
	}
	
    pinMode(PinMax, OUTPUT);
    pinMode(PinMid, OUTPUT);
    pinMode(PinMin, OUTPUT);

	digitalWrite(PinMax, HIGH);
	digitalWrite(PinMid, HIGH); 
	digitalWrite(PinMin, LOW);

		// Initialisation SPI
	if(wiringPiSPISetup (channel1, SPI_SPEED_33) < 0) {		//initialisation du SPI sur le "channel1" et a 1250kHz
		printf("erreur wiringPi SPI\n"); 
	}
	
	// Mesure le plus vite possible
	while(1){
		printf("%d;%d\n", clock(), conversion_mcp3208(channel1, voie_7));
	}
	
	return 0 ;
}
