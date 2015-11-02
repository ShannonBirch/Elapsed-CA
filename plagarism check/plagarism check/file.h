#ifndef FILE_H_
#define FILE_H_

#include<string>
#include<vector>
using namespace std;
class file
{
public:
	file(string fileLoc);
	void outputStats();
	void outputVar();
	vector<string> getIntNames();
	vector<string> getDoubleNames();

private:
	int numInt, numDouble, numChar, numStr;
	int numIf, numWhile,numFor,numSwitch,numCase;
	bool quotes, slComment, multiComment;
	string fileLocation;
	vector<string> ints, doubles;

};

#endif



