#include "diskscheduling.h"
/*
*	C-SCAN (Circular SCAN) algorithm
*	- The head moves from one end of the disk to the other.
*		When the other end is reached, the head moves to the beginning of the diskType and continues.
*/

void c_scan(diskType disk[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;
	int total_diff_sq = 0;
	diskType sortedDisk[MAXSIZE];

	cout << "----------------------------------------------------------------\n";
	cout << "***C-SCAN Algorithm:***\n";

	for (int i = 0; i < size; i++) {
		sortedDisk[i] = disk[i];
	}

	sortedDisk[size].position = MINVAL;
	sortedDisk[size + 1].position = MAXVAL;
	size = size + 2;

	selectionSort(sortedDisk, size);

	if (abs(init - MINVAL) < abs(init - MAXVAL)) {
		int init_head = findInitRight(sortedDisk, size, init);
		for (int i = init_head; i >= 0; i--) {
			if (i == init_head) {
				t_difference = 0;
			}
			else {
				t_difference = abs(sortedDisk[i].position - sortedDisk[i + 1].position);
			}
			elapsed = t_difference + elapsed;
			total_diff_sq = total_diff_sq + t_difference * t_difference;
			cout << "* Head Position: " << sortedDisk[i].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
		for (int j = size - 1; j > init_head; j--) {
			if (j == size - 1) {
				t_difference = abs(sortedDisk[j].position - sortedDisk[0].position);
			}
			else {
				t_difference = abs(sortedDisk[j].position - sortedDisk[j + 1].position);
			}
			elapsed = t_difference + elapsed;
			total_diff_sq = total_diff_sq + t_difference * t_difference;
			cout << "* Head Position: " << sortedDisk[j].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
	}
	else {
		int init_head = findInitLeft(sortedDisk, size, init);
		for (int j = init_head; j < size; j++) {
			if (j == init_head) {
				t_difference = 0;
			}
			else {
				t_difference = abs(sortedDisk[j].position - sortedDisk[j - 1].position);
			}
			elapsed = t_difference + elapsed;
			total_diff_sq = total_diff_sq + t_difference * t_difference;
			cout << "* Head Position: " << sortedDisk[j].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
		for (int i = 0; i < init_head; i++) {
			if (i == 0) {
				t_difference = abs(sortedDisk[i].position - sortedDisk[size - 1].position);
			}
			else {
				t_difference = abs(sortedDisk[i].position - sortedDisk[i - 1].position);
			}
			elapsed = t_difference + elapsed;
			total_diff_sq = total_diff_sq + t_difference * t_difference;
			cout << "* Head Position: " << sortedDisk[i].position
				<< ", Movement time from last position: " << t_difference << " *\n";
		}
	}

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size) << "\n";
	cout << "Standard Deviation of movement time: " << sqrt(total_diff_sq / size) << "\n";
	cout << "----------------------------------------------------------------\n";
}