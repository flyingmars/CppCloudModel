#include "Outputter.h"



void Outputter::output_BaseState(GridField & grid){

	double z_T;
	
	printf("z          tb         qb       rhou     rhow     pi\n");
	for (int k=0;k<NZ;k++){
		z_T = ( (double)k - 0.5) * DZ ;
		printf("%10.2f %8f %8f %8f %8f %8f\n",z_T,grid.tb[k],grid.qb[k],grid.rhou[k],grid.rhow[k],grid.pib[k]);
	}
	return ;


}
