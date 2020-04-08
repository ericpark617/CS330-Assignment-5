#ifndef DISKSCHEDULING_H
#define DISKSCHEDULING_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MAXSIZE = 250;
const int MAXVAL = 9999;
const int MINVAL = 0;

struct disk {
	int position;
	bool visited;
};

void fcfs(disk queue[], int size, int init);
void sstf(disk queue[], int size, int init);
void scan(disk queue[], int size, int init);
void c_scan(disk queue[], int size, int init);
void c_look(disk queue[], int size, int init);
int insertionSort(disk queue[], int size, int val);

#endif