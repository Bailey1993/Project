#include "stdafx.h"
#include "BankAccount.h"
#include "Transaction.h"
#include <conio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	//Create a bank account
	BankAccount bankAccount("Lloyds TSB");

	//Create some transactions - We prefer smart pointers where appropriate
	Transaction* t1 = new Transaction(bankRefund,  9.99);
	Transaction* t2 = new Transaction(bankPayment, 20.00);

	//Add them to the bank 
	bankAccount.addTransaction(t1);
	bankAccount.addTransaction(t2);

	//Save to the db
	bankAccount.save();

	//Whats the blance?
	double balance = bankAccount.balance();

	//Output the results
	
	//Use C++ to format and out put the result
	char output[256];

	sprintf_s(output, "Balance %.2f", balance);

	printf(output);

	_getch();

	return 0;
}

