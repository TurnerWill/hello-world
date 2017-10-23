/*#######################################################################
#																		#
#	Bill Turner												05/05/14	#
#	csc 401													Program 3	#
#																		#
#	WATER BILL program.. using getline to read account name,			#
#	menu function for account code choices (along with error msg 		#
#	for incorrect account type choices), using a repitition structure	#
# 	to allow user to calculate more than one bill.						#
#																		#
#######################################################################*/


//compiler directives

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>

using namespace std;

// constant identifiers

	// residential (Case H) constants:
	
	int	RES_TIER1 = 10000; // gallon usage 10000 or less
	int RES_TIER2 = 13000; // gallon usage over 10000 up to 23000
	int RES_TIER3 = 23000; // for gallon usage over 23000
	float RES_LINE_FEE = 22.09; // residential line fee rate
	float RES_RATE_TIER1 = 2.42; // dollars per gallons unit for tier 1 use
	float RES_RATE_TIER2 = 3.22; // dollars per gallons unit for tier 2 use
	float RES_RATE_TIER3 = 4.03; // dollars per gallons unit for tier 3 use
	int GALLON_FEE_UNIT = 1000; //  chargeable gallons unit (ie for res, 1000 gallons=2.42 at tier 1)

	// industrial (Case I) constants:
	
	int IND_TIER1 = 200000; // gallon usage 200,000 or less
	int IND_TIER2 = 2500000; // gallon usage over 200,000 up to 2,700,000
	int IND_TIER3 = 2700000; // gallon usage over 2,700,000
	float IND_LINE_FEE = 18.41; // industrial line fee rate
	float IND_RATE_TIER1 = 2.16; // dollars per gallons unit for tier 1 use
	float IND_RATE_TIER2 = 1.73; // dollars per gallons unit for tier 2 use
	float IND_RATE_TIER3 = 4.03; // dollars per gallons unit for tier 3 use
	int GALLON_IND_UNIT= 1000; // chargeable gallons unit

	// commercial (Case C) constants:

	float COMM_LINE_FEE = 22.09; // commercial line fee rate
	float COMM_RATE_TIER1 = 2.65; // dollars per gallons unit for tier 1 use (the only tier in this case)
	int GALLON_COMM_UNIT = 1000; // chargeable gallons unit
	

// function prototypes
	 char menuChoice(char&);

int main ()

