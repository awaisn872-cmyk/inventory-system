#include "TransactionLog.h"

#include <iostream>
using namespace std;

template <class T>
TransactionLog<T>::TransactionLog() {
		count = 0;
	}
template <class T>
	void TransactionLog<T>::recordAction(T item) {
		if (count < 100) {
			logHistory[count++] = item;
		}
	}

	template <class T>
	void TransactionLog<T>::printAuditTrail() {
		cout << "\n===== AUDIT TRAIL =====\n";

		for (int i = 0; i < count; i++) {
			logHistory[i]->Display();
			cout << endl;
		}
	}