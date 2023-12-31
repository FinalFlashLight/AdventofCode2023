// AdventofCode2023Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "./headers/AdventofCode2023.h"

int main()
{
    std::cout << "Advent of code 2023 :)" << std::endl << std::endl;
    std::cout << "notes: " << std::endl;
    std::cout << "\tday5b uses a vector of redblack trees to store the filters. Only part 1 is finished so far." << std::endl << std::endl;
    std::cout << "\ti'm skipping day12 for now, part 1 takes about 45 seconds. Part 2... no." << std::endl << std::endl;
    std::cout << "\tday14 part1 is finished, part2 i'll have to learn a bit more about detecting cycles, but spincycle() is good to go" << std::endl << std::endl;
    std::cout << "\tday16 takes 15-16 seconds, just add 16 seconds to final time." << std::endl << std::endl;
    
    
    concurrency::concurrent_vector<int> lines;
    concurrency::concurrent_vector<Day*> days;
    
    days.push_back( new Day1() );
    days.push_back( new Day2() );
    days.push_back( new Day3() );
    days.push_back( new Day4() );
    days.push_back( new Day5() );
    days.push_back( new Day5b() );                  //created redblack tree for the filters, part1 is good, part2 requires merging of filters in the rbtree(not done yet)
    days.push_back( new Day6() );
    days.push_back( new Day7() );
    days.push_back( new Day8() );
    days.push_back( new Day9() );
    days.push_back(new Day10());
    //days.push_back(new Day10b());                 //attempt at creating a window and drawing the pipes
    days.push_back( new Day11() );
    //days.push_back( new Day12() );   //day12 is still very brute force, but part 1 passes in about 45 seconds. Part 2 doesnt get past the first line in... a while. new strat needed.           
    days.push_back( new Day13() );
    days.push_back( new Day14() );
    days.push_back( new Day15() );
    //days.push_back( new Day16() );    //day16 takes 16seconds T-T, another method entirely would be needed to shorten this.
    //days.push_back( new Day17() );
    //days.push_back( new Day18() );
    days.push_back( new Day19() );
    //days.push_back( new Day20() );
    //days.push_back( new Day21() );
    //days.push_back( new Day22() );
    //days.push_back( new Day23() );
    //days.push_back( new Day24() );
    //days.push_back( new Day25() );


    std::cout << "-------- results for each day --------" << std::endl;

    concurrency::concurrent_vector<std::pair<std::string, std::chrono::milliseconds>> durations;

    auto totalstart =           std::chrono::high_resolution_clock::now();

        
    //running the days in parallel makes it slower T-T
    //I won't do anymore parallelizing until I learn a bit more about it.

    std::for_each(/*std::execution::par, */ days.begin(), days.end(), [&](Day* day) {  
        auto start =            std::chrono::high_resolution_clock::now();

        lines.push_back(day->day()); 

        auto finish =           std::chrono::high_resolution_clock::now();

        durations.push_back(std::make_pair(typeid(*day).name(), 
            std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)));
        });

    auto totalfinish =          std::chrono::high_resolution_clock::now();


    std::cout << std::endl << "-------Times for each day in milliseconds -------" << std::endl;
    std::cout << "these times include reading from the input and running Part 1 and Part 2." << std::endl << std::endl;

    for (int i = 0; i < durations.size(); ++i) {
        std::cout << durations[i].first.substr(6) << ":\t" << 
            durations[i].second.count() << "ms \t input size: " <<
            lines[i] << " lines." << std::endl;
    }
    
    auto totalmilliseconds =    std::chrono::duration_cast<std::chrono::milliseconds>(totalfinish - totalstart);

    std::cout << "all days total: " << totalmilliseconds.count() << "ms" << std::endl;

    system("pause");
}