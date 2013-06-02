#include<iostream>
#include<cmath>
#include "Constant.h"
#include "GridField.h"


using namespace std;

class Initializer{
	public :
		static void perturbation_Initialization(GridField & );
		static void baseState_OneDimension_Initialization(GridField & );
		static void perturbation_Initialization_Cold(GridField & );
	private :
		static double base_ThetaBar_Distribution(int );
		static double base_QvBar_Distribution(int );
};