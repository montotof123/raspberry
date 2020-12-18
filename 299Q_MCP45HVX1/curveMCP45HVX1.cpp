#include <iostream>
#include <stdlib.h>

#include "GestionMCP45HVX1.h"
#include "GestionINA219.h"

#include <pigpio.h>

using namespace std;

GestionMCP45HVX1 mcp45hv51;
GestionINA219 ina219;

int main(void) {
	
	if(!mcp45hv51.InitMCP45HVX1(mcp45hv51.ADRESSE_0x3C, mcp45hv51.R5K)) {
		exit(0);
	}
	ina219.init(ADDR_40);
	ina219.reset();
	ina219.setCalibration_0_4A(_16V, B_12Bits_128S_69MS, S_12Bits_128S_69MS, ShuntAndBusVoltageContinuous);
	gpioDelay(3000000); // 3000ms
	
	cout << "valeur;bus voltage;shunt voltage" << endl;
	mcp45hv51.connect();
	mcp45hv51.setValue(0);
	
	cout <<  dec << mcp45hv51.getValue() << ";";
	bool conversion = false;
	while(!conversion){
		conversion  = ina219.isConversionOk();
	}
	cout <<  ina219.getBusVoltage_V() << ";";
	cout <<  ina219.getShuntVoltage_mV() << endl;
	
	for(int compteur = 0; compteur != 256; compteur++) {
		gpioDelay(500000); // 500ms
		cout <<  mcp45hv51.increment() << ";";
		conversion = false;
		while(!conversion){
			conversion  = ina219.isConversionOk();
		}
		// Mesure
		cout <<  ina219.getBusVoltage_V() << ";";
		cout <<  ina219.getShuntVoltage_mV() << endl;
	}
	for(int compteur = 0; compteur != 256; compteur++) {
		gpioDelay(500000); // 500ms
		cout <<  mcp45hv51.decrement() << ";";
		conversion = false;
		while(!conversion){
			conversion  = ina219.isConversionOk();
		}
		// Mesure
		cout <<  ina219.getBusVoltage_V() << ";";
		cout <<  ina219.getShuntVoltage_mV() << endl;
	}
	for(int compteur = 0; compteur != 256; compteur++) {
		gpioDelay(500000); // 500ms
		cout <<  mcp45hv51.increment() << ";";
		conversion = false;
		while(!conversion){
			conversion  = ina219.isConversionOk();
		}
		// Mesure
		cout <<  ina219.getBusVoltage_V() << ";";
		cout <<  ina219.getShuntVoltage_mV() << endl;
	}
	for(int compteur = 0; compteur != 256; compteur++) {
		gpioDelay(500000); // 500ms
		cout <<  mcp45hv51.decrement() << ";";
		conversion = false;
		while(!conversion){
			conversion  = ina219.isConversionOk();
		}
		// Mesure
		cout <<  ina219.getBusVoltage_V() << ";";
		cout <<  ina219.getShuntVoltage_mV() << endl;
	}
}
