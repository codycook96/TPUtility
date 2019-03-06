#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>

std::vector<std::string> getAllFiles(std::string directory, std::string type){
	std::vector<std::string> namesAll;
	//Following code block modified from https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
	DIR *dir;
	std::string fname = "";
	struct dirent *ent;
	
	if ((dir = opendir (directory.c_str())) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			fname = ent->d_name;
			//std::cout << fname << std::endl;
			std::size_t pos = fname.find(type);
			if (pos!=std::string::npos){
				namesAll.push_back(fname);
			}
		}
		closedir (dir);
	} else {
	/* could not open directory */
		perror ("");
		//return EXIT_FAILURE;
	}
	
	return namesAll;
}

#endif