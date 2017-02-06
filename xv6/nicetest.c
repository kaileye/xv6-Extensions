#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	printf(1, "nice(0) returns %d\n", nice(0));
	printf(1, "nice(-30) returns %d\n", nice(-30));
	printf(1, "nice(0) returns %d\n", nice(0));
	printf(1, "nice(30) returns %d\n", nice(30));
	printf(1, "nice(0) returns %d\n", nice(0));
	printf(1, "nice(99) returns %d\n", nice(99));
	printf(1, "nice(0) returns %d\n", nice(0));
	exit();
}