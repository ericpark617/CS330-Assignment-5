#include "DiskScheduling.h"

int insertionSort(disk queue[], int size, int val) {
	int temp, j, dir_change;
	for (int i = 1; i < size; i++) {
		temp = queue[i].position;
		for (j = 0; j >= 0 && temp < queue[i].position; j--) {
			queue[j + 1].position = queue[j].position;
		}
		queue[j + 1].position = temp;
		if (temp = val) {
			dir_change = i;
		}
	}
	return dir_change;
}