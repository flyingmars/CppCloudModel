#include "LeapFrogMethod.h"


void LeapFrogMethod::compute_du_dt(GridField & grid){
	
	/* Main function calculate du_dt */
	for (int k=1;k<NZ-1;k++){
		for (int i=1;i<NX-1;i++){
			grid.up[i][k] = grid.um[i][k] - 0.25 * DTX *( ( grid.u[i+1][k] + grid.u[i][k])*( grid.u[i+1][k] + grid.u[i][k]) 
											 -  ( grid.u[i-1][k] + grid.u[i][k])*( grid.u[i-1][k] + grid.u[i][k]) )
								- 0.25 * DTZ *( grid.rhow[k+1] *( grid.w[i][k+1]+ grid.w[i-1][k+1] )
														  *( grid.u[i][k+1]+ grid.u[i  ][k  ] )
											   -grid.rhow[k  ] *( grid.w[i][k  ]+ grid.w[i-1][k  ] )
														  *( grid.u[i][k-1]+ grid.u[i  ][k  ] )) / grid.rhou[k] 
							    - DTX * C_P * grid.tb[k] * ( grid.pi[i][k] - grid.pi[i-1][k] ) 
								
								+ DTX * (double)KX/(double)DX * (grid.u[i+1][k] - 2.*grid.u[i][k] + grid.u[i-1][k]) /* Diffusion Term */
								+ DTZ * (double)KZ/(double)DZ * (   ( grid.u[i][k+1] - (grid.u[i+1][k] - grid.u[i-1][k])/2. ) -
												  2.*( grid.u[i][k]   - (grid.u[i+1][k] - grid.u[i-1][k])/2. ) +
												    ( grid.u[i][k-1] - (grid.u[i+1][k] - grid.u[i-1][k])/2. ) ) ;	

		}
	}
	/* zero gradient for top and bottom */
	for (int i=1;i<NX-1;i++){
		grid.up[i][0] = grid.up[i][1] ;
		grid.up[i][NZ-1]= grid.up[i][NZ-2] ;
	}
	/* Periodic for left and right */
	for (int k=1;k<NZ-1;k++){
		grid.up[0][k] = grid.up[NX-2][k];
		grid.up[NX-1][k] = grid.up[1][k];
	}
	
	return ;


}
void LeapFrogMethod::compute_dw_dt(GridField & grid){


	
	
	for (int k=1;k<NZ-1;k++){
		for (int i=1;i<NX-1;i++){
			grid.wp[i][k] =  - DTX * ( 0.25 * ( grid.u[i+1][k] + grid.u[i+1][k-1]) * ( grid.w[i+1][k] + grid.w[i  ][k] ) 
								 -0.25 * (grid.u[i  ][k] + grid.u[i  ][k-1]) * ( grid.w[i  ][k] + grid.w[i-1][k] ) )
						- DTZ * ( 0.25 * grid.rhou[k  ]* (grid.w[i][k+1] + grid.w[i][k  ])*( grid.w[i][k+1] + grid.w[i][k  ])
								 -0.25 * grid.rhou[k-1]* (grid.w[i][k  ] + grid.w[i][k-1])*( grid.w[i][k  ] + grid.w[i][k-1]) ) / grid.rhow[k]
						- C_P * (double)DT * ( grid.tb[k] + grid.tb[k-1] ) * ( grid.pi[i][k] - grid.pi[i][k-1] ) / (double)DZ 
						+ GRAVITY * (double)DT * ( ( grid.th[i][k] / grid.tb[k] ) + ( grid.th[i][k-1] / grid.tb[k-1] ) ) 
						+DTX * (double)KX/(double)DX * (  grid.w[i+1][k]- 2.*grid.w[i][k] + grid.w[i-1][k] ) 			
						+DTZ * (double)KZ/(double)DZ * (  grid.w[i][k+1]- 2.*grid.w[i][k] + grid.w[i][k-1] )	/* Diffusion Term */
						+ grid.wm[i][k] ;
		}
	}
	
	/* zero gradient for top and bottom */
	for (int i=1;i<NX-1;i++){
		grid.wp[i][0] = grid.wp[i][1] ;
		grid.wp[i][NZ-1]= grid.wp[i][NZ-2] ;
	}
	/* Periodic for left and right */
	for (int k=1;k<NZ-1;k++){
		grid.wp[0][k] = grid.wp[NX-2][k];
		grid.wp[NX-1][k] = grid.wp[1][k];
	}
	
	return ;	


}
void LeapFrogMethod::compute_dtheta_dt(GridField & grid){
	
	for (int k=1;k<NZ-1;k++){
		for (int i=1;i<NX-1;i++){	
			grid.thp[i][k]  =
				- DTX *( 0.5 * grid.u[i+1][k] * ( grid.th[i+1][k] + grid.th[i  ][k] ) 
						-0.5 * grid.u[i  ][k] * ( grid.th[i  ][k] + grid.th[i-1][k] ) )
				- DTZ/(grid.rhou[k]) * ( 0.5 * grid.rhow[k+1] * grid.w[i][k+1] * ( grid.th[i][k+1] + grid.th[i][k  ] ) 
								   -0.5 * grid.rhow[k  ] * grid.w[i][k  ] * ( grid.th[i][k  ] + grid.th[i][k-1] ) )
				- (double)DT / (grid.rhou[k]) * ( grid.rhow[k+1] * grid.w[i][k+1] * ( grid.tb[k+1] - grid.tb[k  ] ) / (double)DZ  
										  +grid.rhow[k  ] * grid.w[i][k  ] * ( grid.tb[k  ] - grid.tb[k-1] ) / (double)DZ )
				+ DTX * (double)KX/(double)DX * (  grid.th[i+1][k]- 2.*grid.th[i][k] + grid.th[i-1][k] ) 			
				+ DTZ * (double)KZ/(double)DZ * (  grid.th[i][k+1]- 2.*grid.th[i][k] + grid.th[i][k-1] )	/* Diffusion Term */										  				  
				+ grid.thm[i][k] ;
		}
	}
	
	/* zero gradient for top and bottom */
	for (int i=1;i<NX-1;i++){
		grid.thp[i][0] = grid.thp[i][1] ;
		grid.thp[i][NZ-1]= grid.thp[i][NZ-2] ;
	}
	/* Periodic for left and right */
	for (int k=1;k<NZ-1;k++){
		grid.thp[0][k] = grid.thp[NX-2][k];
		grid.thp[NX-1][k] = grid.thp[1][k];
	}
	
	return ;	


}
void LeapFrogMethod::compute_dpi_dt(GridField & grid){

	const double c_s2 = (double)C_S * (double)C_S ; // sound speed (adiabatic)
	
	for (int k=1;k<NZ-1;k++){
		for (int i=1;i<NX-1;i++){	
			grid.pip[i][k]=
				-( c_s2 / ( grid.rhou[k] * C_P * grid.tb[k] * grid.tb[k] ) ) * ( 2.* (double)DT ) *
					( 1./(double)DX * grid.rhou[k] * grid.tb[k] * ( grid.u[i+1][k] - grid.u[i][k] ) 
					 +1./(double)DZ * ( 0.5 * grid.rhow[k+1] * grid.w[i][k+1] * ( grid.tb[k+1] + grid.tb[k  ] ) 
							  -0.5 * grid.rhow[k  ] * grid.w[i][k  ] * ( grid.tb[k  ] + grid.tb[k-1] ) ) )
				+ DTX * (double)KX/(double)DX * (  grid.pi[i+1][k]- 2.*grid.pi[i][k] + grid.pi[i-1][k] ) 			
				+ DTZ * (double)KZ/(double)DZ * (  grid.pi[i][k+1]- 2.*grid.pi[i][k] + grid.pi[i][k-1] )	/* Diffusion Term */								  
				+ grid.pim[i][k] ;
		}
	}
	/* zero gradient for top and bottom */
	for (int i=1;i<NX-1;i++){
		grid.pip[i][0] = grid.pip[i][1] ;
		grid.pip[i][NZ-1]= grid.pip[i][NZ-2] ;
	}
	/* Periodic for left and right */
	for (int k=1;k<NZ-1;k++){
		grid.pip[0][k] = grid.pip[NX-2][k];
		grid.pip[NX-1][k] = grid.pip[1][k];
	}
	
	return ;


}
void LeapFrogMethod::compute_all(GridField & grid , int timend){
	
	int currentTime = 0;
	
	// Output Base Condition
	Outputter::outputCurrentTimestep(grid);
	
	while ( currentTime < timend){

		/* compute functions */
		compute_du_dt(grid);
		compute_dw_dt(grid);
		compute_dtheta_dt(grid);
		compute_dpi_dt(grid);
		
		/* Data pass routine */
		for (int i=0;i<NX;i++){
			for (int k=0;k<NZ;k++){
				grid.thm[i][k] = grid.th[i][k] ; grid.th[i][k] = grid.thp[i][k] ;
				grid.um[i][k]  = grid.u[i][k]  ; grid.u[i][k]  = grid.up[i][k]  ; 
				grid.wm[i][k]  = grid.w[i][k]  ; grid.w[i][k]  = grid.wp[i][k]  ;
				grid.pim[i][k] = grid.pi[i][k]; grid.pi[i][k]  = grid.pip[i][k];
			}	
		}

		/* timestep routine */
		currentTime += DT ;
		grid.SetCurrentTime(currentTime);
		
		
		/* output routine */
		Outputter::outputCurrentTimestep(grid);
	}
	
	printf("Output Time=0 to Time= %d\n",timend);
	return ;



}
