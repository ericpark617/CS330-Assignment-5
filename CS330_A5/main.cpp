#include "DiskScheduling.h"
/*
*	This program getes a list of integers from 0 to 500 from a file.
*	The list is used as an emulation of a disk.
*	Five disk scheduling algorithms are ran on the same list.
*	It displays each request as it is ran, the seek time from the last request, and the average seek time for the whole algorithm.
*/

int main() {
	int cur_val, init;
	diskType disk[MAXSIZE];
	int size = 1;
	string filename;

	cout << "Enter the name of the data file: ";
	cin >> filename;

	cout << "Enter the initial head position (0 to 200): ";
	cin >> init;

	ifstream inFile;
	inFile.open(filename);
	if (!inFile) {
		cout << "Error in opening file.\n";
		exit(1);
	}

	disk[0].position = init;
	disk[0].visited = false;
	while (inFile >> cur_val) {
		disk[size].position = cur_val;
		disk[size].visited = false;
		size++;
	}

	inFile.close();

	auto start = std::chrono::steady_clock::now();
	fcfs(disk, size, init);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> run_time = end - start;
	cout << "FCFS Algorithm run time: " << run_time.count() << " seconds\n";

	start = std::chrono::steady_clock::now();
	sstf(disk, size, init);
	end = std::chrono::steady_clock::now();
	run_time = end - start;
	cout << "SSTF Algorithm run time: " << run_time.count() << " seconds\n";

	start = std::chrono::steady_clock::now();
	scan(disk, size, init);
	end = std::chrono::steady_clock::now();
	run_time = end - start;
	cout << "SCAN Algorithm run time: " << run_time.count() << " seconds\n";

	start = std::chrono::steady_clock::now();
	c_scan(disk, size, init);
	end = std::chrono::steady_clock::now();
	run_time = end - start;
	cout << "C-SCAN Algorithm run time: " << run_time.count() << " seconds\n";

	start = std::chrono::steady_clock::now();
	c_look(disk, size, init);
	end = std::chrono::steady_clock::now();
	run_time = end - start;
	cout << "C-LOOK Algorithm run time: " << run_time.count() << " seconds\n";

	return 0;
}