#pragma once

// Include statements
#include "Transaction.h"
#include <cstdint>
#include <cstring>
#include <string>
#include "Defines.h"

struct BankAccount
{
	// Setting variables
	char* m_accountName = nullptr;
	int bankBalance = 0; 
	
	BankAccount(const char* bankName)
	{
		m_numberOfTransactions = 0;

		m_accountName = new char[MAX_NAME];

		strcpy_s(m_accountName, MAX_NAME, bankName );
	}
	
	BankAccount()
	{
		delete m_accountName;
	}

	bool load()
	{
		//load from DB - not required for this test
		return true;
	}

	bool save()
	{
		//Save to DB - not required for this test
		return true;
	}

	void addTransaction(Transaction* t) 
	{
		if( m_numberOfTransactions < MAX_TRANSACTIONS )
		{
			memcpy(&m_transactions[m_numberOfTransactions++], t, sizeof *t);
		}
	}

	void saveAllTransactions( )
	{
		for(int n = 0; n < m_numberOfTransactions; n++ )
		{
			m_transactions[n].save();
			void totalTransaction();
		}
	}
	
	double balance( )
	{
		double b = 0.0;

		for(int n = 0; n < m_numberOfTransactions; n++ )
		{
			if(m_transactions[n].m_transactionType == bankPayment)
			{
				b += m_transactions[n].m_amount;
			}
			else if(m_transactions[n].m_transactionType == bankRefund)
			{
				b -= m_transactions[n].m_amount;
			}
		}

		return b;
	}

	void release()
	{
		//C Style string - bad, there is a memory leak too
		//char* m_accountName = m_accountName;
		delete m_accountName;
	}
	
	//This is bad, we want any number of transactions. Use an appropriate collection. 
	//Transaction m_transactions[MAX_TRANSACTIONS];
	int * m_transactions;
	void totalTransactions(bankBalance)
	{
		for (int n = 0; n < bankBalance; n++)
		{
			bankBalance++;
		}
	}
	
	void release();
	
	int m_numberOfTransactions;
};