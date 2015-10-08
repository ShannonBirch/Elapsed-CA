#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <regex>
#include "file.h"
using namespace std;




file::file(string fileLoc){
		numIf = 0, numWhile = 0, numFor = 0, numSwitch = 0, numCase = 0;
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

				} //The end of the quotes check
			}//End of Comment check
			slComment = false;//Stops single line comment at end of line

		}//End of the searches


		file.close();
	}

	void file::outputStats(){
		cout << "Displaying stats for " << fileLocation << ":\n\n"
			 << "Number of if statements: " << numIf << endl
			 << "Number of while statements: " << numWhile << endl
			 << "Number of for statements: " << numFor << endl
			 << "Number of switch statements: " << numSwitch << endl
			 << "Number of case statements: " << numCase << endl;

	}
