#include "Initializer.h"

// Public Interface

void Initializer::baseState_OneDimension_Initialization(GridField & grid){	
	const double x_k = R_D / C_P ;		
	double tbv_previous,tbv_current,tbvavg;
	
	grid.pb[1]   = PSURF;
	grid.tb[1]   = base_ThetaBar_Distribution(1);
	grid.qb[1]   = base_QvBar_Distribution(1);
	tbv_previous = grid.tb[1]*(1 + 0.61*grid.qb[1] );
	
	grid.pib[1]  = pow(grid.pb[1]/PZERO,x_k) - GRAVITY*0.5*DZ/(C_P*tbv_previous);	
	grid.rhou[1] = PZERO * pow(grid.pib[1],C_V/R_D ) / ( R_D * tbv_previous );
	grid.rhow[1] = grid.rhou[1];
	
	for (int k=2;k<=NZ-2;k++){
		
		grid.tb[k] = base_ThetaBar_Distribution(k);
		grid.qb[k] = base_QvBar_Distribution(k);

		tbv_current = grid.tb[k]*(1 + 0.61*grid.qb[k] );
		tbvavg = 0.5 * ( tbv_current + tbv_previous ) ;
		
		grid.pib[k] = grid.pib[k-1] - GRAVITY * DZ / (C_P * tbvavg) ;
		grid.pb[k]   = PZERO * pow(grid.pib[k],C_P/R_D);
		grid.rhou[k] = PZERO * pow(grid.pib[k],C_V/R_D ) / ( R_D * tbvavg );
		grid.rhow[k] = 0.5*( grid.rhou[k] + grid.rhou[k-1] );
		
		tbv_previous = tbv_current;
	}

	
	grid.tb[0] = grid.tb[1];		grid.tb[NZ-1] = grid.tb[NZ-2];
	grid.pib[0] = grid.pib[1]; 		grid.pib[NZ-1] = grid.pib[NZ-2];
	grid.rhou[0] = grid.rhou[1];	grid.rhou[NZ-1] = grid.rhou[NZ-2];
	grid.rhow[0] = grid.rhow[1];	grid.rhow[NZ-1] = grid.rhow[NZ-2];
	grid.qb[0]= grid.qb[1]; 		grid.qb[NZ-1] = grid.qb[NZ-2];

}

void Initializer::perturbation_Initialization_Cold(GridField & grid){
	const double TRIGPI = 4.*atan(1.0);
	const double imid   =  (NX%2 == 0) ? (double)NX/2 : ((double)NX-1.0)/2 ;
	const double zcnt   =  3000 ;
	const double delta  =  5.0;
	const double radx   =  4000.0 , radz = 2000.0;


	
	double currentRad;
	double tup,tdn;
	double z_scalar;
	

	
	/* Create Theta perturbation */
	for (int i=1;i<=NX-2;i++){
		for (int k=1;k<=NZ-2;k++){
			z_scalar = DZ * (k - 0.5);
			currentRad = sqrt( pow( (z_scalar - zcnt)/radz , 2 ) + pow( DX*( i - imid )/radx , 2 ) ) ;

			if ( currentRad >= 1 ){
				grid.th[i][k] = 0;
			}else{
				grid.th[i][k] = 0.5 * delta * ( cos( TRIGPI * currentRad ) + 1 );
			}
			/* make sure the first step run correctly */
			grid.thm[i][k] = grid.th[i][k];
		}
	}
	
	/* Modify Pressure Adjustment to Initial Temperature Perturbation  */

	for (int i=1; i<=NX-2;i++){
		grid.pi[i][NZ-1] = 0;
		
		for (int k=NZ-2;k>=1;k--) {
			tup = grid.th[i][k+1]/( grid.tb[k+1] * grid.tb[k+1] );
			tdn = grid.th[i][k] / (grid.tb[k] * grid.tb[k]) ;
			grid.pi[i][k] = grid.pi[i][k+1] - 0.5 * ( GRAVITY / C_P ) * ( tup + tdn ) * DZ;
			/* make sure the first step run correctly */
			grid.pim[i][k] = grid.pi[i][k];
		}
		grid.pi[i][0] = grid.pi[i][1];
		grid.pim[i][0] = grid.pim[i][1];
	}

	
	return;
}

void Initializer::perturbation_Initialization(GridField & grid){
	const double TRIGPI = 4.*atan(1.0);
	const double imid   =  (NX%2 == 0) ? (double)NX/2 : ((double)NX-1.0)/2 ;
	const double zcnt   =  3000 ;
	const double delta  =  5.0;
	const double radx   =  4000.0 , radz = 4000.0;


	
	double currentRad;
	double tup,tdn;
	double z_scalar;
	

	
	/* Create Theta perturbation */
	for (int i=1;i<=NX-2;i++){
		for (int k=1;k<=NZ-2;k++){
			z_scalar = DZ * (k - 0.5);
			currentRad = sqrt( pow( (z_scalar - zcnt)/radz , 2 ) + pow( DX*( i - imid )/radx , 2 ) ) ;

			if ( currentRad >= 1 ){
				grid.th[i][k] = 0;
			}else{
				grid.th[i][k] = 0.5 * delta * ( cos( TRIGPI * currentRad ) + 1 );
			}
			/* make sure the first step run correctly */
			grid.thm[i][k] = grid.th[i][k];
		}
	}
	
	/* Modify Pressure Adjustment to Initial Temperature Perturbation  */

	for (int i=1; i<=NX-2;i++){
		grid.pi[i][NZ-1] = 0;
		
		for (int k=NZ-2;k>=1;k--) {
			tup = grid.th[i][k+1]/( grid.tb[k+1] * grid.tb[k+1] );
			tdn = grid.th[i][k] / (grid.tb[k] * grid.tb[k]) ;
			grid.pi[i][k] = grid.pi[i][k+1] - 0.5 * ( GRAVITY / C_P ) * ( tup + tdn ) * DZ;
			/* make sure the first step run correctly */
			grid.pim[i][k] = grid.pi[i][k];
		}
		grid.pi[i][0] = grid.pi[i][1];
		grid.pim[i][0] = grid.pim[i][1];
	}

	
	return;
}


/* Private Function */
double Initializer::base_ThetaBar_Distribution(int z_grid_index){

	const double z_TR = 12000; 			//[m] Height level of Tropopause
	const double T_TR = 213;			//[K] Temperature of Tropopause
	const double Theta_TR = 343; 		//[K] Potential Temperature of Tropopause
	double z_T = ( (double)z_grid_index - 0.5) * DZ ;	
	
	if(z_T <= z_TR){
		return ( 300 + 43 * pow(z_T / z_TR , 1.25) ) ;
	}else{
		return ( Theta_TR * exp( GRAVITY *(z_T - z_TR)/(C_P * T_TR) ) ) ;
	}

}


double Initializer::base_QvBar_Distribution(int z_grid_index){
	
	double z_T = ( (double)z_grid_index - 0.5) * DZ ;
	
	
	if(z_T <= 4000){
		return 0.0161 - 0.000003375 * z_T ; 
	}else if (z_T <= 8000){
		return 0.0026 - 0.00000065 * (z_T -4000) ;
	}else{
		return 0;
	}
}


