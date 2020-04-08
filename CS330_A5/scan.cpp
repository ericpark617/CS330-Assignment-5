#include "DiskScheduling.h"
/*
*	SCAN algorithm / Elevator algorithm
*	- The disk arm starts from a position towards closest end of the disk. 
*		The movement is reversed when it reaches the end of the disk and continues.
*/

void sstf(disk queue[], int size, int init) {
	int head;
	int elapsed = 0;
	int t_difference = 0;
	string direction;

	cout << "----------------------------------------------------------------";
	cout << "***SCAN Algorithm:***\n";
	queue[size].position = init;
	queue[size].visited = false;
	int dir_change = insertionSort(queue, size + 1, init);

	for (int i = 0; i < 2; i++) {
		if (abs(init - MINVAL) < abs(init - MAXVAL)) {
			head = dir_change;
			cout << "* Head Position: " << queue[head].position
				<< ", Movement time from last position: " << t_difference << " *\n";
			head--;
		}
		else {
			
		}

	}

		cout << "* Head Position: " << queue[min_position].position 
			<< ", Movement time from last position: " << t_difference << " *\n";

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size + 1) << "\n";
	cout << "----------------------------------------------------------------";
}