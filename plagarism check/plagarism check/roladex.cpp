//Remember to reference dreamincode.net!

#include <dirent.h>
#include <iostream>
#include <vector>

#include "file.h"
#include "Roladex.h"
using namespace std;



roladex::roladex(){
	DIR *pdir = NULL;
	struct dirent *pent = NULL;
	string dirLoc = "files";

	pdir = opendir("files");
	if (pdir == NULL){
		cout << "Error";
		exit(1);
	}

	while (pent = readdir(pdir)){
		if (pent == NULL){
			cout << "Error";
			exit(3);
		}
		if (strcmp(pent->d_name, ".") && strcmp(pent->d_name, "..")){
	
		cout << dirLoc << "/" << pent->d_name << endl;
		files.push_back(file(dirLoc + "/" + pent->d_name));
		}
	}

	closedir(pdir);
}

void roladex::allFileStats(){

	for (size_t i = 0; i < files.size(); i++){
		files.at(i).outputStats();
	}
}



