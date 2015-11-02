#ifndef ROLADEX_H_
#define ROLADEX_H_
#include <string>
#include <vector>
#include "file.h"
using namespace std;
class roladex
{
public:
	roladex();
	void allFileStats();
	int folderSize();
	void outputVars(int fileNum);
	void compareVars(int file1, int file2);

private:
	vector<file> files;

};

#endif

