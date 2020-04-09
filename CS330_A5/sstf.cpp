#include "diskscheduling.h"
/*
*	SSTF (Shortest Seek Time First) algorithm
*	- The request with the minimum seek time from the current head position is selected next.
*/

void sstf(diskType disk[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;
	int total_diff_sq = 0;

	cout << "----------------------------------------------------------------\n";
	cout << "***SSTF Algorithm:***\n";

	for (int i = 0; i < size; i++) {
		int min_t = MAXVAL;
		int min_val, min_position;
		for (int j = 0; j < size; j++) {
			if (abs(init - disk[j].position) < min_t && !disk[j].visited) {
				min_t = abs(init - disk[j].position);
				min_val = disk[j].position;
				min_position = j;
			}
		}
		t_difference = abs(init - disk[min_position].position);
		init = disk[min_position].position;
		disk[min_position].visited = true;
		elapsed = t_difference + elapsed;
		total_diff_sq = total_diff_sq + t_difference * t_difference;
		cout << "* Head Position: " << disk[min_position].position 
			<< ", Movement time from last position: " << t_difference << " *\n";
	}

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size) << "\n";
	cout << "Standard Deviation of movement time: " << sqrt(total_diff_sq / size) << "\n";
	cout << "----------------------------------------------------------------\n";
}