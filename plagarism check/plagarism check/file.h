#ifndef FILE_H_
#define FILE_H_

#include<string>
using namespace std;
class file
{
public:
	file(string fileLoc);
	void outputStats();

private:
	int numIf, numWhile,numFor,numSwitch,numCase;
	bool quotes, slComment, multiComment;
	string fileLocation;

};

#endif



