#include "DiskScheduling.h"
/*
*	Function for finding the rightmost array node containing the init value.
*/

int findInitRight(diskType disk[], int size, int init) {
	for (int i = size; i >= 0; i--) {
		if (disk[i].position == init) {
			return i;
		}
	}
	return -1;
}