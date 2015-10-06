#include<iostream>
#include<fstream>
#include<string>
#include <regex>
using namespace std;



void main(){

	int numIf = 0;int numWhile = 0;int numFor = 0;
	int numSwitch = 0; int numCase = 0;

	bool quotes = false;

	ifstream file;
	string content;
	smatch m;
	regex findIf("\\b(if)(\\b|[^a-zA-Z])");regex findWhile("\\b(while)(\\b|[^a-zA-Z])");
	regex findFor("\\b(for)(\\b|[^a-zA-Z])");regex findSwitch("\\b(switch)(\\b|[^a-zA-Z])");
	regex findCase("\\b(case)(\\b|[^a-zA-Z])");
	regex findQuote("\"");



	file.open("files/example.cpp");

	cout << "Wait a  second\n\n";

	while (!file.fail()){
		file >> content;

		while (regex_search(content, m, findQuote)){
			for (auto x : m);
			content = m.suffix().str();
			quotes = !quotes;
			//Makes it ignore these words when they are inside double quotes
		}

		if (quotes == false){
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
		}
	}
	file.close();

	cout << "Number of if statements: " << numIf << endl
		 << "Number of while statements: " << numWhile << endl
		 << "Number of for statements: " << numFor << endl
		 << "Number of switch statements: " << numSwitch << endl
		 << "Number of case statements: " << numCase << endl;
	
	system("Pause");



}