{	
	char Choice; // account type choice ( residential H or h, comm C or c, Industrial I or i
	string AccountName;
	string AccountType;
	int AccountNumber;
	float GallonsUsed;
	int AccountCode;
	float AmountDue;
	char Another;
	
	do
	{
	cout<<"\t"<<"\t"<<"Welcome to the Onondaga Water Bill Calculator"<<endl;
	cout<<"Please enter your account name:<terminate with # sign>\t";
	getline(cin,AccountName,'#');//reads string as account name until # is read
	cout<<"Please enter your 5 digit account number\t";
	cin>>AccountNumber;
	cout<<"Please enter the number of gallons used this quarter\t";
	cin>>GallonsUsed;
	cout<<"Please choose from the following account types:"<<endl;
		
	menuChoice(Choice);	
	// begin rate schedule switch
	
	if ((Choice=='H')||(Choice=='h'))
	{
	AccountType="Residential";
	AccountCode=1;
	}	
	else
		if ((Choice=='C')||(Choice=='c'))
		{
		AccountType="Commercial";
		AccountCode=2;
		}
		else
			if((Choice=='I')||(Choice=='i'))
			{
			AccountType="Industrial";
			AccountCode=3;
			}
			
	
	switch (AccountCode)
	
	{
	
		case 1:
			if(GallonsUsed<=RES_TIER1)
			{
			 AmountDue= ((GallonsUsed/GALLON_FEE_UNIT)*RES_RATE_TIER1+RES_LINE_FEE);
			}
			else
				if(GallonsUsed>RES_TIER1&&GallonsUsed<=RES_TIER3)
				{
				AmountDue=float ((GallonsUsed-RES_TIER1)/GALLON_FEE_UNIT*RES_RATE_TIER2)+((RES_TIER1/GALLON_FEE_UNIT)*
							RES_RATE_TIER1)+RES_LINE_FEE;
				}
				else
					AmountDue=((GallonsUsed-RES_TIER3)/GALLON_FEE_UNIT*RES_RATE_TIER3)+
					((RES_TIER2/GALLON_FEE_UNIT)*RES_RATE_TIER2)+((RES_TIER1/GALLON_FEE_UNIT)*
					RES_RATE_TIER1)+RES_LINE_FEE;
		break;
	
		
		case 2:
			AmountDue=(GallonsUsed/GALLON_COMM_UNIT)*COMM_RATE_TIER1+COMM_LINE_FEE;
		
		break;
	
		case 3:
		
			if (GallonsUsed<=IND_TIER1)
			{
				AmountDue=(GallonsUsed/GALLON_IND_UNIT)*IND_RATE_TIER1+IND_LINE_FEE;
			}
			else
				if(GallonsUsed>IND_TIER1&&GallonsUsed<=IND_TIER3)
				{
					AmountDue=((GallonsUsed-IND_TIER1)/GALLON_IND_UNIT)*IND_RATE_TIER2+(IND_TIER1/GALLON_IND_UNIT)*IND_RATE_TIER1
					+IND_LINE_FEE;
				}
					else
						AmountDue=((GallonsUsed-IND_TIER2)/GALLON_IND_UNIT)*IND_RATE_TIER3+((IND_TIER2/GALLON_IND_UNIT)*
						IND_RATE_TIER2)+((IND_TIER1/GALLON_IND_UNIT)*IND_RATE_TIER1)+IND_LINE_FEE;
					break;				
	}
		
		cout<<endl;
		//output module begins here:
		cout<<"Account Name:\t"<<AccountName<<endl;
		if (AccountNumber<=99999&&AccountNumber>=10000)	
			cout<<"Account Number:\t"<<AccountNumber<<endl;
		else
			if(AccountNumber<=9999&&AccountNumber>=1000)
			cout<<"Account Number:\t 0"<<AccountNumber<<endl;
			else
				if(AccountNumber<=999&&AccountNumber>=100)
				cout<<"Account Number:\t 00"<<AccountNumber<<endl;
				else
					if(AccountNumber<=99&&AccountNumber>=10)
					cout<<"Account Number:\t 000"<<AccountNumber<<endl;
					else
						if(AccountNumber<=9&&AccountNumber>=1)
						cout<<"Account Number:\t 0000"<<AccountNumber<<endl;
					
		cout<<"Account Type:\t"<<AccountType<<endl;
		cout<<"Gallons Used:\t"<<fixed<<showpoint<<setprecision(2)<<GallonsUsed<<endl;
		cout<<"Amount Due:\t"<<fixed<<showpoint<<setprecision(2)<<"$"<<AmountDue<<endl<<endl;
		cout<<"Do you have another account to process? <Y or N>\t"<<endl<<endl<<endl;
		cin>>Another;
		system ("CLS");
		cout<<"press any key when ready to begin next bill"<<endl<<endl;
		system ("pause>nul");
	} while (Another!='N'&&Another!='n');	
		
	return 0; 
	
} // end main

//menuChoice function...	
char menuChoice(char& Choice)
{	
	cout<<"H for residential"<<endl;
	cout<<"C for commercial"<<endl;
	cout<<"I for industrial"<<endl;
	cin>>Choice;
		
	while (Choice!='H'&&Choice!='h'&&Choice!='C'&&Choice!='c'&&Choice!='I'&&Choice!='i')
		{
			cout<<"Incorrect account type selected, please re-enter:\t";
			cin>>Choice;
			return (Choice);
					
		}
		
} // end menuChoice 


