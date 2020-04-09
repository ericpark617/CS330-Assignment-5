#include "DiskScheduling.h"
/*
*	Selection Sort function
*/

void selectionSort(diskType disk[], int size) {
	int min, temp;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (disk[j].position < disk[min].position) {
				min = j;
			}
		}
		temp = disk[i].position;
		disk[i].position = disk[min].position;
		disk[min].position = temp;
	}
}