#include <stdio.h>
#include <unistd.h>


int main() {
	int userChoice = -1;
	while(userChoice != 5){
	
		int fl = 0;
		FILE * file;
		file = fopen("/home/vboxuser/file.txt", "a+");
		if (file == NULL) {return -1; }
		
		printf("0 to turn off/on\n1 to check connection\n2 to get coordinates\n"
			   "3 to check if the device is turned on\n"
			   "4 for lastest coordinates\n5 to exit\n");
		scanf("%d", &userChoice);
		if(userChoice == 4) fl = 1;
		fprintf(file, "%d\n", userChoice);
		fclose(file);
		sleep(1);
				
		file = fopen("/home/vboxuser/file.txt", "a+");
		if (file == NULL) {return -1; }
		while(fscanf(file, "%d", &userChoice) == 1);
		
		switch(userChoice) {
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
		
		if (userChoice != 100 && userChoice != 101 && userChoice != 102 && userChoice != 103 && userChoice != 5){
			if (fl) printf("Lastest coordinates are %d\n", userChoice);
			else printf("Current coordinates are %d\n", userChoice);	
		}
		
		printf("\n");
		fclose(file);
	}	
	

}
