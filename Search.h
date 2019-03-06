#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>

#include "Common.h"

void search(std::string searchTerm, std::string directory){
	
	std::vector<std::string> namesAll;
	std::vector<int> lines;
	std::string line;
	
	std::vector<std::string> found;
	
	namesAll = getAllFiles(directory, ".LS");
	
	std::cout << "\"" << searchTerm << "\" Found at:\n\n";
	//std::ofstream searchFile("search_results.txt");
	for(int i=0; i<namesAll.size(); i++){	
		std::ifstream file(directory + "\\" + namesAll.at(i));
		
		int numLine = 1;
		
		while (std::getline(file, line)) {
			std::size_t pos = line.find(searchTerm);
			if (pos!=std::string::npos){
				found.push_back(namesAll.at(i));
				std::cout << namesAll.at(i) << " line " << numLine << ":\n\t" << line << "\n" << std::endl;
			}
			numLine++;
		}
		file.close();
	}
	std::cin >> line;
	
}


#endif