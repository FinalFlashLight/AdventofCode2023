#include <iostream>
#include <fstream>
#include <string>
#include "./headers/Day14.h"


/*

https://adventofcode.com/2023/day/14
*/
int Day14::day() {
	std::string line;
	std::fstream file("./inputs/day14input.txt");
	int lines = 0;
	int sum1 = 0, sum2 = 0;

	while (getline(file, line)) {
		lines++;


	}


	std::cout << "Day 14:\t" << sum1 << "\tand " << sum2 << std::endl;
	return lines;
}