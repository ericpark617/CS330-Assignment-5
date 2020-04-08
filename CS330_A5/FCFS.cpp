#include "DiskScheduling.h"
/*
*	FCFS (First Come First Serve) algorithm
*	- The head moves following the order of the queue.
*/
void fcfs(disk queue[], int size, int init) {
	int elapsed = 0;
	int t_difference = 0;
	cout << "----------------------------------------------------------------";
	cout << "***FCFS Algorithm:***\n";

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			t_difference = abs(init - queue[i].position);
		} else {
			t_difference = abs(queue[i - 1].position - queue[i].position);
		}
		elapsed = t_difference + elapsed;
		cout << "* Head Position: " << queue[i].position 
			<< ", Movement time from last position: " << t_difference << " *\n";
	}

	cout << "Total movement time: " << elapsed << "\n";
	cout << "Average movement time: " << ((float)elapsed / size + 1) << "\n";
	cout << "----------------------------------------------------------------";
}