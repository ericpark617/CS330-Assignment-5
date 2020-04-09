# CS330 Assignment 5: Disk Scheduling Algorithms Comparison
Assignment 5 - Final Project for Min Kyu Park (200378413).

# Description
This project is based on the five different algorithms of disk scheduling (FCFS, SSTF, SCAN, C-SCAN, C-LOOK) from Chapter 14: File System Implementation. The program will take a list that emulates a disk. The list gets loaded with values representing the position on the disk. The list will get run through each disk scheduling algorithm and return a total seek time, average seek time, standard deviation of seek times. Also, the position of the head of the disk and the movement from the last position will be displayed with every request. At the end of each algorithm, the program will also display the actual run time of each algorithm.

# Instruction to Reproduce
The code in CS330_A5 is a project folder for Visual Studio. It is possible to open the project by clicking `CS330_A5.sln` using Microsoft Visual Studio.

Using Microsoft Visual Studio
1. Download this repo and unzip the contents.
2. Navigate to `CS330_A5` and open `CS330_A5.sln`.
3. Create a `.txt` file filled with up to 250 values between 0 and 200 and save it in the directory `CS330_A5`. Skip to step 4 if you already have a file to use or wish to use the test files already included.
4. Do `Ctrl + F5` or click `Debug -> Start Without Debugging` to run program.
5. Enter the name of the `.txt` file to use.
6. Enter the position of the disk to start at (between 0 and 200).
7. The results are displayed.

Not using Microsoft Visual Studio
1. Download this repo and unzip the contents.
2. Navigate to `CS330_A5` and compile and link all `.h` and `.cpp` files in the compiler of your choice.
3. Identical to steps 3 - 7 from `Using Microsoft Visual Studio` above.
