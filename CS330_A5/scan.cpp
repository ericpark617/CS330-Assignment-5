#include "DiskScheduling.h"
/*
*	SCAN algorithm / Elevator algorithm
*	- The disk arm starts from a position towards closest end of the disk. 
*		The movement is reversed when it reaches the end of the disk and continues.
*/

//come back

void scan(diskType disk[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;
	diskType sortedDisk[MAXSIZE];

	cout << "----------------------------------------------------------------\n";
	cout << "***SCAN Algorithm:***\n";

	for (int i = 0; i < size; i++) {
		sortedDisk[i] = disk[i];
	}

	selectionSort(sortedDisk, size);
	int dir_change = findInit(sortedDisk, size, init);

	if (abs(init - MINVAL) < abs(init - MAXVAL)) {
		
		for (int i = dir_change; i >= 0; i--) {
			if (i == dir_change) {
				t_difference = 0;
			}
			else {
				t_difference = abs(sortedDisk[i].position - sortedDisk[i + 1].position);
			}
			elapsed = t_difference + elapsed;
			cout << "* Head Position: " << sortedDisk[i].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
		for (int j = dir_change + 1; j < size; j++) {
			if (j == dir_change + 1) {
				t_difference = abs(sortedDisk[j].position - sortedDisk[0].position);
			}
			else {
				t_difference = abs(sortedDisk[j].position - sortedDisk[j - 1].position);
			}
			elapsed = t_difference + elapsed;
			cout << "* Head Position: " << sortedDisk[j].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
	}
	else {
		for (int j = dir_change; j < size; j++) {
			if (j == dir_change) {
				t_difference = 0;
			}
			else {
				t_difference = abs(sortedDisk[j].position - sortedDisk[j - 1].position);
			}
			elapsed = t_difference + elapsed;
			cout << "* Head Position: " << sortedDisk[j].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
		for (int i = dir_change - 1; i > 0; i--) {
			if (i == dir_change) {
				t_difference = abs(sortedDisk[i].position - sortedDisk[size - 1].position);
			}
			else {
				t_difference = abs(sortedDisk[i].position - sortedDisk[i + 1].position);
			}
			elapsed = t_difference + elapsed;
			cout << "* Head Position: " << sortedDisk[i].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
	}


	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size) << "\n";
	cout << "----------------------------------------------------------------\n";
}