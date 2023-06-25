#include <stdio.h> 
#include "driver.h" 
#include <unistd.h>


int currentCoords = 312;
int numOfSatelites = 3;

int toggle(int currState) { 
 	sleep(0.5); 
 	if (currState == 101) { return 100; } 
 	return 101; 
} 
 
int getCoords() { 
 	sleep(0.5); 
 	return currentCoords; 
} 
 
int checkConnection() { 
 	sleep(0.5); 
 	if (numOfSatelites < 3) return 102; 
 	return 103; 
}

