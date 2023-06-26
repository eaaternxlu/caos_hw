#include <stdio.h>
#include <unistd.h>


int main() {
	int userChoice = -1;
	int daemonAns = -1;
	while(userChoice != 5){
	
		int fl = 0;
		FILE * file;
		file = fopen("/home/vboxuser/file.txt", "a+");
		if (file == NULL) return -1;
		
		printf("0 to turn off/on\n1 to check connection\n2 to get current coordinates if possible\n"
			   "3 to check if the device is turned on\n"
			   "4 for the latest coordinates\n5 to exit\n");
		scanf("%d", &userChoice);
		if(userChoice == 4) fl = 1;
		fprintf(file, "%d\n", userChoice);
		fclose(file);
		sleep(1);
				
		file = fopen("/home/vboxuser/file.txt", "a+");
		if (file == NULL) return -1;
		while(fscanf(file, "%d", &daemonAns) == 1);
		
		switch(daemonAns) {
			case 100:
				printf("The device is turned off\n");
				break;
			case 101:
				printf("The device is turned on\n");
				break;
			case 102:
				printf("Not connected\n");
				break;
			case 103:
				printf("Connected\n");
				break;
		}
		
		if (daemonAns != 100 && daemonAns != 101 && daemonAns != 102 && daemonAns != 103 && userChoice != 5){
			if (fl) printf("The latest coordinates are %d\n", daemonAns);
			else printf("Current coordinates are %d\n", daemonAns);	
		}
		
		printf("\n");
		fclose(file);
	}	
	

}
