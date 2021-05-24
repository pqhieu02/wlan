#include "wlan.h";

int main() {
	system(CMD);
	FILE* fi = fopen("wlan.txt", "r");
	if (fi == NULL) {
		printf("Error: wlan.txt file does not exist!\n");
	}
	analyse(fi);
	printf("\n\n\n");
	fclose(fi);
}