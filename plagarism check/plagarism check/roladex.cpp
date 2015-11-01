//Remember to reference dreamincode.net!


#include <iostream>
#include <vector>
#include <iomanip>

#include "dirent.h"
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

	//preston
	const char separator = ' ';
	const int width = 10;
	const int width2 = 30;
	//preston
	cout << "\n";
	cout << left << setw(width2)<< setfill(separator) <<"file";
	cout << left << setw(width) << setfill(separator) << "if";
	cout << left << setw(width) << setfill(separator) << "while";
	cout << left << setw(width) << setfill(separator) << "for";
	cout << left << setw(width) << setfill(separator) << "switch";
	cout << left << setw(width) << setfill(separator) << "case";
	cout << left << setw(width) << setfill(separator) << "int";
	cout << left << setw(width) << setfill(separator) << "double";
	cout << left << setw(width) << setfill(separator) << "char";
	cout << left << setw(width) << setfill(separator) << "string";
	cout << left << setw(width) << setfill(separator) << "function";
	cout << endl;
	cout << std::string(160, '-');
	cout << endl;

	for (size_t i = 0; i < files.size(); i++){
		files.at(i).outputStats();
	}
}



