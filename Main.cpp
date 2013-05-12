#include <iostream>
#include "Outputter.h"



int main ( int argc , char ** argv ){
	
	GridField grid ;
	Outputter outputter;
	Initializer initializer;
	
	initializer.baseState_OneDimension_Initialization(grid);
	outputter.output_BaseState(grid);
	initializer.perturbation_Initialization(grid);
	outputter.outputCurrentTimestep(grid);
	
	return 0;

}
