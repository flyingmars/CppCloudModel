#include <iostream>
#include "GridField.h"
#include "Initializer.h"
#include "LeapFrogMethod.h"
#include "Outputter.h"



int main ( int argc , char ** argv[] ){
	
	GridField grid ;
	Outputter outputter;

	outputter.output_BaseState(grid);
	
	
	return 0;

}