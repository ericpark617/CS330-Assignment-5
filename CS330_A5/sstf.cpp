#include "diskscheduling.h"
/*
*	SSTF (Shortest Seek Time First) algorithm
*	- The request with the minimum seek time from the current head position is selected next.
*/

void sstf(disk queue[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;

	cout << "----------------------------------------------------------------";
	cout << "***SSTF Algorithm:***\n";

	for (int i = 0; i < size; i++) {
		int min_t = MAXVAL;
		int min_val, min_position;
		for (int j = 0; j < size; j++) {
			if (abs(init - queue[j].position) < min_t && !queue[j].visited) {
				min_t = abs(init - queue[j].position);
				min_val = queue[j].position;
				min_position = j;
			}
		}
		t_difference = abs(init - queue[min_position].position);
		init = queue[min_position].position;
		queue[min_position].visited = true;
		elapsed = t_difference + elapsed;
		cout << "* Head Position: " << queue[min_position].position 
			<< ", Movement time from last position: " << t_difference << " *\n";
	}

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size) << "\n";
	cout << "----------------------------------------------------------------";
}