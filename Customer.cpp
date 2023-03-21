#include "Customer.h"
char *Customer::statement(char *Buffer, int size)
{
	double totalAmount = 0;
	int curPos = 0;
	int frequentRenterPoints = 0;
	std::vector<Rental *>::iterator rentals_it = rentals.begin();

	curPos = sprintf_s(Buffer, size, "%s %s\n", "Report for", getName());

	while (rentals_it != rentals.end())
	{
		double thisAmount = 0;
		Rental *eachRental = *rentals_it;
		thisAmount = eachRental->getMovie()->getTotalAmount();

		frequentRenterPoints += frequentRenterCalculator();

		curPos += sprintf_s(Buffer + curPos, size - curPos, "\t%s\t%lf\n", eachRental->getMovie()->getTitle(), thisAmount);
		totalAmount += thisAmount;
		rentals_it++;
	}

	curPos += sprintf_s(Buffer + curPos, size - curPos, "The amount owed is %lf\nYou've earned %d activity points", totalAmount,
						frequentRenterPoints);
	return Buffer;
}
