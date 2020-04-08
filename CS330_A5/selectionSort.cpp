#include "DiskScheduling.h"

void selectionSort(disk queue[], int size) {
	int min, temp;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (queue[j].position < queue[min].position) {
				min = j;
			}
		}
		temp = queue[i].position;
		queue[i].position = queue[min].position;
		queue[min].position = temp;
	}
}