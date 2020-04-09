#include "DiskScheduling.h"
/*
*	Function for finding the array node containing the init value.
*/

int findInit(diskType disk[], int size, int init) {
	for (int i = size; i >= 0; i--) {
		if (disk[i].position == init) {
			return i;
		}
	}
	return -1;
}