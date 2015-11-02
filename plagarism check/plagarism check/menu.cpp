#include "menu.h"
#include "Roladex.h"

#include<iostream>
using namespace std;

menu::menu(){
	
	run();
}

void menu::run(){
	r1.allFileStats();
	menuMessage();
	string command;
	cout << "\n>";
	cin >> command;
	while (command != "stop"){
		if (command == "allStats"){
			r1.allFileStats();
		}
		else if(command =="printVar"){
			int number;
			cout << "Enter the number of the file you would like to see the variables for:\n";
			cout << ">";
			cin >> number;
			if (number > 0 && number <= r1.folderSize()){
				r1.outputVars(number);
			}
			else{
				cout << "Error: Invalid file number";
			}
		}
		else if (command == "compareVars"){
			int file1, file2;
			cout << "Enter the number of the first file you would like to compare:\n>";
			cin >> file1;
			if (file1 > 0 && file1 <= r1.folderSize()){}
			else{
				cout << "Error: Invalid file number. Try again:\n>";
				bool valid = false;
				while (valid = false){
					cin >> file1;
					if (file1 > 0 && file1 <= r1.folderSize()){ valid = true; }
					else{ cout << "Error: Invalid file number. Try again:\n>"; }
				}
			}
			cout << "\n>";
			cin >> file2;
			if (file2 > 0 && file2 <= r1.folderSize()){}
			else{
				cout << "Error: Invalid file number. Try again:\n>";
				bool valid = false;
				while (valid = false){
					cin >> file2;
					if (file2 > 0 && file2 <= r1.folderSize()){ valid = true; }
					else{ cout << "Error: Invalid file number. Try again:\n>"; }
				}
			}
			r1.compareVars((file1 - 1), (file2 - 1));
		}
		else if (command == "stop"){
		}
		else{
			cout << "Command not recognised. Available commands:\n";
			menuMessage();
		}
		cout << "\n>";
		cin >> command;
	}
}

void menu::menuMessage(){
	cout << "Menu Commands: \n" <<
		"\"allStats\" \tPrints out the basic stats for all the files in the folder\n"
		<< "\"printVar\" \tPrints all the names of variables for a file\n"
		<< "\"compareVars\" \tLooks for similar variable names in each file\n"
		<< "\"stop\" \tStops the program\n";
}


