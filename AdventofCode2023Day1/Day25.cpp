#include <iostream>
#include <fstream>
#include <string>
#include "./headers/Day25.h"


/*

https://adventofcode.com/2023/day/25
*/
int Day25::day() {
	std::string line;
	std::fstream file("./inputs/day25input.txt");
	int lines = 0;
	int sum1 = 0, sum2 = 0;

	while (getline(file, line)) {
		lines++;


	}


	std::cout << "Day 25:\t" << sum1 << "\tand " << sum2 << std::endl;
	return lines;
}