#include "types.h"
#include "user.h"


int main(int argc, char *argv[]){
	int selectedCount = 0;
	int ticks;
	
	if (0 == fork()){
		ticks = uptime();
		nice(0);
		while(1){
			selectedCount += 1;
			if (500000 == selectedCount){
				ticks = uptime() - ticks;
				printf(1, "Process 1(0) reached 500000 increments in %d ticks.\n", ticks);
				exit();
			}
			yield();
		}
	}
	else{
		if (0 == fork()){
			ticks = uptime();
			nice(0);
			while(1){
				selectedCount += 1;
				if (500000 == selectedCount){
					ticks = uptime() - ticks;
					printf(1, "Process 2(0) reached 500000 increments in %d ticks.\n", ticks);
					exit();
				}
				yield();
			}
		}
		else{
			if (0 == fork()){
				ticks = uptime();
				nice(19);
				while(1){
					selectedCount += 1;
					if (selectedCount % 1000 == 0){
						printf(1, "Process 3 (%d) increments: %d.\n", nice(0), selectedCount);
					}
					if (selectedCount % 2500 == 0){
						nice(-1);
					}
					if (100000 == selectedCount){
						ticks = uptime() - ticks;
						printf(1, "Process 3(%d) reached 100000 increments in %d ticks.\n", nice(0), ticks);
						exit();
					}
					yield();
				}
			}
			else{
				if (0 == fork()){
					ticks = uptime();
					nice(19);
					while(1){
						selectedCount += 1;
						if (selectedCount % 1000 == 0){
						printf(1, "Process  4(19) increments: %d.\n", selectedCount);
					}
						if (100000 == selectedCount){
							ticks = uptime() - ticks;
							printf(1, "Process 4(variable) reached 100000 increments in %d ticks.\n", ticks);
							exit();
						}
						yield();
					}
				}
				else{
					wait();
					wait();
					wait();
					wait();
					exit();
				}
			}
		}
	}
	
	/*if (0 == fork()){
		
	}
	else{
		wait();
		exit();
	}*/
}