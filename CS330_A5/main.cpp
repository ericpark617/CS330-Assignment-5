#include "DiskScheduling.h"

int main() {
	int cur_val, init;
	disk disk[MAXSIZE];
	int size = 0;
	string filename;
	cout << "Enter the name of the data file: ";
	cin >> filename;

	cout << "Enter the initial head position (from 0 to 9999): ";
	cin >> init;

	ifstream inFile;
	inFile.open(filename);
	if (!inFile) {
		cout << "Error in opening file.\n";
		exit(1);
	}

	while (inFile >> cur_val) {
		disk[size].position = cur_val;
		disk[size].visited = false;
		size++;
	}

	inFile.close();

	fcfs(disk, size, init);
	sstf(disk, size, init);

	return 0;
}