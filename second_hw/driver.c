#include <stdio.h> 
#include "driver.h" 
#include <unistd.h>

int currentCoords = 312;
int numOfSatelites = 3;
int isOn1 = 0;

int checkIfIsOn() {
	return isOn1;
}

int toggle(int currState) { 
 	sleep(0.5); 
 	if (currState) {
 		isOn1 = 0;
 		return 0;
 	}
 	else {
 		isOn1 = 1;	
 		return 1;
 	} 
} 
 
int getCoords() { 
 	sleep(0.5); 
 	return currentCoords; 
} 
 
int checkConnection() { 
 	sleep(0.5); 
 	if (numOfSatelites < 3) return 0; 
 	return 1; 
}
