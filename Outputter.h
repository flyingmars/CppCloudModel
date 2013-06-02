#include <cmath>
#include <cstdio>
#include <cstring>
#include "Constant.h"
#include "Initializer.h"

class Outputter{

	private:
		static void output_th(GridField &,FILE *);
		static void output_w(GridField &,FILE *);
		static void output_u(GridField &,FILE *);
		static void output_pi(GridField &,FILE *);
		
	public:
		static void output_BaseState(GridField &) ;
		static void outputCurrentTimestep(GridField &,FILE ** ) ;
		
};
