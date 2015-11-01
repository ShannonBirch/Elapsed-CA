#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include<regex>
#include"file.h"
using namespace std;




file::file(string fileLoc){
	numIf = 0, numWhile = 0, numFor = 0, numSwitch = 0, numCase = 0;
	//preston
	numInt = 0, numDouble = 0, numChar = 0, numStr = 0, numFunc = 0;

		fileLocation = fileLoc;
		quotes=false, slComment=false, multiComment=false;
		ifstream file;
		string content;
		smatch m;
		regex findIf("\\b(if)(\\b|[^a-zA-Z])"); 
		regex findWhile("\\b(while)(\\b|[^a-zA-Z])");
		regex findFor("\\b(for)(\\b|[^a-zA-Z])"); 
		regex findSwitch("\\b(switch)(\\b|[^a-zA-Z])");
		regex findCase("\\b(case)(\\b|[^a-zA-Z])");
		//preston
		regex findInt("\\b(int)(\\b|[^a-zA-Z])");
		regex findDouble("\\b(double)(\\b|[^a-zA-Z])");
		regex findChar("\\b(char)(\\b|[^a-zA-Z])");
		regex findStr("\\b(string)(\\b|[^a-zA-Z])");
		regex findFunc("()", regex_constants::grep);
		regex findQuote("""", regex_constants::grep);
		regex findSLComment("//", regex_constants::grep); //Single line comment
		regex multiCommentS("/*", regex_constants::grep); //Start of multi line comments
		regex multiCommentE("*/", regex_constants::grep);//End of multi line comments

		file.open(fileLoc);

		while (getline(file, content)){
			istringstream iss(content);

			while (regex_search(content, m, findSLComment)){
				//Searches for Single line comments
				for (auto x : m) content = m.suffix().str();
				slComment = true;
				//Tells the program this is a single line comment
			}
			while (regex_search(content, m, multiCommentS)){
				for (auto x : m) content = m.suffix().str();
				multiComment = true;//Starts a multiline comment
			}
			while (regex_search(content, m, multiCommentE)){
				for (auto x : m) content = m.suffix().str();
				multiComment = false; //Ends a multiline comment
			}

			if (slComment == false && multiComment == false){
				//Ignores things that are commented out
				while (regex_search(content, m, findQuote)){
					for (auto x : m);
					content = m.suffix().str();
					quotes = !quotes;//Starts quotes

				}

				if (quotes == false){//Ignores things in quotes
					while (regex_search(content, m, findIf)){
						for (auto x : m);
						content = m.suffix().str();
						numIf++;
					}
					while (regex_search(content, m, findWhile)){
						for (auto x : m); content = m.suffix().str(); numWhile++;
					}
					while (regex_search(content, m, findFor)){
						for (auto x : m); content = m.suffix().str(); numFor++;
					}
					while (regex_search(content, m, findSwitch)){
						for (auto x : m); content = m.suffix().str(); numSwitch++;
					}
					while (regex_search(content, m, findCase)){
						for (auto x : m); content = m.suffix().str(); numCase++;
					}

					//preston
					while (regex_search(content, m, findInt)) {
						for (auto x : m); content = m.suffix().str(); numInt++;
					}
					while (regex_search(content, m, findDouble)) {
						for (auto x : m); content = m.suffix().str(); numDouble++;
					}
					while (regex_search(content, m, findChar)) {
						for (auto x : m); content = m.suffix().str(); numChar++;
					}
					while (regex_search(content, m, findStr)) {
						for (auto x : m); content = m.suffix().str(); numStr++;
					}
					while (regex_search(content, m, findFunc)) {
						for (auto x : m); content = m.suffix().str(); numFunc++;
					}
				} //The end of the quotes check
		 }//End of Comment check
			slComment = false;//Stops single line comment at end of line

		}//End of the searches


		file.close();
	}


	//preston
	void file::outputStats(){
		const char separator = ' ';
		const int width = 10;
		const int width2 = 30;

		cout << left << setw(width2) << setfill(separator) << fileLocation;
		cout << left << setw(width) << setfill(separator) << numIf;
		cout << left << setw(width) << setfill(separator) << numWhile;
		cout << left << setw(width) << setfill(separator) << numFor;
		cout << left << setw(width) << setfill(separator) << numSwitch;
		cout << left << setw(width) << setfill(separator) << numCase;
		cout << left << setw(width) << setfill(separator) << numInt;
		cout << left << setw(width) << setfill(separator) << numDouble;
		cout << left << setw(width) << setfill(separator) << numChar;
		cout << left << setw(width) << setfill(separator) << numStr;
		cout << left << setw(width) << setfill(separator) << numFunc;
		cout << endl << "\n";

	}
