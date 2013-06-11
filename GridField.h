#include<iostream>
#include<cmath>
#include "Constant.h"

using namespace std;


class GridField {
	private :
		int timePerGraph;
		double currentTime;
		
	public :
		// Base state arrays
		double tb[NZ];	
		double qb[NZ];	
		double pb[NZ];
		double pib[NZ];
		double rhou[NZ];
		double rhow[NZ];

		// progonstic arrays ( Perturbated )
		double thp[NX][NZ]	,th[NX][NZ]	,thm[NX][NZ];
		double up[NX][NZ]	, u[NX][NZ]	,um[NX][NZ];
		double wp[NX][NZ]	, w[NX][NZ]	,wm[NX][NZ];
		double pip[NX][NZ]	,pi[NX][NZ]	,pim[NX][NZ];
		
		// Constructor
		GridField(void);
		GridField(int);
		
		// Get Set Functions
		void SetGraphOutputTime(int toSet){ timePerGraph = toSet ; }
		int GetGraphOutputTime(void){ return timePerGraph ; }
		void SetCurrentTime(double toSet){ currentTime = (toSet >= 0.0) ? toSet : 0.0  ; }
		double GetCurrentTime(void){ return currentTime ; }
};
