#include <cmath>
#include <cstdio>
#include <cstring>
#include "Constant.h"
#include "Initializer.h"

class Outputter{

	private:
		static void output_th(GridField &);
		static void output_w(GridField &);
		static void output_u(GridField &);
		static void output_pi(GridField &);
		
	public:
		static void output_BaseState(GridField &) ;
		static void outputCurrentTimestep(GridField &) ;
		
};
