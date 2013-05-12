#include<iostream>
#include<cmath>
#include "Constant.h"
#include "Outputter.h"

class LeapFrogMethod{
	
	private :
		static void compute_du_dt(GridField &);
		static void compute_dw_dt(GridField &);
		static void compute_dtheta_dt(GridField &);
		static void compute_dpi_dt(GridField &);

	public :
		static void compute_all(GridField & , int);

};