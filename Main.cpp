#include <iostream>
#include "LeapFrogMethod.h"

GridField grid(PERGRAPH) ;

int main ( int argc , char ** argv ){
	
	
	Initializer::baseState_OneDimension_Initialization(grid);
	Initializer::perturbation_Initialization_Cold(grid);

	Outputter::output_BaseState(grid);
	LeapFrogMethod::compute_all(grid,FINISHTIME);
	
	
	return 0;

}
