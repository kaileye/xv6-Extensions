#include "types.h"
#include "user.h"

int prng(){
	static int s1 = 2016103781;
	static int s2 = 1789513354;
	static int s3 = 44784530;
	static int s4 = 1052555986;
	int r = s2;
	r ^= r << 11;
	r ^= r >> 8;
	s2 = s3;
	s3 = s4;
	s4 = s1;
	s1 ^= s1 >> 19;
    s1 ^= r;
	return r;
}

int main(int argc, char *argv[]){
	int i;
	int a[64] = {0};
	for(i = 0; i < 640000; i++){
		a[prng() % 64] += 1;
	}
	for(i = 0; i < 64; i++){
		printf(1, "%d: %d\n", i, a[i]);
	}
	
	exit();
}