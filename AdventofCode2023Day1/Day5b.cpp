#include "./headers/Day5b.h"

//trying to redo day5, but this time put the filters in a Red Black Binary search tree.
//Part1 worked flawlessly :) very slightly faster on average than normal day5, but that might be a problem size issue.
//would probably see bigger benefits on a larger dataset.

int Day5b::day() {
	std::string line;
	std::fstream file("./inputs/day5input.txt");
	int lines = 1;
	

	/*
	* PARSING THE FILE AND STORING DATA
	*/
	//seed -> soil -> fertilizer -> water -> light -> temp -> humidity -> location
	std::vector<__int64> seeds; //part1 vec
	std::vector<std::pair<__int64, __int64>> seedRanges; //part2 vec
	std::vector<d5RBTree> filters(1); //used in both p1 and p2


	//get seeds
	getline(file, line);
	std::stringstream ss(line.substr(7, (line.end() - line.begin()) - 7));
	std::string seedword;
	int oddseed = 0;
	while (getline(ss, seedword, ' ')) {
		if (seedword.size() > 0) {
			seeds.push_back(_strtoui64(&seedword[0], NULL, 10));
			if (oddseed % 2 == 1) {
				seedRanges.push_back(std::make_pair(seeds[oddseed - 1], seeds[oddseed]));
			}
			oddseed++;
		}
	}
	sort(seeds.begin(), seeds.end());
	sort(seedRanges.begin(), seedRanges.end());

	int filterToFill = 0;
	getline(file, line); // skip the first blank line
	getline(file, line);
	//get data and store it in filter[filterToFill]

	int lineCount = 0;
	while (getline(file, line)) {
		lines++;
		//blank line -> skip this line and next line.
		if (line.size() == 0) {
			filters.push_back(d5RBTree()); //add a new empty RBTree to filters
			filterToFill++;
			getline(file, line);
			continue;
		}
		std::stringstream linestream(line);
		std::string convert;
		__int64 filterNumA = 0;
		__int64 filterNumB = 0;
		__int64 filterNumC = 0;
		while (getline(linestream, convert, ' ')) {
			if (convert.size() > 0) {
				filterNumA = filterNumB;
				filterNumB = filterNumC;
				filterNumC = _strtoui64(&convert[0], NULL, 10);
			}
		}
		//insert into the RBTree
		filters[filterToFill].insertNode(new d5RBtreeNode(nullptr, true, nullptr, nullptr, std::make_tuple(filterNumA, filterNumB, filterNumC)));
	}
	file.close();
	/*
	* END OF PARSING
	*/
	/*
	for (d5RBTree tree : filters) {
		std::cout << "NEW FILTER" << std::endl;
		tree.inOrderPrint();
	}
	*/


	//only bug i can forsee atm, filters overlapping on each layer.
	//possible fix, when entering filters into the tree, check sizes and adjust each node thats overlapping as we go.
	//left node gets priority over right node.
	//ex) if left overlaps by 5, right adjusts destination, source, and range size to 5 less.
	//that's only IF they overlap, idk if they do


	/*
	* Part 1
	*/
	for (int i = 0; i < filters.size(); ++i) { //for each filter
		for (int j = 0; j < seeds.size(); ++j) { //for each seed
			seeds[j] = filters[i].part1Filter(seeds[j]); //run the seed thru the filter
		}
	}





	//min_element makes an iterator to the minimum element
	//we can get the element by just pointing to it
	std::vector<long long>::iterator lowest1 = std::min_element(seeds.begin(), seeds.end());
	
	std::cout << "Day 5b:\t" << *lowest1 << std::endl;
	return lines;
}