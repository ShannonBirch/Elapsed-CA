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
#include "Roladex.h"
#include <dirent.h>
#include <iostream>
void main(){

	roladex r1;
	r1.allFileStats();


	system("pause");
}
