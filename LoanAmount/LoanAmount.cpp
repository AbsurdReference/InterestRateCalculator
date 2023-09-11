/// Program calculates info about a loan based on 3 user input statements 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	//defines variables used in program, normally I would name all of them more specifically and starting with a lowercase, but this is how they
	//were named in the documentation for the project so I kept the names.
	double L, Rate, ratePercent, payments, Amount, totalInterestPaid, N;

	
	//gets the amount the loan was 
	cout << "Please enter the loan amount" << endl;
		cin >> L;

	// gets the annual rate of the loan
	cout << "Please enter the annual rate of the loan" << endl;
	cin >> Rate;

	// converts the annual rate of the loan into the monthly rate of the loan, and because the annual rate isn't used anywhwere in the program
	// it just redefines the original variable the input was stored as to be the monthly rate to be more efficient.
	// also defines rate percent
	Rate = Rate / 12;
	ratePercent = Rate / 100;

	// records number of payments
	cout << "Please enter the Number of Payments" << endl; 
	cin >> N;

	//calculates the cost of each payment, I defined it in 2 seperate lines to increase readability, with the first line being the top half 
	// of the fractional equation defined in the documentation and the second line being the bottom half of that fraction.
	payments = (ratePercent * (pow((ratePercent + 1), N)));
	payments = payments	/ ( pow ((1 + ratePercent), N) - 1) * L;

	Amount = payments * N;
	totalInterestPaid = Amount - L;


	//outputs the information previously calculated in a neat format, and each variable is set to only display a relevant number of decimal places
	// (percentage no decimal places, anything with dollars 2, and integers 0)
	cout << left << setw(22) << "Loan Amount:"  << right << setw(10) << "$ " << fixed << setprecision(2) << L << endl;
	cout << left << setw(22) << "Monthly Interest Rate:" << right << setw(17) << fixed << setprecision(0) << Rate << "%" << endl;
	cout << left << setw(22) << "Number of Payments: " << right << setw(18) << fixed << setprecision(0) << N << endl;
	
	cout << left << setw(22) << "Monthly Payment:" << right << setw(10) << "$ " << right << setw(8) << fixed << setprecision(2) << payments << endl;
	cout << left << setw(22) << "Amount Paid Back:" << right << setw(10) << "$ " << right << setw(8) << fixed << setprecision(2) << Amount << endl;
	cout << left << setw(22) << "Interest Paid:" << right << setw(10) << "$ " << right << setw(8) << fixed << setprecision(2) << totalInterestPaid << endl;
}