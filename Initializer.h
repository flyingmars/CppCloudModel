#include<iostream>
#include<cmath>
#include "Constant.h"
#include "GridField.h"


using namespace std;

class Initializer{
	public :
		void perturbation_Initialization(GridField & );
		void baseState_OneDimension_Initialization(GridField & );
	private :
		double base_ThetaBar_Distribution(int );
		double base_QvBar_Distribution(int );
};