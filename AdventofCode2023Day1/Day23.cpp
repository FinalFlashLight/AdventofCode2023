#include <iostream>
#include <fstream>
#include <string>
#include "./headers/Day23.h"


/*

https://adventofcode.com/2023/day/23
*/
int Day23::day() {
	std::string line;
	std::fstream file("./inputs/day23input.txt");
	int lines = 0;
	int sum1 = 0, sum2 = 0;

	while (getline(file, line)) {
		lines++;


	}


	std::cout << "Day 23:\t" << sum1 << "\tand " << sum2 << std::endl;
	return lines;
}