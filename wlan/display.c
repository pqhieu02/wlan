#include "wlan.h"

void displayAnalysis(struct ssid* ssid_list, int wlan_total) {
	printf("Found %d WLANS\n\n--------------------\n", wlan_total);
	for (int i = 0; i < wlan_total; i++) {
		printf("SSID %d: %s\n", i + 1, ssid_list[i].ssid);
		printf("This network has %d access points\n\n", ssid_list[i].ap_total);
		for (int j = 0; j < ssid_list[i].ap_total; j++) {
			printf("	BSSID %d: %s", j + 1, ssid_list[i].ap_list[j].mac_address);
			printf("		+ Channel: %d\n", ssid_list[i].ap_list[j].channel);
			printf("		+ Signal strength: %s", ssid_list[i].ap_list[j].signal_strength);
		}
		printf("--------------------\n\n");
	}
}