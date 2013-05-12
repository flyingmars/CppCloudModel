#include <cmath>
#include <cstdio>
#include <cstring>
#include "Constant.h"
#include "Initializer.h"

class Outputter{

	private:
		void output_th(GridField &);
		void output_w(GridField &);
		void output_u(GridField &);
		void output_pi(GridField &);
		
	public:
		void output_BaseState(GridField &) ;
		void outputCurrentTimestep(GridField &) ;
		
};
