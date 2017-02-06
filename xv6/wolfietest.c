#include "types.h"
#include "user.h"

int main (void) {
	char* buffer = malloc(5000);
	if (buffer == 0) {
		exit();
	}
	if (wolfie(buffer, 5000) < 0) {
		exit();
	}
	printf(1, buffer);
	free(buffer);
	exit();
}