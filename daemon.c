#include <stdio.h>
#include "driver.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int isConnected = 103;
int currState = 100;
int lastCoords = 305;

int loop() 
{ 
	int userChoice = -1; 
    int fd; 
    while(1){
     	FILE * file;
        file = fopen("/home/vboxuser/file.txt", "a+");
        if(file == NULL) 
            return -1;
        while(fscanf(file, "%d", &userChoice) == 1);
        if(userChoice >= 100) {
        	sleep(1);
        	fclose(file);
        	continue;    	
        }
        switch(userChoice){
        	case 0:
        		currState = toggle(currState);
        		fprintf(file, "%d\n", currState);
        		break;
        	case 1:
        		if (currState == 100) {
        			fprintf(file, "%d\n", currState);
        			break;
        		}
        		else {
        			isConnected = checkConnection();
        			fprintf(file, "%d\n", isConnected);
        			break;
        		}
        	case 2:
        		if (currState == 100) {
        			fprintf(file, "%d\n", currState);
        		}
        		else {
        			lastCoords = getCoords();
        			fprintf(file, "%d\n", lastCoords);
				}
				break;        		
        	case 3:
        	    fprintf(file, "%d\n", currState);
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



