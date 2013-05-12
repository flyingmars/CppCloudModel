#include <iostream>
#include "LeapFrogMethod.h"



int main ( int argc , char ** argv ){
	
	GridField grid(3) ;
	
	
	Initializer::baseState_OneDimension_Initialization(grid);
	Initializer::perturbation_Initialization(grid);

	Outputter::output_BaseState(grid);
	LeapFrogMethod::compute_all(grid,2000);
	
	
	return 0;

}
