#define CMD "netsh wlan show networks mode=bssid > wlan.txt"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct ap {
	char mac_address[20];
	char signal_strength[10];
	int channel;
};

struct ssid {
	char ssid[30];
	int ap_total;
	struct ap ap_list[20];
};

void analyse(FILE* fp);
char* getValue(char*);
char* fieldIdentifier(char*);
void displayAnalysis(struct ssid*, int);

