#include "wlan.h"

char* fieldIdentifier(char* c) {
	static char field[100]; // string in C is an array. we need static char variable and char pointer function in order to return char function
	memset(field, 0, sizeof(field)); // need to empty the string before reading. This "value" is static variable.
	for(int i = 0; i < strlen(c); i++) {
		if (c[i] != ' ') {
			field[strlen(field)] = c[i];
		}
		if (c[i] == ' ' && strlen(field) != 0) { // return the field when we got the first word in the line 
			return field;
		}
	}
	//printf("fieldIdentifier() has been executed!\n");
	return "Unknow line";
}