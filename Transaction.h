#pragma once

// Include Statements
#include "Defines.h"

struct Transaction 
{
	Transaction(){ }

	Transaction(int type, double amount)
	{
		m_transactionType	= type;
		m_amount			= amount;		
		m_transactionNumber = transactionNumber();
	}
	
	int transactionNumber()
	{		
		//Not required for this test
		return 1; 
	}
	
	bool Load()
	{
		//load from DB - not required for this test
		return true;
	}

	bool save()
	{
		//Save to DB - not required for this test
		return true;
	}

	int		m_transactionNumber;
	int		m_transactionType;
	double  m_amount;
};