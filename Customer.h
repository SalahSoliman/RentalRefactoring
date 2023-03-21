#pragma once

#include <vector>
#include <string>
#include "Rental.h"

class Customer
{
private:
	std::string name;
	std::vector<Rental *> rentals;

public:
	Customer(std::string name) : name(name)
	{
	}
	~Customer()
	{
		rentals.clear();
	}
	size_t frequentRenterCalculator(Rental *rentalPtr)
	{
		size_t frequentRenterPoints = 1;
		if (rentalPtr->getMovie()->isSpecialRentalFrequentOffer() && rentalPtr->getDaysRented() > 1)
		{
			frequentRenterPoints += rentalPtr->getMovie()->specialRentalFrequentOfferValue;
		}
		return frequentRenterPoints;
	}
	void addRental(Rental *rental)
	{
		rentals.push_back(rental);
	}

	const std::string getName(void) const
	{
		return name;
	}
	char *statement(char *Buffer, int size);
};
