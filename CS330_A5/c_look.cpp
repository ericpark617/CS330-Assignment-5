#include "diskscheduling.h"
/*
*	C-LOOK (Circular LOOK) algorithm
*	- Similar to C-SCAN where the head moves from one end of the disk to the other.
*		Unlike C-SCAN, the head only moves as far as the last request in each direction.
*/

void c_look(diskType disk[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;

	cout << "----------------------------------------------------------------\n";
	cout << "***C-LOOK Algorithm:***\n";

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
		cout << "* Head Position: " << disk[min_position].position
			<< ", Movement time from last position: " << t_difference << " *\n";
	}

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size) << "\n";
	cout << "----------------------------------------------------------------\n";
}