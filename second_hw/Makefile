project: daemon.o driver.o
	gcc -o project daemon.o driver.o
daemon.o: daemon.c
	gcc -c daemon.c
driver.o: driver.c
	gcc -c driver.c
clean:
	rm -f *.o project  
