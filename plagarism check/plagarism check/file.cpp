#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <regex>
#include "file.h"
using namespace std;




file::file(string fileLoc){
		numIf = 0, numWhile = 0, numFor = 0, numSwitch = 0, numCase = 0;
		//preston
		numInt = 0, numDouble = 0, numChar = 0, numStr = 0;
		//Preston 
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
		//
		regex findInt("\\b(int)(\\b|[^a-zA-Z])");
		regex findDouble("\\b(double)(\\b|[^a-zA-Z])");
		regex findChar("\\b(char)(\\b|[^a-zA-Z])");
		regex findStr("\\b(string)(\\b|[^a-zA-Z])");
		//


		regex findQuote("\"");
		regex findSLComment("//"); //Single line comment
		regex multiCommentS("/\\*"); //Start of multi line comments
		regex multiCommentE("\\*/");//End of multi line comments

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
					//Recording variable names
					//preston
					regex intName("int ([[:w:]]+)");
					while (regex_search(content, m, intName)){
						for (auto x : m);
						ints.push_back(m._At(1).str());
						break;
					}

					regex doubleName("double ([[:w:]]+)");
					while (regex_search(content, m, doubleName)){
						for (auto x : m);
						doubles.push_back(m._At(1).str());
						break;
					}

					//End of Recording variable names
					//Counting things
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
						for (auto x : m); content = m.suffix().str();numCase++;
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

				} //The end of the quotes check
			}//End of Comment check
			slComment = false;//Stops single line comment at end of line

		}//End of the searches


		file.close();
	}

	void file::outputStats(){
		const char separator = ' ';
		const int width = 9;
		

		cout << fileLocation << ":" << endl
		 << left << setw(width) << setfill(separator) << numIf
		 << left << setw(width) << setfill(separator) << numWhile
		 << left << setw(width) << setfill(separator) << numFor
		 << left << setw(width) << setfill(separator) << numSwitch
		 << left << setw(width) << setfill(separator) << numCase
		 << left << setw(width) << setfill(separator) << numInt
		 << left << setw(width) << setfill(separator) << numDouble
		 << left << setw(width) << setfill(separator) << numChar
		 << left << setw(width) << setfill(separator) << numStr
		 << endl;
	}

	void file::outputVar(){
		cout << "Ints:\n";
		for (int i = 0; i < ints.size(); i++){
			cout << ints.at(i) << endl;
		}
		cout << "Doubles:\n";
		for (int i = 0; i < doubles.size(); i++){
			cout << doubles.at(i) << endl;
		}
	}

	vector<string> file::getIntNames(){
		return ints;
	}
	vector<string> file::getDoubleNames(){
		return doubles;
	}


	