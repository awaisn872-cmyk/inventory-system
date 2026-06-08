#ifndef TRANSACTIONLOG_H
#define TRANSACTIONLOG_H


template <class T>
class TransactionLog {
private:
	T logHistory[100];
	int count;

public:

	TransactionLog();

	void recordAction(T );

	void printAuditTrail();

};
#endif