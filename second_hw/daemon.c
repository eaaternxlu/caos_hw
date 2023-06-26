#include <stdio.h>
#include "driver.h"
#include <unistd.h>
#include <stdlib.h>

int lastCoords = 305;
int isConnected = 0; 
int isOn = 0;		
int loop() {
	int userChoice = -1; 
    while(1) {
    	isOn = checkIfIsOn();
    	isConnected = checkConnection();
    	
    	if (isOn && isConnected) lastCoords = getCoords();
    	
     	FILE * file;
        file = fopen("/home/vboxuser/file.txt", "a+");
        if(file == NULL) 
            return -1;
        while(fscanf(file, "%d", &userChoice) == 1);
        if(userChoice >= 100) {
        	sleep(0.5);
        	fclose(file);
        	continue;    	
        }
        
        switch(userChoice) {
        
        	case 0:
        		isOn = toggle(isOn);
        		if (isOn) fprintf(file, "%d\n", 101);
        		else fprintf(file, "%d\n", 100);
        		break;
        		
        	case 1:
        		if (!isOn) {
        			fprintf(file, "%d\n", 100);
        			break;
        		}
        		else {
        			if (isConnected) fprintf(file, "%d\n", 103);
        			else fprintf(file, "%d\n", 102);
        			break;
        		}
        		
        	case 2:
        		if (!isOn) {
        			fprintf(file, "%d\n", 100);
        		}
        		else {
        			fprintf(file, "%d\n", lastCoords);
				}
				break;
				        		
        	case 3:
        		if (isOn) fprintf(file, "%d\n", 101);
        		else fprintf(file, "%d\n", 100);
        		break;
        		
        	case 4:
        		fprintf(file, "%d\n", lastCoords);
        		break;       		
        }
        fclose(file); 
        sleep(0.1);     
    } 
    return 0; 
} 

int main() { 
	int pid = fork(); 
	switch(pid) { 
		case 0: 
			setsid(); 
			chdir("/"); 
			fclose(stdin); 
			fclose(stdout); 
			fclose(stderr);
			loop(); 
			exit(0); 
		case -1: 
			printf("Unable to fork\n"); 
			break; 
		default: 
			printf("Daemon with pid %d is created\n", pid); 
			break; 
	}  
 	return 0; 
}
