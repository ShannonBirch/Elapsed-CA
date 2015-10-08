	/*Big Todo:
	*			Move everything out of main.
	*			Allow for searching multiple files.
	*			Look for similar method names.
	*			Count numbers of variables.
	*	
	*Less important:
	*			Look for similar strings
	*				Ignore include and nessacary statements
	*			
	*
	*Maybe
	*			Try and ignore quoted comment marks?
	*
	*
	*/
#include "file.h"

void main(){

	file f1("files/example.cpp");
	file f2("files/testy.cpp");

	f1.outputStats();

	f2.outputStats();

	system("pause");
}
