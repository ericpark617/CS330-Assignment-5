#include "DiskScheduling.h"
/*
*	Function for finding the leftmost array node containing the init value.
*/

int findInitLeft(diskType disk[], int size, int init) {
	for (int i = 0; i < size; i++) {
		if (disk[i].position == init) {
			return i;
		}
	}
	return -1;
}