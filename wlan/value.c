#include "wlan.h"

char* getValue(char* c) {
	static char value[100];
	memset(value, 0, sizeof(value)); // need to empty the string before reading. This "value" is static variable.
	int flag = 0; // flag = true when it is ready to find the value (pass the first ':' or not)
	for (int i = 0; i < strlen(c); i++) {
		if (flag == 0 && c[i] == ':') {
			flag = 1; // start to get the field's value after passing the first ':'
			continue;
		}
		if (strlen(value) == 0 && c[i] == ' ') {
			continue; // do nothing if c[i] is meaningless space
		}
		else { // if c[i] is not meaningless space
			if (flag == 1) { // is it ready to start to read the value ? 
				value[strlen(value)] = c[i];
			}
		}
	}
	//printf("getValue() has been executed!\n");
	return value;
}