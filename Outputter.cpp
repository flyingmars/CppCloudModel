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


void Outputter::outputCurrentTimestep(GridField &grid){
	if( grid.GetCurrentTime()/DT % grid.GetGraphOutputTime() == 0 )
		output_th(grid);
		output_w(grid);
		output_u(grid);
		output_pi(grid);
	return ;
}




void Outputter::output_th(GridField & grid){
	char outputString[100]; sprintf(outputString,"./%d_%s.txt",grid.GetCurrentTime(),"th");
	FILE* fp = fopen(outputString,"wb");
	
	
	
	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.th[i][k]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	
	return ;

}
void Outputter::output_w(GridField & grid){
	char outputString[100]; sprintf(outputString,"./%d_%s.txt",grid.GetCurrentTime(),"w");
	FILE* fp = fopen(outputString,"wb");
	
	
	
	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.w[i][k]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	
	return ;
}
void Outputter::output_u(GridField & grid){
	char outputString[100]; sprintf(outputString,"./%d_%s.txt",grid.GetCurrentTime(),"u");
	FILE* fp = fopen(outputString,"wb");
	
	
	
	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.u[i][k]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	
	return ;
}
void Outputter::output_pi(GridField & grid){
	char outputString[100]; sprintf(outputString,"./%d_%s.txt",grid.GetCurrentTime(),"pi");
	FILE* fp = fopen(outputString,"wb");
	
	for (int i=1;i<NX-2;i++){
		for (int k=1;k<NZ-2;k++){
			fprintf(fp,"%lf ",grid.pi[i][k]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	
	return ;
}
