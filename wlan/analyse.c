#include "wlan.h"

void analyse(FILE* fi) {
	char c[100];
	int line = 0;
	int ssid_index = -1;
	int ap_index = -1;
	int wlan_found = 0;
	struct ssid ssid_list[100];

	while (fgets(c, 100, fi) != NULL) {
		line++;
		if (c[0] != '\n') {
			//printf("Line %d----%s", line, c); // show full file
		}
		if (line > 2) {
			char field[100] = "";
			strcpy(field, fieldIdentifier(c));
			//printf("%s\n", field);

			// Get SSID 
			if (strcmp(field, "SSID") == 0) {
				//printf("%s : %s\n", field, getValue(c));

				//set up for new ssid
				wlan_found++;
				ssid_index++;
				ap_index = -1;
				ssid_list[ssid_index].ap_total = 0;
				
				strcpy(ssid_list[ssid_index].ssid, getValue(c));
				//printf("%s\n", ssid_list[ssid_index].ssid);
				//printf("%s\n", ssid_list[ssid_index].ssid);
			}

			//Get BSSID 
			if (strcmp(field, "BSSID") == 0) {
				//printf("%s : %s\n", field, getValue(c));
				ap_index++;
				ssid_list[ssid_index].ap_total++;
				strcpy(ssid_list[ssid_index].ap_list[ap_index].mac_address, getValue(c));
			}

			//get Channel 
			if (strcmp(field, "Channel") == 0) {
				//printf("%s : %s\n", field, getValue(c));
				ssid_list[ssid_index].ap_list[ap_index].channel = atoi(getValue(c));
			}

			//Get Signal strength 
			if (strcmp(field, "Signal") == 0) {
				//printf("%s : %s\n", field, getValue(c));
				strcpy(ssid_list[ssid_index].ap_list[ap_index].signal_strength, getValue(c));
			}
		}
	}
	printf("--------------------\n\n\nAnalyse completed!\n\n\n--------------------\n\n");
	displayAnalysis(ssid_list, wlan_found);
}