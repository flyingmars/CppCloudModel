#include "GridField.h"


GridField :: GridField(void){
	/* Make sure initial value are all zeros  */
	
	for (int i=0;i<NX;i++){
		for (int k=0;k<NZ;k++){
			thp[i][k]=0	;	th[i][k]=0	;	thm[i][k]=0 ;
			up[i][k]=0	; 	u[i][k]=0	;	um[i][k]=0  ;
			wp[i][k]=0	; 	w[i][k]=0	;	wm[i][k]=0  ;
			pip[i][k]=0	;	pi[i][k]=0	;	pim[i][k]=0 ;
		}
	}
	
	for (int k=0;k<NZ;k++){
		tb[k] = 0;	
		qb[k] = 0;	
		pb[k] = 0;	
		pib[k] = 0;	
		rhou[k] = 0;	
		rhow[k] = 0;	
		
	}	
	
	timePerGraph = 1 ;
	currentTime = 0;

}


GridField :: GridField(int inputTimePerGraph){
	
	/* Make sure initial value are all zeros  */
	
	for (int i=0;i<NX;i++){
		for (int k=0;k<NZ;k++){
			thp[i][k]=0	;	th[i][k]=0	;	thm[i][k]=0 ;
			up[i][k]=0	; 	u[i][k]=0	;	um[i][k]=0  ;
			wp[i][k]=0	; 	w[i][k]=0	;	wm[i][k]=0  ;
			pip[i][k]=0	;	pi[i][k]=0	;	pim[i][k]=0 ;
		}
	}
	
	for (int k=0;k<NZ;k++){
		tb[k] = 0;	
		qb[k] = 0;	
		pb[k] = 0;	
		pib[k] = 0;	
		rhou[k] = 0;	
		rhow[k] = 0;	
		
	}	
	
	timePerGraph = inputTimePerGraph ;
	currentTime = 0;

}
