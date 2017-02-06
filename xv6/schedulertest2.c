#include "types.h"
#include "user.h"


int main(int argc, char *argv[]){
	int selectedCount = 0;
	int ticks;
	
	if (0 == fork()){
		ticks = uptime();
		nice(19);
		while(1){
			selectedCount += 1;
			if (20000 == selectedCount){
				ticks = uptime() - ticks;
				printf(1, "Process 1(19) reached 20000 increments in %d ticks.\n", ticks);
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
				if (20000 == selectedCount){
					ticks = uptime() - ticks;
					printf(1, "Process 2(19) reached 20000 increments in %d ticks.\n", ticks);
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
					if (20000 == selectedCount){
						ticks = uptime() - ticks;
						printf(1, "Process 3(19) reached 20000 increments in %d ticks.\n", ticks);
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
						if (20000 == selectedCount){
							ticks = uptime() - ticks;
							printf(1, "Process 4(19) reached 20000 increments in %d ticks.\n", ticks);
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
				}
			}
		}
	}
	
	printf(1, "\n");
	
	
	if (0 == fork()){
		ticks = uptime();
		nice(-20);
		while(1){
			selectedCount += 1;
			if (20000 == selectedCount){
				ticks = uptime() - ticks;
				printf(1, "Process 1(-20) reached 20000 increments in %d ticks.\n", ticks);
				exit();
			}
			yield();
		}
	}
	else{
		if (0 == fork()){
			ticks = uptime();
			nice(-20);
			while(1){
				selectedCount += 1;
				if (20000 == selectedCount){
					ticks = uptime() - ticks;
					printf(1, "Process 2(-20) reached 20000 increments in %d ticks.\n", ticks);
					exit();
				}
				yield();
			}
		}
		else{
			if (0 == fork()){
				ticks = uptime();
				nice(-20);
				while(1){
					selectedCount += 1;
					if (20000 == selectedCount){
						ticks = uptime() - ticks;
						printf(1, "Process 3(-20) reached 20000 increments in %d ticks.\n", ticks);
						exit();
					}
					yield();
				}
			}
			else{
				if (0 == fork()){
					ticks = uptime();
					nice(-20);
					while(1){
						selectedCount += 1;
						if (20000 == selectedCount){
							ticks = uptime() - ticks;
							printf(1, "Process 4(-20) reached 20000 increments in %d ticks.\n", ticks);
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