/*###############################################################
#           													#
#																#
#	Bill Turner 										Lab 4	#
#	csc-110-401										05/13/14	#
#				Pizza Program: calculates the cost				#
#			of making a pizza based on the area of the pizza	#
#			and the amount of toppings on the pizza.			#
#																#
###############################################################*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

// constant identifiers

const float COST_PER_TOP=1.10;
const float COST_PER_INCH_SQ=.075;

// function prototypes
void computeCost(float, int, float&);

int main()
{
	float PizzaDiameter;
	int Toppings;
	float Cost;
	
	cout<<"Welcome to Patsy's Pizza Cost Calculator"<<endl<<endl;
	cout<<"Please enter the diameter of the pizza:\t";
	cin>>PizzaDiameter;
	cout<<endl<<"Please enter the number of toppings:\t"; 
	cin>>Toppings;
	cout<<endl<<endl;
	computeCost(PizzaDiameter, Toppings, Cost);
	cout<<"The cost of this pizza will be:\t"<<fixed<<showpoint<<setprecision(2)<<"$"<<Cost;
	return 0;
}
	//computeCost function
	void computeCost
		(float PizzaDiameterf,
		 int Toppingsf,
		 float& Costf) 
{
	float area=(acos(-1)/4)* pow(PizzaDiameterf,2);
	Costf=area*COST_PER_INCH_SQ+Toppingsf*COST_PER_TOP;	
}
	
	


