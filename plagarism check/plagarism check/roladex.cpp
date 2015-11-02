//Remember to reference dreamincode.net!

#include <dirent.h>
#include <iostream>
#include <vector>
#include <iomanip>
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
	
		cout << "Found  " << dirLoc << "/" << pent->d_name << endl;
		files.push_back(file(dirLoc + "/" + pent->d_name));
		}
	}

	closedir(pdir);
}

void roladex::allFileStats(){

	//preston
	const char separator = ' ';
	const int width = 9;
	
	//preston
	cout << "\n"
	 << left << setw(width) << setfill(separator) << "if"
	 << left << setw(width) << setfill(separator) << "while"
	 << left << setw(width) << setfill(separator) << "for"
	 << left << setw(width) << setfill(separator) << "switch"
	 << left << setw(width) << setfill(separator) << "case"
	 << left << setw(width) << setfill(separator) << "int"
	 << left << setw(width) << setfill(separator) << "double"
	 << left << setw(width) << setfill(separator) << "char"
	 << left << setw(width) << setfill(separator) << "string"
	 << endl
	 << std::string(80, '-')
	 << endl;

	for (size_t i = 0; i < files.size(); i++){
		cout << (i + 1) << ".) ";
		files.at(i).outputStats();
	}
}

int roladex::folderSize(){
	return files.size();
}

void roladex::outputVars(int fileNum){
	files.at(fileNum - 1).outputVar();

}

void roladex::compareVars(int file1, int file2){
	int numSame=0;
	vector<string> ints1, ints2, doubles1, doubles2;
	ints1 = files.at(file1).getIntNames(); ints2 = files.at(file2).getIntNames();
	doubles1 = files.at(file1).getDoubleNames(); doubles2 = files.at(file2).getDoubleNames();

	int numVariables = ints1.size() + ints2.size() + doubles1.size() + doubles2.size();

	for (unsigned int i = 0; i < ints1.size(); i++){
		if ((ints1.at(i) == "i") || (ints1.at(i) == "j")){
			//Do nothing
		}else{
			for (unsigned int j = 0; j < ints2.size(); j++){
				if (ints1.at(i) == ints2.at(j)){
					numSame++;
					break;
				}
			}
		}
	}
	for (unsigned int i = 0; i < doubles1.size(); i++){
		if ((doubles1.at(i) == "i") || (doubles1.at(i) == "j")){
			//Do nothing
		}
		else{
			for (unsigned int j = 0; j < doubles2.size(); j++){
				if (doubles1.at(i) == doubles2.at(j)){
					numSame++;
					break;
				}
			}
		}
	}
	cout << numSame << " similarly named variables of " << numVariables 
		<<" total variables.";
}



