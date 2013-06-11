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


void Outputter::outputCurrentTimestep(GridField &grid, FILE * fp_Mat[4] ){
	double  divisionResult = grid.GetCurrentTime() / (double)DT  / (double)grid.GetGraphOutputTime() ;
	int truncatResult =  (int)(divisionResult + 0.5) ;
	
	if( abs(divisionResult - (double)truncatResult) < 1E-8  ){
		output_th(grid,fp_Mat[0]);
		output_w(grid,fp_Mat[1]);
		output_u(grid,fp_Mat[2]);
		output_pi(grid,fp_Mat[3]);
		cout << "Time = " << grid.GetCurrentTime() << endl ;
	}
	return ;
}




void Outputter::output_th(GridField & grid,FILE* fp){

	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.th[i][k]);
		}
		fprintf(fp,"%d ",245145);
	}
	
	fprintf(fp,"%d ",192168);
	
	return ;

}
void Outputter::output_w(GridField & grid,FILE* fp){
	
	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.w[i][k]);
		}
		fprintf(fp,"%d ",245145);
	}
	
	fprintf(fp,"%d ",192168);
	
	return ;
}
void Outputter::output_u(GridField & grid,FILE* fp){

	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.u[i][k]);
		}
		fprintf(fp,"%d ",245145);
	}
	
	fprintf(fp,"%d ",192168);
	
	return ;
}
void Outputter::output_pi(GridField & grid,FILE* fp){

	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.pi[i][k]);
		}
		fprintf(fp,"%d ",245145);
	}
	
	fprintf(fp,"%d ",192168);
	
	return ;
}
