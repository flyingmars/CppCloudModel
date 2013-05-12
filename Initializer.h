#include<iostream>
#include<cmath>
using namespace std;

class Initializer{
	public :
		void perturbation_Initialization(GridField & );
		void baseState_OneDimension_Initialization(GridField & );
	private :
		double base_ThetaBar_Distribution(int );
		double base_QvBar_Distribution(int );
};