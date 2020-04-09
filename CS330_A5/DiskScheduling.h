#ifndef DISKSCHEDULING_H
#define DISKSCHEDULING_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXSIZE = 250;
const int MAXVAL = 200;
const int MINVAL = 0;

struct diskType {
	int position;
	bool visited;
};

void fcfs(diskType disk[], int size, int init);
void sstf(diskType disk[], int size, int init);
void scan(diskType disk[], int size, int init);
void c_scan(diskType disk[], int size, int init);
void c_look(diskType disk[], int size, int init);
int findInit(diskType disk[], int size, int init);
void selectionSort(diskType disk[], int size);

#endif